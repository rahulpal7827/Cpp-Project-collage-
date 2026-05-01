import React from "react";

interface Props {
  stations: string[];
  label: string;
  value: string;
  onChange: (val: string) => void;
}

export default function StationSelector({ stations, label, value, onChange }: Props) {
  return (
    <div className="flex flex-col">
      <label className="text-sm font-medium text-gray-700">{label}</label>
      <input
        list={`${label}-stations`}
        value={value}
        onChange={(e) => onChange(e.target.value)}
        className="border rounded px-2 py-1"
      />
      <datalist id={`${label}-stations`}>
        {stations.map((s) => (
          <option key={s} value={s} />
        ))}
      </datalist>
    </div>
  );
}
