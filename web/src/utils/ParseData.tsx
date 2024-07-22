interface Algorithm {
  title: string;
  data: Row[];
  avgWaitingTime?: number;
  avgTurnaroundTime?: number;
  headers?: string[];
}

interface Row {
  [key: string]: string | number;
}

export const ParseData = (text: string): Algorithm[] => {
  const lines = text.trim().split("\n");
  const algorithms: Algorithm[] = [];
  let currentAlgorithm: Algorithm | null = null;
  lines.forEach((line) => {
    if (
      line.startsWith("First Come First Serve") ||
      line.startsWith("Shortest Job First") ||
      line.startsWith("Round Robin") ||
      line.startsWith("Priority Scheduling")
    ) {
      if (currentAlgorithm) {
        algorithms.push(currentAlgorithm);
      }
      currentAlgorithm = { title: line, data: [] };
    } else if (line.includes("Average Waiting Time:")) {
      const avgWaitingTime = parseFloat(line.split(":").pop() || "0");
      if (currentAlgorithm) currentAlgorithm.avgWaitingTime = avgWaitingTime;
    } else if (line.includes("Average Turnaround Time")) {
      const avgTurnaroundTime = parseFloat(line.split(":").pop() || "0");
      if (currentAlgorithm)
        currentAlgorithm.avgTurnaroundTime = avgTurnaroundTime;
    } else if (line.startsWith("Process")) {
      const headers = line
        .split(/\s+/)
        .filter(Boolean)
        .filter((header) => header !== "Time");
      if (currentAlgorithm) currentAlgorithm.headers = headers;
    } else if (line && currentAlgorithm?.headers) {
      const values = line.split(/\s+/).filter(Boolean);
      const row: Row = {};
      currentAlgorithm.headers.forEach((header, index) => {
        row[header] = isNaN(values[index] as any)
          ? values[index]
          : parseFloat(values[index]);
      });
      currentAlgorithm.data.push(row);
    }
  });

  if (currentAlgorithm) {
    algorithms.push(currentAlgorithm);
  }

  return algorithms;
};
