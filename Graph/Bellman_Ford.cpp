#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<pair<int, int>>> AdjacencyList;

class BellmannFord {
private:
  AdjacencyList adjacencyList;
  int INFINITI = 1'000'000'000;
public:
  BellmannFord(AdjacencyList _adjacencyList) 
    : adjacencyList {_adjacencyList}
  {}
  vector<int> computeDistances(int start) {
    int n = this->adjacencyList.size();
    vector<int> distances(n, INFINITI);
    distances[start] = 0;
    // keep track of changes in distances
    bool changed = true;
    // count executions of step (2), run at most (|V| - 1)
    int executions = 0;
    while (changed && executions < n-1) {
      changed = false;
      executions++;
      // try to relax all edges
      for (int u = 0; u < n; ++u) {
        for (auto [v, w]: this->adjacencyList[u]) {
          if (distances[u] + w < distances[v]) {
            distances[v] = distances[u] + w;
            // keep track of the change
            changed = true;
          }
        }
      }
    }
      return distances;
  }
};

/*
Runtime complexity is O(|V||E|)
*/