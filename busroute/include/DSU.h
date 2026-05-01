#pragma once
#include <vector>
using namespace std;

class DSU {
    vector<int> parent, rank;

public:
    DSU(int n);
    int find(int x);
    bool unite(int a, int b);
};