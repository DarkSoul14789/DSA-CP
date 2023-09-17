#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> AdjacencyList;

enum class NodeState{UNVISITED, IN_PROGRESS, FINISHED};

class StronglyConnectedComponents{
  private:
    AdjacencyList adjacencyList;
    vector<NodeState> nodeStates;
    vector<int> finishOrder;
    vector<vector<int>> scc;

  public:
    StronglyConnectedComponents(AdjacencyList &_adjacencyList)
      : adjacencyList {_adjacencyList}
      , nodeStates {vector<NodeState>(adjacencyList.size(), NodeState::UNVISITED)}
    {}

    void transpose(){
      // create new transposed adjacency list
      AdjacencyList tmp = AdjacencyList(this->adjacencyList.size());
      for(int u=0; u<this->adjacencyList.size(); u++){
        for(int v : this->adjacencyList[u]){
          // add reverse edge (v,u)
          tmp[v].push_back(u);
        }
      }
      // replace the adjacency list
      this->adjacencyList = tmp;
    }

    vector<vector<int>> computeScc(){
      for(int u=0; u<this->adjacencyList.size(); u++){
        if(this->nodeStates[u] == NodeState::UNVISITED){
          this->dfs(u);
        }
      }

      // get the reverse finishing order
      vector<int> traverseOrder(finishOrder.rbegin(), finishOrder.rend());

      this->finishOrder.clear();
      fill(this->nodeStates.begin(), this->nodeStates.end(), NodeState::UNVISITED);
      this->transpose();


      for(int u : traverseOrder){
        if(this->nodeStates[u] == NodeState::UNVISITED){
          this->dfs(u);
          // add the newly found SCC
          this->scc.push_back(this->finishOrder);
          // clear the finsh order to make room for the next SCC
          this->finishOrder.clear();
        }
      }

      // cleanup
      this->transpose();
      fill(this->nodeStates.begin(), this->nodeStates.end(), NodeState::UNVISITED);
      return this->scc;
    }

    void dfs(int u){
      this->nodeStates[u] = NodeState::IN_PROGRESS;

      for(int v: this->adjacencyList[u]){
        if(this->nodeStates[v] == NodeState::UNVISITED){
          this->dfs(v);
        }
      }

      this->nodeStates[u] = NodeState::FINISHED;
      this->finishOrder.push_back(u);
    }
};

int main() {
  int n = 7;
  AdjacencyList adjacencyList(n);
  vector<pair<int, int>> edges {{0, 1}, {0, 6}, {1, 4}, {2, 3}, {2, 5}, {3, 2}, {3, 5}, {4, 0}, {4, 5}, {6, 4}};
  for (auto [u, v] : edges) {
    adjacencyList[u].push_back(v);
  }

  StronglyConnectedComponents components(adjacencyList);
  auto scc = components.computeScc();
  cout << "Strongly connected components:" << endl;
  for (auto component : scc) {
    for (int u : component) {
      cout << u << " ";
    }
    cout << endl;
  }
}

/*
  Total runtime complexity is O(|V| + |E|)
*/