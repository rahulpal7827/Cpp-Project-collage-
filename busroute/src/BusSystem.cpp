#include "../include/BusSystem.h"
#include <fstream>
#include <iostream>
using namespace std;

BusSystem::BusSystem(int n) : g(n), city(n) {}

void BusSystem::setCity(int idx, string name) {
    city[idx] = name;
}

void BusSystem::addRoute(int u, int v, int d) {
    g.addEdge(u, v, d);
}

void BusSystem::loadRoutes(string file) {
    ifstream fin(file);
    int u, v, d;
    while(fin >> u >> v >> d) {
        addRoute(u, v, d);
    }
}

void BusSystem::findRoute(int src, int dest) {
    vector<int> path = g.shortestPath(src, dest);

    cout << "\n🚍 Route: ";

    for(int i = 0; i < path.size(); i++) {
        cout << city[path[i]];
        if(i != path.size() - 1) cout << " → ";
    }

    cout << endl;
}

void BusSystem::showCities() {
    cout << "\n📍 Cities:\n";
    for(int i = 0; i < city.size(); i++) {
        cout << i << " : " << city[i] << endl;
    }
}

int BusSystem::getCityIndex(string name) {
    for(int i = 0; i < city.size(); i++) {
        if(city[i] == name) return i;
    }
    return -1;
}