#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> AdjacencyList;
enum class NodeState {UNVISITED, IN_PROGRESS, FINISHED};

class CycleDetector {
private:
    const AdjacencyList adjacencyList;
    vector<NodeState> nodeStates;
    bool cycleFound = false;
public: 
    CycleDetector(AdjacencyList _adjacencyList) 
        : adjacencyList {_adjacencyList} 
        , nodeStates {vector<NodeState>(adjacencyList.size(), NodeState::UNVISITED)}
    {}

    bool containsCycle() {
        for (int u = 0; u < (int)this->adjacencyList.size(); ++u) {
            if (this->nodeStates[u] == NodeState::FINISHED) continue;
            dfs(u);
        }
        return this->cycleFound;
    }

    // For directed graphs
    void dfs(int u) {
        this->nodeStates[u] = NodeState::IN_PROGRESS;

        for (int v : this->adjacencyList[u]) {
            switch (this->nodeStates[v]) {
                case NodeState::UNVISITED: dfs(v); break;
                case NodeState::IN_PROGRESS: this->cycleFound = true; break;
                case NodeState::FINISHED: break;
            }
        }

        this->nodeStates[u] = NodeState::FINISHED;
    }

    // For undirected graphs
    // void dfs(int u, int parent = -1) {
    //     this->nodeStates[u] = NodeState::IN_PROGRESS;

    //     for (int v : this->adjacencyList[u]) {
    //       // skip edge back to the parent
    //       if(v == parent) continue;
    //         switch (this->nodeStates[v]) {
    //             case NodeState::UNVISITED: dfs(v,u); break;
    //             case NodeState::IN_PROGRESS: this->cycleFound = true; break;
    //             case NodeState::FINISHED: break;
    //         }
    //     }

    //     this->nodeStates[u] = NodeState::FINISHED;
    // }
};

int main(){
  int n = 5;
  AdjacencyList adjacencyList(n);
  vector<pair<int,int>> edges {{0,1},{0,2},{1,3},{2,1},{3,0},{4,1}};

  for(auto [u,v]: edges){
    adjacencyList[u].push_back(v);
  }

  CycleDetector cycleDetector(adjacencyList);
  cout << "Contains cycle " << cycleDetector.containsCycle() << endl;
}

// Runtime complexity: O(|E|)