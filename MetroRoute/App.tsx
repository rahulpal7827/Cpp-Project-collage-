import React, { useState } from "react";
import StationSelector from "./StationSelector";
import JourneySummary from "./JourneySummary";
import MetroGraph from "./MetroGraph";
import AdminPanel from "./AdminPanel";
import { dijkstra, Graph } from "./Dijkstra";

const initialGraph: Graph = {
  "Rajiv Chowk": [
    { to: "Kashmere Gate", time: 10, fare: 20 },
    { to: "Central Secretariat", time: 5, fare: 15 },
  ],
  "Kashmere Gate": [{ to: "Rajiv Chowk", time: 10, fare: 20 }],
  "Central Secretariat": [{ to: "Rajiv Chowk", time: 5, fare: 15 }],
};

export default function App() {
  const [graph, setGraph] = useState<Graph>(initialGraph);
  const [source, setSource] = useState("");
  const [destination, setDestination] = useState("");
  const [result, setResult] = useState<{
    path: string[];
    totalTime: number;
    totalFare: number;
  } | null>(null);

  const handleFindRoute = () => {
    if (source && destination) {
      const res = dijkstra(graph, source, destination);
      setResult(res);
    }
  };

  return (
    <div className="min-h-screen bg-blue-50 flex flex-col items-center p-6">
      <h1 className="text-3xl font-bold text-red-600 mb-6">
        Delhi Metro Route Finder
      </h1>

      <div className="flex gap-4 mb-6">
        <StationSelector
          stations={Object.keys(graph)}
          label="Source"
          value={source}
          onChange={setSource}
        />
        <StationSelector
          stations={Object.keys(graph)}
          label="Destination"
          value={destination}
          onChange={setDestination}
        />
        <button
          onClick={handleFindRoute}
          className="bg-yellow-400 text-black px-4 py-2 rounded-lg font-semibold hover:bg-yellow-500"
        >
          Find Route
        </button>
      </div>

      {result && (
        <JourneySummary
          path={result.path}
          totalTime={result.totalTime}
          totalFare={result.totalFare}
        />
      )}

      <MetroGraph graph={graph} />

      <AdminPanel graph={graph} setGraph={setGraph} />
    </div>
  );
}
