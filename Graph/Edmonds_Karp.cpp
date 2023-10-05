#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<pair<int, int>>> WeightedAdjacencyList;
typedef vector<vector<int>> Matrix;

class EdmondsKarp {
private:
    // adjacency list with edge capacities as weights
    WeightedAdjacencyList adjacencyList;
    // |V| x |V| matrix of current flow
    Matrix flow;
    // number of nodes
    int n;
    // to represent infinite capacity
    int INFINITI = 1'000'000'000;

    void addMissingEdges() {
        // store set of present edges
        set<pair<int, int>> edges;
        for (int u = 0; u < this->n; ++u) {
            for (auto [v, c] : this->adjacencyList[u]) {
                edges.insert(make_pair(u, v));
            }
        }
        // if an edge does not have a reverse edge, add one with zero capacity
        for (auto [u, v] : edges) {
            if (edges.find(make_pair(v, u)) == edges.end()) {
                this->adjacencyList[v].push_back(make_pair(u, 0));
            }
        }
    }

    int bfs (int s, int t, vector<int> &parents) {
        queue<int> toVisit;
        // store how much flow we can push to each node
        vector<int> canPush(this->n, 0);
        parents[s] = s;
        canPush[s] = INFINITI;
        toVisit.push(s);

        while (!toVisit.empty()) {
            int u = toVisit.front();
            toVisit.pop();
            for (auto [v, c] : this->adjacencyList[u]) {
                int residual = this->getResidual(u, v, c);
                // only process neighbor if it is unvisited and there is residual capacity
                if (parents[v] == -1 && residual > 0) {
                    parents[v] = u;
                    // note how much flow can be pushed to the neighbor
                    canPush[v] = min(canPush[u], residual);
                    // if we found the sink, we can stop the BFS
                    if (v == t) { return canPush[t]; }
                    toVisit.push(v);
                }
            }
        }
        // no s-t path was found
        return 0;
    }

    void pushFlow(int s, int t, int newPush, vector<int> const& parents) {
        int current = t;
        // go backwards along the path from t to s
        while (current != s) {
            int u = parents[current];
            int v = current;
            // check if there is backward flow against the direction of the path
            int backFlow = this->flow[v][u];
            int pushed = 0;
            if (backFlow > 0) {
                // if there is backward flow, prioritize removing it
                int takeBack = min(backFlow, newPush);
                this->flow[v][u] -= takeBack;
                pushed += takeBack;
            }
            // add forward flow in direction of the path
            this->flow[u][v] += (newPush - pushed);

            current = parents[current];
        }
    }

    int augment(int s, int t) {
        vector<int> parents(this->n, -1);
        // find augmenting path
        int newPush = this->bfs(s, t, parents);

        if (newPush == 0) { return 0; }
        // push flow along augmenting path
        this->pushFlow(s, t, newPush, parents);
        return newPush;
    }

    int getResidual(int u, int v, int c) {
        return c - this->flow[u][v] + this->flow[v][u];
    }

public:
    EdmondsKarp(WeightedAdjacencyList const &_adjacencyList) 
        : adjacencyList {_adjacencyList}
        , n {(int) _adjacencyList.size()}
    {
        this->addMissingEdges();
    }

    pair<int, Matrix> computeMaxFlow(int s, int t) {
        // initialize empty flow
        this->flow = Matrix(this->n, vector<int>(this->n, 0));
        int improvement;
        int maxFlow = 0;
        // main loop of Ford-Fulkerson
        do {
            improvement = this->augment(s, t);
            maxFlow += improvement;
        } while (improvement > 0);
        // return value and flow
        return make_pair(maxFlow, this->flow);
    }
};

int main() {
    int n = 7;
    vector<tuple<int, int, int>> edges {
        {0, 1, 5}, {0, 2, 8}, {1, 3, 3},
        {1, 4, 4}, {2, 4, 3}, {2, 5, 4},
        {3, 6, 2}, {4, 6, 4}, {5, 6, 5}
    };
    WeightedAdjacencyList adjacencyList(n);
    for (auto [u, v, c] : edges) {
        adjacencyList[u].push_back(make_pair(v, c));
    }
    EdmondsKarp edmondsKarp(adjacencyList);
    auto [maxFlow, flow] = edmondsKarp.computeMaxFlow(0, 6);
    cout << "maximum flow: " << maxFlow << endl << endl;
    cout << "pushed flow per edge:" << endl;
    for (int u = 0; u < n; ++u) {
        for (auto [v, c] : adjacencyList[u]) {
            cout << u << " -> " << v << " : " << flow[u][v] << "/" << c << endl;
        }
    }
}

/*
  Runtime complexity is O(|V||E|^2)
*/