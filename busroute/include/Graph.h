#pragma once
#include <vector>
#include <string>
using namespace std;

struct Edge {
    int v;
    int distance;
};

class Graph {
    int n;
    vector<vector<Edge>> adj;

public:
    Graph(int n);
    void addEdge(int u, int v, int d);
    vector<int> shortestPath(int src, int dest);
};