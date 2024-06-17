"use client";
import { useState } from "react";
import classes from "@/styles/page.module.css";
import { ParseData } from "@/utils/ParseData";
import AlgorithmTable from "@/components/AlgorithmTable";
import CustomInputField from "@/components/CustomInputField";

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
  const [dataNum, setDataNum] = useState("");
  const [error, setError] = useState("");

  const handleChangeData = (e: React.ChangeEvent<HTMLInputElement>) => {
    setDataNum(e.target.value);
    if (error != "") setError("");
  };

  const handleCheckCpuTImes = (data: string) => {
    const cpuTimes = data.split(" ");
    if (cpuTimes.length % 3 !== 0) {
      return false;
    }
    for (let i = 0; i < cpuTimes.length; i++) {
      if (isNaN(Number(cpuTimes[i]))) {
        return false;
      }
    }
    return true;
  };

  const handleClick = async () => {
    if (algorithms.length > 0) {
      setAlgorithms([]);
      setDataNum("");
      return;
    }
    if (!handleCheckCpuTImes(dataNum)) {
      setError("Invalid input");
      return;
    }
    try {
      setIsFetching(true);
      const response = await fetch("http://127.0.0.1:5000/run-code", {
        method: "POST",
        headers: {
          "Content-Type": "application/json",
        },
        body: JSON.stringify({ data: dataNum }),
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
      <div className={classes["input"]}>
        {error && <p className={classes["error"]}>*{error}</p>}
        {algorithms.length == 0 && (
          <CustomInputField
            placeholder="Enter CPU Arrival Time , Burst Time and Priority in the format: 0 5 2 1 3 1 2 8 3 3 6 2"
            type="text"
            value={dataNum}
            id="chat-name"
            handleChanges={handleChangeData}
          />
        )}
      </div>
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
          {!isFetching && algorithms.length == 0 && "Run Algorithm"}
          {isFetching && <div className="spin"></div>}
          {algorithms.length > 0 && "Reset Data"}
        </button>
      </div>
    </div>
  );
}
