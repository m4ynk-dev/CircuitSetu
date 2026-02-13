# CircuitSetu

CircuitSetu is a high-performance, open-source circuit simulator that brings professional-grade engineering tools to the browser. By combining a C++ engine (compiled to WebAssembly) with a modern React-based drag-and-drop interface, it allows users to design, simulate, and analyze electrical circuits with lightning speed.

## The Vision

Most web simulators struggle with complex nodal analysis as the component count grows. CircuitSetu offloads the heavy mathematical lifting to a WebAssembly (Wasm) module, allowing for near-instantaneous DC analysis and real-time theorem verification.

Students can use CircuitSetu to solve and verify:

- **Fundamental Laws**: Ohm’s Law, KVL, and KCL
- **Network Theorems**: Thevenin’s & Norton’s equivalent circuits, Superposition, and Maximum Power Transfer
- **Nodal Analysis**: Automatic generation and solving of matrix equations

## Installation

**Prerequisites:**
- Node.js (v18 or higher)
- Emscripten SDK (for compiling the C++ engine)


```
git clone https://github.com/r17e8h/CircuitSetu.git
cd CircuitSetu
npm install
```
**Build the Engine and run**

```
npm run build:wasm
npm run dev
```
## Contribution

Contributions are welcome! Please feel free to submit a Pull Request.

## Licence

This project is licensed under the GNU General Public License v3.0 (GPL-3.0). This ensures that the software remains free and open-source, and any derivative works must also be shared under the same license.