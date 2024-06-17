import React from "react";
import classes from "@/styles/AlgorithmTable.module.css";
type AlgorithmTableProps = {
  title: string;
  data: any;
  avgWaitingTime: number;
  avgTurnaroundTime: number;
  headers: string[];
};

const AlgorithmTable: React.FC<AlgorithmTableProps> = ({
  title,
  data,
  avgWaitingTime,
  avgTurnaroundTime,
  headers,
}) => {
  return (
    <div className={classes["container"]}>
      <h2>{title}</h2>
      <table>
        <thead>
          <tr>
            {headers.map((heading, index) => (
              <th key={index}>{heading}</th>
            ))}
          </tr>
        </thead>
        <tbody>
          {data.map((row: any, rowIndex: number) => (
            <tr key={rowIndex}>
              {headers.map((header, cellIndex) => (
                <td key={cellIndex}>
                  <span>{row[header]}</span>
                </td>
              ))}
            </tr>
          ))}
        </tbody>
      </table>
      <p>
        <strong>Average Waiting Time:</strong> <span>{avgWaitingTime}</span>
      </p>
      <p>
        <strong>Average Turnaround Time:</strong>{" "}
        <span>{avgTurnaroundTime}</span>
      </p>
    </div>
  );
};

export default AlgorithmTable;
