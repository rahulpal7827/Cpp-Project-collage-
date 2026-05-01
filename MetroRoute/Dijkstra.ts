// Dijkstra.ts - Ported from C++
export interface Edge {
  to: string;
  time: number;
  fare: number;
}

export interface Graph {
  [station: string]: Edge[];
}

export function dijkstra(
  graph: Graph,
  source: string,
  destination: string
): { path: string[]; totalTime: number; totalFare: number } {
  const dist: Record<string, number> = {};
  const fare: Record<string, number> = {};
  const prev: Record<string, string | null> = {};
  const visited: Set<string> = new Set();

  for (const station in graph) {
    dist[station] = Infinity;
    fare[station] = Infinity;
    prev[station] = null;
  }

  dist[source] = 0;
  fare[source] = 0;

  while (visited.size < Object.keys(graph).length) {
    let u: string | null = null;
    let minDist = Infinity;

    for (const station in graph) {
      if (!visited.has(station) && dist[station] < minDist) {
        minDist = dist[station];
        u = station;
      }
    }

    if (!u) break;
    visited.add(u);

    for (const edge of graph[u]) {
      const alt = dist[u] + edge.time;
      if (alt < dist[edge.to]) {
        dist[edge.to] = alt;
        fare[edge.to] = fare[u] + edge.fare;
        prev[edge.to] = u;
      }
    }
  }

  const path: string[] = [];
  let u: string | null = destination;
  while (u) {
    path.unshift(u);
    u = prev[u];
  }

  return { path, totalTime: dist[destination], totalFare: fare[destination] };
}
