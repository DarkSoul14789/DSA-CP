#include <bits/stdc++.h>
using namespace std;

class DisjointSetUnion {
private:
    vector<int> parents;
    vector<int> ranks;
public:
    DisjointSetUnion(int numberOfSets) {
        this->parents = vector<int>(numberOfSets);
        this->ranks = vector<int>(numberOfSets);
        // every elements starts as its own parent -- and representative
        iota(this->parents.begin(), this->parents.end(), 0);
    }

    int find(int u) {
        // find the root
        int root = u;
        while (this->parents[root] != root) { root = this->parents[root]; }
        // compress paths
        while (this->parents[u] != root) {
            int tmp = this->parents[u];
            this->parents[u] = root;
            u = tmp;
        }
        return root;
    }

    void unite(int u, int v) {
        u = this->find(u);
        v = this->find(v);
        // u and v are already in the same set
        if (u == v) { return; }

        // union by rank -> the root with greater rank becomes the new root
        if (this->ranks[u] == this->ranks[v]) {
            this->parents[u] = v;
            this->ranks[v]++;
        } else if (this->ranks[u] < this->ranks[v]) {
            this->parents[u] = v;
        } else if (this->ranks[u] > this->ranks[v]){
            this->parents[v] = u;
        }
    }
};

typedef vector<vector<pair<int, int>>> AdjacencyList;
typedef tuple<int, int, int> Edge;

pair<int, AdjacencyList> computeMinimumSpanningTree(AdjacencyList adjacencyList) {
    int n = adjacencyList.size();
    vector<Edge> edges;
    // build edge list
    for (int u = 0; u < n; ++u) {
        for (auto [v, w] : adjacencyList[u]) {
            edges.push_back(make_tuple(u, v, w));
        }
    }
    // sort by weight
    sort(
        edges.begin(), 
        edges.end(), 
        [](auto e, auto f){ return get<2>(e) <= get<2>(f); }
    );

    // initialize |V| singleton sets
    auto dsu = DisjointSetUnion(n);
    AdjacencyList tree(n);
    int treeWeight = 0;
    for (auto [u, v, w] : edges) {
        // if u and v are in different connected components
        if (dsu.find(u) != dsu.find(v)) {
            // join the components
            dsu.unite(u, v);
            // add edge to the tree
            treeWeight += w;
            tree[u].push_back(make_pair(v, w));
            tree[v].push_back(make_pair(u, w));
        }
    }

    return make_pair(treeWeight, tree);
};

int main() {
    // set up the adjacency list
    int n = 5;
    vector<Edge> edges {
        make_tuple(0, 1, 7), make_tuple(0, 2, 2), make_tuple(0, 3, 8),
        make_tuple(0, 4, 4), make_tuple(1, 2, 8), make_tuple(1, 3, 3),
        make_tuple(2, 4, 6)
    };
    AdjacencyList adjacencyList(n);
    for (auto [u, v, w] : edges) {
        adjacencyList[u].push_back(make_pair(v, w));
        adjacencyList[v].push_back(make_pair(u, w));
    }

    // run mst computation
    auto [weight, tree] = computeMinimumSpanningTree(adjacencyList);

    // print output
    cout << "Weight of the MST: " << weight << endl;
    cout << "Edges:";
    for (int u = 0; u < n; ++u) {
        for (auto [v, w] : tree[u]) {
            if (u < v) {
                cout << " (" << u << ", " << v << ")";
            }
        }
    }
}

/*
    Runtime complexity is O(|E|log|V|)
*/