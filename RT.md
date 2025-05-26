# Tabu Search Knapsack Solver

## Overview
This project implements a **Tabu Search** algorithm to solve the **0/1 Knapsack Problem**. The 0/1 Knapsack Problem is a combinatorial optimization problem where, given a set of items with associated weights and gains, the goal is to select a subset of items that maximizes the total gain while ensuring the total weight does not exceed a given capacity.

The Tabu Search algorithm is a metaheuristic that enhances local search by maintaining a short-term memory (tabu list) to avoid revisiting recently explored solutions, thus preventing cycling and encouraging exploration of new areas in the solution space. The code is written in **C++** and uses the standard library (`bits/stdc++.h`) for vector operations and other utilities.

## Features
- **Initial Solution**: Accepts a user-defined initial solution to start the search.
- **Neighbor Generation**: Generates neighbors by flipping one bit at a time in the current solution.
- **Tabu List**: Maintains a list of recently visited solutions to avoid revisiting them, with a configurable tenure.
- **Feasibility Check**: Ensures solutions respect the knapsack's weight capacity.
- **Best Neighbor Selection**: Chooses the best feasible neighbor not in the tabu list based on gain.
- **Progress Tracking**: Outputs the current best neighbor and overall best solution at each iteration.
- **Configurable Parameters**: Allows customization of maximum iterations and tabu tenure.

## Prerequisites
To compile and run this code, you need:
- A C++ compiler supporting C++11 or later (e.g., `g++`, `clang++`).
- Standard C++ libraries (included via `<bits/stdc++.h>`).

No external dependencies are required beyond the C++ Standard Library.

## Installation
1. **Save the Code**: Copy the provided C++ code into a file named `knapsack_tabu.cpp`.
2. **Compile the Code**:
   ```bash
   g++ -std=c++11 knapsack_tabu.cpp -o knapsack_tabu
   ```
   Ensure you have a C++11-compliant compiler. Replace `g++` with your preferred compiler if necessary.
3. **Run the Program**:
   ```bash
   ./knapsack_tabu
   ```

## Usage
The program is configured with a sample knapsack problem in the `main` function. The input data consists of:
- **Gains**: A vector of integers representing the value of each item.
- **Weights**: A vector of integers representing the weight of each item.
- **Max Weight**: The knapsack's capacity (maximum allowable total weight).
- **Initial Solution**: A binary vector indicating which items are initially selected.
- **Max Iterations**: The number of iterations to run the algorithm.
- **Tabu Tenure**: The maximum size of the tabu list (number of recent solutions to remember).

### Example Input (Defined in `main`)
```cpp
vector<vector<int>> TC = {
    {7, 4, 3, 3},   // Gains
    {13, 12, 8, 10} // Weights
};
vector<int> initialSolution = {0, 1, 0, 1}; // Initial solution
int maxIterations = 5;
int maxWeight = 30;
int tabuTenure = 2;
```

### Running the Program
1. The program initializes with the provided data and runs the Tabu Search algorithm.
2. It outputs the current best neighbor and the overall best solution at each iteration.
3. The final output includes the best solution found, its total gain, and its total weight.

### Sample Output
```
Iteration 1:
Current Best Neighbor: 0 1 1 1
Sbest: 0 1 1 1
-----------------------------
Iteration 2:
Current Best Neighbor: 1 1 1 1
Sbest: 1 1 1 1
-----------------------------
...
Best Solution Found: 1 1 1 1
Total Gain: 17
Total Weight: 43
```

## Code Structure
The code is organized in a single C++ file with several functions to implement the Tabu Search algorithm. Key components include:

### Functions
- `printVector`: Prints a vector (used for solutions).
- `printMatrix`: Prints a matrix (used for debugging input data).
- `calculateGain`: Computes the total gain of a solution based on the gain vector.
- `calculateWeight`: Computes the total weight of a solution based on the weight vector.
- `generateNeighbors`: Generates all possible neighbors by flipping one bit at a time.
- `findBestNeighbor`: Selects the best feasible neighbor not in the tabu list.
- `tabuSearch`: Implements the main Tabu Search algorithm, iterating through neighbors and updating the best solution.
- `main`: Defines sample problem data, runs the algorithm, and prints results.

## Algorithm Parameters
The Tabu Search algorithm uses the following parameters, defined in the `main` function:
- **Max Iterations**: `5` — Controls how many iterations the algorithm runs.
- **Tabu Tenure**: `2` — Limits the size of the tabu list to prevent revisiting recent solutions.
- **Max Weight**: `30` — The knapsack's capacity.

These parameters can be tuned for different problem sizes or desired behaviors.

## Customization
To use the solver with different data:
1. Modify the `TC` matrix, `initialSolution`, `maxIterations`, `maxWeight`, and `tabuTenure` in the `main` function.
2. Ensure `TC` has two rows: `TC[0]` for gains and `TC[1]` for weights, with equal lengths.
3. Ensure `initialSolution` is a binary vector of the same length as the gains/weights.
4. Adjust `maxIterations` and `tabuTenure` to control runtime and exploration.

## Limitations
- The algorithm may not always find the global optimum, as Tabu Search is a heuristic method.
- The neighbor generation strategy (flipping one bit) may be less effective for large problems.
- The sample input has a small size, and the algorithm may need tuning for larger instances.
- The initial solution must be feasible; no validation is performed.

## Future Improvements
- Add validation for the initial solution's feasibility.
- Implement alternative neighbor generation strategies (e.g., flipping multiple bits).
- Add timing measurements to track performance.
- Support saving results to a file.
- Add visualization of the search process.

## License
This project is provided as-is for educational purposes. Feel free to modify and use it as needed.
