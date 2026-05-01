#include "metro.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

DelhiMetro::DelhiMetro(int v) : V(v) {
    adj.resize(v);
}

void DelhiMetro::addStation(int id, string name) {
    stationNames[id] = name;
}

void DelhiMetro::addRoute(int u, int v, int time, int fare) {
    if (u < V && v < V) {
        adj[u].push_back({v, time, fare});
        adj[v].push_back({u, time, fare});
    }
}

void DelhiMetro::displayStations() {
    cout << "\n--- AVAILABLE METRO STATIONS ---\n";
    for (auto const& it : stationNames) {
        cout << "[" << it.first << "] " << it.second << endl;
    }
}

void DelhiMetro::findShortestRoute(int start, int end) {

    if (stationNames.find(start) == stationNames.end() ||
        stationNames.find(end) == stationNames.end()) {
        cout << "\n[Error] Invalid Station ID!" << endl;
        return;
    }

    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<int> fare(V, 0);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &edge : adj[u]) {
            int v = edge.to;

            if (dist[v] > dist[u] + edge.time) {
                dist[v] = dist[u] + edge.time;
                fare[v] = fare[u] + edge.fare;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[end] == INT_MAX) {
        cout << "\nRoute not found!\n";
        return;
    }

    cout << "\n================================\n";
    cout << "      JOURNEY SUMMARY\n";
    cout << "================================\n";
    cout << "TIME: " << dist[end] << " mins\n";
    cout << "FARE: Rs. " << fare[end] << "\n";

    vector<int> path;
    for (int v = end; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    cout << "\nOPTIMAL ROUTE:\n";
    for (int i = 0; i < path.size(); i++) {
        cout << stationNames[path[i]];
        if (i != path.size() - 1) cout << " -> ";
    }

    cout << "\nTotal Stations: " << path.size();
    cout << "\n================================\n";
}