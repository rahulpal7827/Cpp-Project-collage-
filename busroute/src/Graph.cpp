#include "../include/Graph.h"
#include <queue>
#include <limits>
#include <algorithm>
using namespace std;

Graph::Graph(int n) {
    this->n = n;
    adj.resize(n);
}

void Graph::addEdge(int u, int v, int d) {
    adj[u].push_back({v, d});
    adj[v].push_back({u, d});
}

vector<int> Graph::shortestPath(int src, int dest) {
    vector<int> dist(n, 1e9), parent(n, -1);
    dist[src] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0, src));

    while(!pq.empty()) {

        pair<int,int> top = pq.top();
        int d = top.first;
        int u = top.second;
        pq.pop();

        for(auto &e : adj[u]) {
            if(dist[e.v] > d + e.distance) {
                dist[e.v] = d + e.distance;
                parent[e.v] = u;
                pq.push(make_pair(dist[e.v], e.v));
            }
        }
    }

    vector<int> path;
    for(int v = dest; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());
    return path;
}