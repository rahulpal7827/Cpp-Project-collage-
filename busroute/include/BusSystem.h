#pragma once
#include "Graph.h"
#include <vector>
#include <string>
using namespace std;

class BusSystem {
    Graph g;
    vector<string> city;

public:
    BusSystem(int n);

    void setCity(int idx, string name);

    void addRoute(int u, int v, int d);

    void loadRoutes(string file);

    void findRoute(int src, int dest);

    void showCities();

    int getCityIndex(string name);
};