import React from "react";

interface Props {
  path: string[];
  totalTime: number;
  totalFare: number;
}

export default function JourneySummary({ path, totalTime, totalFare }: Props) {
  return (
    <div className="bg-white shadow-lg rounded-lg p-4 w-96">
      <h2 className="text-xl font-bold text-blue-600 mb-2">Journey Summary</h2>
      <p>Total Time: {totalTime} mins</p>
      <p>Total Fare: ₹{totalFare}</p>
      <div className="mt-4 border-l-2 border-blue-600 pl-4">
        {path.map((station, idx) => (
          <div key={idx} className="mb-2">
            <span className="text-gray-800">{station}</span>
          </div>
        ))}
      </div>
    </div>
  );
}
