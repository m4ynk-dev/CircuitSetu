import { create } from 'zustand';

function generateEnginePayload(reactNodes, reactEdges) {
  const engineComponents = [];
  const edgeToNodeId = {};
  let nextNodeId = 1;

  reactEdges.forEach(edge => {
    if (edge.source === 'ground' || edge.target === 'ground') {
      edgeToNodeId[edge.id] = 0;
    } else {
      edgeToNodeId[edge.id] = nextNodeId++;
    }
  });

  reactNodes.forEach(node => {
    if (node.type === 'ground' || node.type === 'wire') return;
    
    const wireA = reactEdges.find(e => e.source === node.id);
    const wireB = reactEdges.find(e => e.target === node.id);

    if (!wireA || !wireB) return;

    engineComponents.push({
      type: node.type, 
      value: parseFloat(node.data?.value || 0), 
      nodeA: edgeToNodeId[wireA.id],
      nodeB: edgeToNodeId[wireB.id]
    });
  });

  return { components: engineComponents };
}

const useCircuitStore = create((set, get) => ({
  nodes: [],
  edges: [],
  results: {},

  setNodes: (nodes) => set({ nodes }),
  setEdges: (edges) => set({ edges }),

  updateNodeValue: (id, newValue) => set((state) => ({
    nodes: state.nodes.map(node => 
      node.id === id ? { ...node, data: { ...node.data, value: newValue } } : node
    )
  })),

  setResults: (data) => set({ results: data }),

  getEnginePayload: () => {
    const { nodes, edges } = get();
    
    return JSON.stringify(generateEnginePayload(nodes, edges));
  }
}));

export default useCircuitStore;