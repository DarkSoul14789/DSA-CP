#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> AdjacencyList;

enum class NodeState{UNVISITED, IN_PROGRESS, FINISHED};

class GraphIsCyclicException: public runtime_error{
  public:
    GraphIsCyclicException() : runtime_error("The graph contains a cycle.") {}
};

class TopologicalSort{
  private:
    const AdjacencyList adjacencyList;
    vector<NodeState> nodeStates;
    vector<int> finishOrder;


  public:
    TopologicalSort(AdjacencyList &_adjacencyList)
      : adjacencyList {_adjacencyList}
      , nodeStates {vector<NodeState>(adjacencyList.size(), NodeState::UNVISITED)}
    {}

    vector<int> computeTopologicalSort(){
      for(int u = 0; u < (int)this->adjacencyList.size(); u++){
        if(this->nodeStates[u] == NodeState::FINISHED) continue;
        dfs(u);
      }
      reverse(this->finishOrder.begin(),this->finishOrder.end());
      return this->finishOrder;
    }

    void dfs(int u){
      this->nodeStates[u] = NodeState::IN_PROGRESS;

      for(int v: this->adjacencyList[u]){
        switch (this->nodeStates[v]){
          case NodeState::UNVISITED: dfs(v); break;
          case NodeState::IN_PROGRESS: throw GraphIsCyclicException(); break;
          case NodeState::FINISHED: break;
        }
      }

      this->nodeStates[u] = NodeState::FINISHED;
      this->finishOrder.push_back(u);
    }
};

int main() {
  int n = 5;
  AdjacencyList adjacencyList(n);
  vector<pair<int, int>> edges {{0, 1}, {0, 4}, {2, 4}, {2, 1}, {3, 0}, {4, 1}};
  for (auto [u, v] : edges) {
    adjacencyList[u].push_back(v);
  }

  TopologicalSort topologicalSort(adjacencyList);
  try
  {
    vector<int> topSort = topologicalSort.computeTopologicalSort();
    cout << "Topological sort:";
    for (int u : topSort) {
      cout << " " << u;
    }
  }
  catch(GraphIsCyclicException exc)
  {
    cout << exc.what() << '\n';
  }
  
  
}

/*
  Runtime complexity is O(|V| + |E|)
*/