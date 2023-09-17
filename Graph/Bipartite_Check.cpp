// solution using DFS
#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> AdjacencyList;
enum class NodeState {UNVISITED, RED, BLUE};

class BipartiteCheck {
private:
  AdjacencyList adjacencyList;
  vector<NodeState> states;
public:
  BipartiteCheck(AdjacencyList _adjacencyList) 
    : adjacencyList {_adjacencyList}
    , states(_adjacencyList.size(), NodeState::UNVISITED)
  {}
  bool isBipartite() {
    // color the nodes
    for (int u = 0; u < this->adjacencyList.size(); ++u) {
      if (this->states[u] == NodeState::UNVISITED) {
        dfs(u, true);
      }
    }

    // check for invalid edges between nodes of the same color
    for (int u = 0; u < this->adjacencyList.size(); ++u) {
      for (int v : this->adjacencyList[u]) {
        if (this->states[u] == this->states[v]) {
            return false;
        }
      }
    }
    // no invalid edge found, graph is bipartite
    return true;
  }

  // dfs from node u and assign a color using the second argument
  void dfs(int u, bool red) {
    // color the node
    this->states[u] = red ? NodeState::RED : NodeState::BLUE;

    // check neighbors and color them in the other color
    for (int v : this->adjacencyList[u]) {
      if (this->states[v] == NodeState::UNVISITED) {
        dfs(v, !red);
      }
    }
  }
};

/*

#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> AdjacencyList;

class BipartiteCheck {
private:
  AdjacencyList adjacencyList;
  vector<int> nodeStates;
  bool canColor = true;
public:
  BipartiteCheck(AdjacencyList _adjacencyList) 
    : adjacencyList {_adjacencyList}
    , nodeStates {vector<int>(adjacencyList.size(), -1)}
  {}
  void dfs(int u, bool red){
    if(red){
      nodeStates[u] = 1;
    }else{
      nodeStates[u] = 0;
    }
    for(int v : adjacencyList[u]){
      if(nodeStates[v] == -1){
        this->dfs(v, !red);
      }
      else if(nodeStates[v] == red){
        this->canColor = false;
      }
    }
  }
  bool isBipartite() {
    // TODO modify the code below
    for(int u = 0; u<adjacencyList.size(); u++){
      if(nodeStates[u] == -1){
        this->dfs(u,1);
      }
    }
    return this->canColor;
  }
};

*/