import React, { useState } from "react";
import { Graph } from "./Dijkstra";

interface Props {
  graph: Graph;
  setGraph: React.Dispatch<React.SetStateAction<Graph>>;
}

export default function AdminPanel({ graph, setGraph }: Props) {
  const [station, setStation] = useState("");
  const [to, setTo] = useState("");
  const [time, setTime] = useState(0);
  const [fare, setFare] = useState(0);

  const addRoute = () => {
    setGraph((prev) => {
      const newGraph = { ...prev };
      if (!newGraph[station]) newGraph[station] = [];
      newGraph[station].push({ to, time, fare });
      return newGraph;
    });
  };

  return (
    <div className="mt-6 bg-gray-100 p-4 rounded-lg w-full">
      <h2 className="text-lg font-bold text-yellow-600 mb-2">Developer Mode</h2>
      <div className="flex gap-2">
        <input
          placeholder="Station"
          value={station}
          onChange={(e) => setStation(e.target.value)}
          className="border px-2 py-1 rounded"
        />
        <input
          placeholder="To"
          value={to}
          onChange={(e) => setTo(e.target.value)}
          className="border px-2 py-1 rounded"
