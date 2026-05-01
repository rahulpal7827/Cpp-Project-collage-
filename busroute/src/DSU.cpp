#include "../include/DSU.h"

DSU::DSU(int n) {
    parent.resize(n);
    rank.resize(n, 0);
    for(int i = 0; i < n; i++) parent[i] = i;
}

int DSU::find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

bool DSU::unite(int a, int b) {
    a = find(a);
    b = find(b);

    if(a == b) return false;

    if(rank[a] < rank[b]) swap(a, b);
    parent[b] = a;

    if(rank[a] == rank[b]) rank[a]++;
    return true;
}