#include "../include/solver.hpp"
#include "../include/json.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

using json = nlohmann::json;

CircuitSolver::CircuitSolver() {}

void CircuitSolver::addComponent(std::unique_ptr<Component> comp) {
  if (comp) {
    components.push_back(std::move(comp));
  }
}

std::string CircuitSolver::simulate(const std::string &jsonData) {
  try {
    auto data = json::parse(jsonData);
    components.clear();
    int maxNode = 0;
    if (data.contains("components") && data["components"].is_array()) {
      for (const auto &item : data["components"]) {
        int nA = item.value("nodeA", 0);
        int nB = item.value("nodeB", 0);
        maxNode = std::max({maxNode, nA, nB});
      }
    }
    int matrixSize = maxNode + 1;
    std::vector<std::vector<double>> A(matrixSize,
                                       std::vector<double>(matrixSize, 0.0));
    std::vector<double> z(matrixSize, 0.0);

    /*
    this space is for math work. we'll be looping thru the components ans stamp
    them into A and z. then solve the linear system A*x = z
    */

    json response;
    response["status"] = "success";
    response["message"] = "Circuit passed successfully!";
    response["matrix_size"] = matrixSize;

    return response.dump();
  } catch (const json::parse_error &e) {
    return "{\"status\": \"error\", \"message\": \"JSON Parse Error: " +
           std::string(e.what()) + "\"}";
  } catch (const std::exception &e) {
    return "{\"status\": \"error\", \"message\": \"Engine Error: " +
           std::string(e.what()) + "\"}";
  }
}