#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> AdjacencyMatrix;

class NoPathExistsException : public runtime_error
{
public:
  NoPathExistsException() : runtime_error("No path exists between the nodes.") {}
};

class FloydWarshall
{
private:
  AdjacencyMatrix distanceMatrix;
  AdjacencyMatrix predecessorMatrix;
  // static constexpr int UNKNOWN = -1;
  // static constexpr int INFINITI = 1'000'000'000;

  void initialize(AdjacencyMatrix const &adjacencyMatrix)
  {
    int n = adjacencyMatrix.size();
    // default values: infinite distance, no predecessor
    this->distanceMatrix = AdjacencyMatrix(n, vector<int>(n, 1'000'000'000));
    this->predecessorMatrix = AdjacencyMatrix(n, vector<int>(n, -1));
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        // fill main diagonal
        if (i == j)
        {
          this->distanceMatrix[i][j] = 0;
          this->predecessorMatrix[i][j] = i;
        }
        // fill distances and predecessors for edges
        else if (adjacencyMatrix[i][j] > 0)
        {
          this->distanceMatrix[i][j] = adjacencyMatrix[i][j];
          this->predecessorMatrix[i][j] = i;
        }
      }
    }
  }

  void compute()
  {
    int n = this->distanceMatrix.size();
    // run n = |V| operations
    for (int k = 0; k < n; ++k)
    {
      // update each entry
      for (int i = 0; i < n; ++i)
      {
        for (int j = 0; j < n; ++j)
        {
          if (this->distanceMatrix[i][k] + this->distanceMatrix[k][j] < this->distanceMatrix[i][j])
          {
            this->distanceMatrix[i][j] = this->distanceMatrix[i][k] + this->distanceMatrix[k][j];
            this->predecessorMatrix[i][j] = this->predecessorMatrix[k][j];
          }
        }
      }
    }
  }

public:
  FloydWarshall(AdjacencyMatrix const &adjacencyMatrix)
  {
    this->initialize(adjacencyMatrix);
    this->compute();
  }

  // return length of shortest path as well as the path itself
  pair<int, vector<int>> getShortestPath(int start, int end)
  {
    int distance = this->distanceMatrix[start][end];
    if (distance == 1'000'000'000)
    {
      throw NoPathExistsException();
    }

    vector<int> path{end};
    int current = end;
    while (current != start)
    {
      current = this->predecessorMatrix[start][current];
      path.push_back(current);
    }
    std::reverse(path.begin(), path.end());
    return make_pair(distance, path);
  }
};

int main() {
  int n = 4;
  AdjacencyMatrix adjacencyMatrix(n, vector<int>(n, 0));
  vector<tuple<int, int, int>> edges {
    make_tuple(0, 1, 6), 
    make_tuple(0, 2, 3), 
    make_tuple(0, 3, 12), 
    make_tuple(1, 2, 9), 
    make_tuple(1, 3, 5), 
    make_tuple(2, 3, 2),
    make_tuple(3, 1, 4),
    make_tuple(3, 2, 1)
  };
  for (auto [v, u, w] : edges) {
    adjacencyMatrix[v][u] = w;
  }

  FloydWarshall floydWarshall(adjacencyMatrix);
  auto [distance, path] = floydWarshall.getShortestPath(0, 3);
  cout << "Shortest path from 0 to 3:";
  for (int u : path) {
    cout << " " << u;
  }
  cout << endl << "Length of the path: " << distance << endl;
  
  try {
    floydWarshall.getShortestPath(2, 0);
  } catch (NoPathExistsException exc) {
    cout << "No path from 2 to 0.";
  }  
}

/*
Runtime complexity is O(|V|^3).
In dense graphs where |E| = O(|V|^2), the Dijkstra runtime ends up to be O(|V|^3 log|V|), using Floyd-Warshall is preferable.

However, in sparse graphs where ∣E∣ = O(∣V∣), repeated Dijkstra runs end up with a O(|V|^2 log|V|) complexity, Dijkstra generally outperforms Floyd-Warshall.
*/