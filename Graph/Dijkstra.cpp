#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> NodeAndDistance;
typedef vector<vector<NodeAndDistance>> AdjacencyList;

class NoPathExistsException: public runtime_error {
public:
  NoPathExistsException() : runtime_error("No path exists between the nodes.") {}
};

class Dijkstra {
private:
  AdjacencyList adjacencyList;
  vector<int> distances;
  vector<int> parents;
  // static constexpr int UNKNOWN = -1;

  void runDijkstra(int start) {
    // swaps p1 with p2 when returned true. Hence, node with the smallest distance will  be given the highest priority
    auto comparator = [](NodeAndDistance p1, NodeAndDistance p2) {
      return p1.second > p2.second || (p1.second == p2.second && p1.first > p2.first);
    };
    priority_queue<NodeAndDistance, vector<NodeAndDistance>, decltype(comparator)> distanceQueue(comparator);
    vector<bool> visited(this->adjacencyList.size(), false);

    // handle the starting node
    distanceQueue.push(make_pair(start, 0));
    parents[start] = start;
    distances[start] = 0;

    while (!distanceQueue.empty()) {
      // get the closest node from the queue
      auto [u, distance] = distanceQueue.top();
      distanceQueue.pop();
      // do not visit a node more than once
      if (visited[u]) continue;
      visited[u] = true;

      for (auto [v, weight] : this->adjacencyList[u]) {
        // relax the edge (u, v)
        if (distances[v] == -1 || distances[u] + weight < distances[v]) {
          distances[v] = distances[u] + weight;
          parents[v] = u;
          distanceQueue.push(make_pair(v, distances[v]));
        }
      }
    }
  }
public:
  Dijkstra(AdjacencyList &_adjacencyList) 
    : adjacencyList {_adjacencyList}  
    , distances {vector<int>(_adjacencyList.size(), -1)}
    , parents {vector<int>(_adjacencyList.size(), -1)}
  {}

  pair<int, vector<int>> computeShortestPath(int start, int end) {
    this->runDijkstra(start);
    if (this->parents[end] == -1) {
      throw NoPathExistsException();
    }

    int distance = this->distances[end];

    // reconstruct the path from parents
    vector<int> path;
    path.push_back(end);
    int current = end;
    while (current != start) {
      current = parents[current];
      path.push_back(current);
    }

    std::reverse(path.begin(), path.end());
    return make_pair(distance, path);
  }
};

int main() {
  int n = 5;
  AdjacencyList adjacencyList(n);
  vector<tuple<int, int, int>> edges {
    make_tuple(0, 1, 6),
    make_tuple(0, 2, 10),
    make_tuple(0, 3, 4),
    make_tuple(1, 0, 2),
    make_tuple(1, 2, 3),
    make_tuple(1, 4, 5),
    make_tuple(3, 1, 1),
    make_tuple(3, 4, 2),
    make_tuple(4, 2, 1)
  };
  for (auto [u, v, w] : edges) {
    adjacencyList[u].push_back(make_pair(v, w));
  }

  Dijkstra dijkstra(adjacencyList);
  auto [distance, path02] = dijkstra.computeShortestPath(0, 2);
  cout << "Shortest path from 0 to 2: ";
  for (int u : path02) {
    cout << u << " ";
  }
  cout << endl << "Length of the path: " << distance;
}

/*
Runtime complexity is O(|E|log|V|)
*/