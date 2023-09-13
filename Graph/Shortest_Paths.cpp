#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> AdjacencyList;

class NoPathExistsException: public runtime_error {
public:
  NoPathExistsException() : runtime_error("No path exists between the nodes.") {}
};

class ShortestPaths {
private:
  AdjacencyList adjacencyList;
  vector<int> distances;
  vector<int> parents;
  // static constexpr int UNKNOWN = -1;

  void bfs(int start) {
    this->distances.assign(this->distances.size(), -1);
    this->parents.assign(this->parents.size(), -1);
    queue<int> unexplored;
    unexplored.push(start);
    distances[start] = 0;
    parents[start] = start;

    while (!unexplored.empty()) {
      int u = unexplored.front();
      unexplored.pop();
      for (int v : this->adjacencyList[u]) {
        if (this->parents[v] == -1) {
          parents[v] = u;
          distances[v] = distances[u] + 1;
          unexplored.push(v);
        }
      }
    }
  }
public:
  ShortestPaths(AdjacencyList &_adjacencyList) 
    : adjacencyList {_adjacencyList}  
    , distances {vector<int>(_adjacencyList.size(), -1)}
    , parents {vector<int>(_adjacencyList.size(), -1)}
  {}

  vector<int> computeShortestPath(int start, int end) {
    this->bfs(start);
    if (this->parents[end] == -1) {
      throw NoPathExistsException();
    }

    vector<int> path;
    path.push_back(end);
    int current = end;
    while (current != start) {
      current = parents[current];
      path.push_back(current);
    }

    std::reverse(path.begin(), path.end());
    return path;
  }

};

int main() {
  int n = 6;
  AdjacencyList adjacencyList(n);
  vector<pair<int, int>> edges {{0, 1}, {0, 2}, {1, 3}, {2, 4}, {3, 0}, {3, 4}, {4, 3}, {4, 5}};
  for (auto [u, v] : edges) {
    adjacencyList[u].push_back(v);
  }

  ShortestPaths shortestPaths(adjacencyList);
  vector<int> path04 = shortestPaths.computeShortestPath(0, 4);
  cout << "Shortest path from 0 to 4: "<<endl;
  for (int u : path04) {
    cout << u << " ";
  }
  cout<<endl;
  try {
    vector<int> path50 = shortestPaths.computeShortestPath(5, 0);
  } catch (NoPathExistsException exc) {
    cout << exc.what();
  }
}

/*
  Performing a BFS from one node takes O(|E|) time, and running BFS from all nodes takes O(|V| + |E|). Hence, the shortest path computation from one starting node has complexity O(|E|).
*/