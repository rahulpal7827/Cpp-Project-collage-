import React from "react";
import { Graph } from "./Dijkstra";

interface Props {
  graph: Graph;
}

export default function MetroGraph({ graph }: Props) {
  return (
    <div className="mt-6 p-4 bg-white rounded shadow w-full">
      <h2 className="text-lg font-bold text-red-500 mb-2">Metro Network</h2>
      <svg width="600" height="400">
        {Object.keys(graph).map((station, i) =>
          graph[station].map((edge, j) => (
            <line
              key={`${station}-${j}`}
              x1={50 + i * 100}
              y1={50}
              x2={50 + (i + 1) * 100}
              y2={150}
              stroke="blue"
              strokeWidth="2"
            />
          ))
        )}
      </svg>
    </div>
  );
}
