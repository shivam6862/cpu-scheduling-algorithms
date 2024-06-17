"use client";
import { useState } from "react";
import classes from "@/styles/page.module.css";
import { ParseData } from "@/utils/ParseData";
import AlgorithmTable from "@/components/AlgorithmTable";

interface AlgoData {
  title: string;
  data: Row[];
  avgWaitingTime: number;
  avgTurnaroundTime: number;
  headers: string[];
}
interface Row {
  [key: string]: string | number;
}

export default function Home() {
  const [algorithms, setAlgorithms] = useState([] as AlgoData[]);
  const [isFetching, setIsFetching] = useState(false);

  const handleClick = async () => {
    try {
      setIsFetching(true);
      const response = await fetch("http://127.0.0.1:5000/run-code", {
        method: "GET",
        headers: {
          "Content-Type": "application/json",
        },
      });
      const data = await response.json();
      const algoData = ParseData(data.output);
      setAlgorithms(algoData as AlgoData[]);
      setIsFetching(false);
    } catch (error) {
      console.error(error);
      setAlgorithms([]);
      setIsFetching(false);
    }
  };

  return (
    <div className={classes["container"]}>
      <h1>Scheduling Algorithms</h1>
      <div className={classes["box"]}>
        {algorithms.map((algo, index) => (
          <AlgorithmTable
            key={index}
            title={algo.title}
            data={algo.data}
            avgWaitingTime={algo.avgWaitingTime}
            avgTurnaroundTime={algo.avgTurnaroundTime}
            headers={algo.headers}
          />
        ))}
        <button className={classes["button"]} onClick={handleClick}>
          {!isFetching && "Run Code"}
          {isFetching && <div className="spin"></div>}
        </button>
      </div>
    </div>
  );
}
