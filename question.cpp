#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


vector<vector<int>> adj;
vector<int> values;
vector<unordered_map<int, int>> subtree_freq;
vector<int> parent;
vector<int> subtree_size;
int k;

void dfs(int node, int par) {
    subtree_freq[node][values[node - 1]]++;
    subtree_size[node] = 1;
    for (int neighbor : adj[node]) {
        if (neighbor == par) continue;
        parent[neighbor] = node;
        dfs(neighbor, node);
        subtree_size[node] += subtree_size[neighbor];
        for (const auto& entry : subtree_freq[neighbor]) {
            subtree_freq[node][entry.first] += entry.second;
        }
    }
}

bool is_good_edge(int u, int v) {
    // Ensure u is the parent of v
    if (parent[u] == v) swap(u, v);

    // Calculate frequencies in the "remaining" part of the tree
    unordered_map<int, int> remaining_freq = subtree_freq[1];
    for (const auto& entry : subtree_freq[v]) {
        remaining_freq[entry.first] -= entry.second;
    }

    // Check if any frequency exceeds k in the subtree of v or in the remaining tree
    for (const auto& entry : subtree_freq[v]) {
        if (entry.second > k) return false;
    }
    for (const auto& entry : remaining_freq) {
        if (entry.second > k) return false;
    }
    return true;
}

int count_good_edges(int n, const vector<pair<int, int>>& edges, int k_val, const vector<int>& values_val) {
    k = k_val;
    values = values_val;
    adj.resize(n + 1);
    subtree_freq.resize(n + 1);
    parent.resize(n + 1, -1);
    subtree_size.resize(n + 1, 0);

    for (const auto& edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }

    // Perform DFS from the root (assuming root is node 1)
    dfs(1, -1);

    int good_edges = 0;
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        if (is_good_edge(u, v)) {
            good_edges++;
        }
    }

    return good_edges;
}


int main() {
    int n = 5;
    vector<pair<int, int>> edges = {{1, 2}, {1, 3}, {2, 4}, {3, 5}};
    vector<int> values = {0,1, 1, 1, 2, 1};
    int k = 1;
    
    cout << count_good_edges(n, edges, k, values) << endl; // Example output
    
    return 0;
}
