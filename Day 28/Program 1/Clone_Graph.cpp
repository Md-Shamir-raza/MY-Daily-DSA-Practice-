#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
    unordered_map<Node*, Node*> visited;
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        
        // If the node was already visited, return the cloned node from the map
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }
        
        // Clone the current node
        Node* cloneNode = new Node(node->val);
        // Save the cloned node in the visited map
        visited[node] = cloneNode;
        
        // Iterate through the neighbors to recursively clone them
        for (Node* neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }
        
        return cloneNode;
    }
};

int main() {
    // Setup a simple connected graph: 1 -- 2
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    node1->neighbors.push_back(node2);
    node2->neighbors.push_back(node1);
    
    Solution solution;
    Node* clonedGraph = solution.cloneGraph(node1);
    
    cout << "Original Node 1 Value: " << node1->val << ", Neighbor: " << node1->neighbors[0]->val << endl;
    cout << "Cloned Node 1 Value: " << clonedGraph->val << ", Neighbor: " << clonedGraph->neighbors[0]->val << endl;
    
    // Check if they are actually different objects in memory
    cout << "Is cloned node 1 the same object in memory? " << (node1 == clonedGraph ? "Yes" : "No") << endl;
    
    return 0;
}
