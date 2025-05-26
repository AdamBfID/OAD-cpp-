# Local Search Knapsack Solver

## Overview
This project implements a **Local Search** algorithm to solve the **0/1 Knapsack Problem**. The 0/1 Knapsack Problem is a combinatorial optimization problem where, given a set of items with associated weights and gains, the goal is to select a subset of items that maximizes the total gain while ensuring the total weight does not exceed a given capacity.

The Local Search algorithm is a simple heuristic that iteratively explores neighboring solutions and selects the best feasible neighbor until no better solution is found. The code is written in **C++** and uses the standard library (`bits/stdc++.h` and `chrono`) for vector operations and time measurement.

## Features
- **Initial Solution**: Starts with a user-defined initial solution (default: all items unselected).
- **Neighbor Generation**: Generates neighbors by flipping one bit at a time in the current solution.
- **Feasibility Check**: Ensures solutions respect the knapsack's weight capacity.
- **Best Neighbor Selection**: Chooses the best feasible neighbor based on gain.
- **Progress Tracking**: Outputs the current solution and gain at each iteration.
- **Performance Measurement**: Tracks and reports the execution time in seconds.
- **Simple Termination**: Stops when no better neighbor is found.

## Prerequisites
To compile and run this code, you need:
- A C++ compiler supporting C++11 or later (e.g., `g++`, `clang++`).
- Standard C++ libraries (included via `<bits/stdc++.h>` and `<chrono>`).

No external dependencies are required beyond the C++ Standard Library.

## Installation
1. **Save the Code**: Copy the provided C++ code into a file named `knapsack_local.cpp`.
2. **Compile the Code**:
   ```bash
   g++ -std=c++11 knapsack_local.cpp -o knapsack_local
   ```
   Ensure you have a C++11-compliant compiler. Replace `g++` with your preferred compiler if necessary.
3. **Run the Program**:
   ```bash
   ./knapsack_local
   ```

## Usage
The program is configured with a sample knapsack problem in the `main` function. The input data consists of:
- **Gains**: A vector of integers representing the value of each item.
- **Weights**: A vector of integers representing the weight of each item.
- **Max Weight**: The knapsack's capacity (maximum allowable total weight).
- **Initial Solution**: A binary vector indicating which items are initially selected (default: all zeros).

### Example Input (Defined in `main`)
```cpp
vector<vector<int>> TC = {
    // Gains
    {91, 72, 90, 46, 55, 8, 35, 75, 61, 15, 77, 40, 63, 75, 29, 75, 17, 78, 40, 44},
    // Weights
    {84, 83, 43, 4, 44, 6, 82, 92, 25, 83, 56, 18, 58, 14, 48, 70, 96, 32, 68, 92}
};
int maxWeight = 879;
```

### Running the Program
1. The program initializes with the provided data and runs the Local Search algorithm.
2. It outputs the current solution and gain at each iteration until no better neighbor is found.
3. The final output includes the best solution found, its total gain, total weight, and execution time.

### Sample Output
```
Best Solution Found: 1 1 1 1 1 1 0 1 1 0 1 1 1 1 1 1 0 1 1 0
Total Gain: 802
Total Weight: 658
Execution Time: 0.002 seconds
```

## Code Structure
The code is organized in a single C++ file with several functions to implement the Local Search algorithm. Key components include:

### Functions
- `printVector`: Prints a vector (used for solutions).
- `printMatrix`: Prints a matrix (used for debugging input data).
- `calculateGain`: Computes the total gain of a solution based on the gain vector.
- `calculateWeight`: Computes the total weight of a solution based on the weight vector.
- `generateNeighbors`: Generates all possible neighbors by flipping one bit at a time.
- `findBestNeighbor`: Selects the best feasible neighbor based on gain.
- `localSearch`: Implements the main Local Search algorithm, iterating through neighbors until no better solution is found.
- `main`: Defines sample problem data, runs the algorithm, measures execution time, and prints results.

## Algorithm Parameters
The Local Search algorithm uses the following parameters:
- **Max Weight**: `879` — The knapsack's capacity, defined in `main`.
- **Initial Solution**: A vector of zeros (no items selected initially), defined in `main`.
- **Termination Condition**: Stops when no better neighbor is found.

## Customization
To use the solver with different data:
1. Modify the `TC` matrix, `maxWeight`, and `initialSolution` in the `main` function.
2. Ensure `TC` has two rows: `TC[0]` for gains and `TC[1]` for weights, with equal lengths.
3. Ensure `initialSolution` is a binary vector of the same length as the gains/weights.
4. The algorithm does not require iteration limits, as it stops when no better neighbor is found.

## Limitations
- The algorithm may get stuck in a local optimum, as Local Search is a simple hill-climbing heuristic.
- The neighbor generation strategy (flipping one bit) may be less effective for large problems.
- The initial solution must be feasible; no validation is performed.
- The algorithm does not explore worse solutions, limiting its ability to escape local optima.

## Future Improvements
- Add validation for the initial solution's feasibility.
- Implement alternative neighbor generation strategies (e.g., flipping multiple bits).
- Add a maximum iteration limit to prevent excessive runtime for large problems.
- Support saving results to a file.
- Integrate with other heuristics (e.g., Simulated Annealing or Tabu Search) for better exploration.

## License
This project is provided as-is for educational purposes. Feel free to modify and use it as needed.
