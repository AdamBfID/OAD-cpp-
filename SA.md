# Knapsack Simulated Annealing Solver

## Overview
This project implements a **Simulated Annealing (SA)** algorithm to solve the **0/1 Knapsack Problem**. The 0/1 Knapsack Problem is a combinatorial optimization problem where, given a set of items with associated weights and gains, the goal is to select a subset of items that maximizes the total gain while ensuring the total weight does not exceed a given capacity.

The algorithm uses a probabilistic metaheuristic (Simulated Annealing) to explore the solution space, balancing exploration and exploitation to find a near-optimal solution. The code is written in **C++** and utilizes standard libraries for random number generation, time measurement, and vector operations.

## Features
- **Random Initial Solution**: Generates a feasible initial solution by randomly selecting items within the weight constraint.
- **Neighbor Generation**: Creates neighboring solutions by flipping 1-3 random bits in the current solution.
- **Feasibility Check**: Ensures solutions do not exceed the knapsack's weight capacity.
- **Simulated Annealing Process**: Iteratively improves the solution by accepting better solutions or, with some probability, worse solutions to escape local optima.
- **Progress Tracking**: Outputs progress every 1000 iterations, including current temperature, gain, and best gain.
- **Performance Measurement**: Tracks and reports the execution time in milliseconds.
- **Configurable Parameters**: Initial temperature, final temperature, and cooling rate can be adjusted for different problem sizes or behaviors.

## Prerequisites
To compile and run this code, you need:
- A C++ compiler supporting C++11 or later (e.g., `g++`, `clang++`).
- Standard C++ libraries (`iostream`, `vector`, `random`, `cmath`, `chrono`, `algorithm`).

No external dependencies are required beyond the C++ Standard Library.

## Installation
1. **Save the Code**: Copy the provided C++ code into a file named `knapsack_sa.cpp`.
2. **Compile the Code**:
   ```bash
   g++ -std=c++11 knapsack_sa.cpp -o knapsack_sa
   ```
   Ensure you have a C++11-compliant compiler. Replace `g++` with your preferred compiler if necessary.
3. **Run the Program**:
   ```bash
   ./knapsack_sa
   ```

## Usage
The program is configured with a sample knapsack problem in the `main` function. The input data consists of:
- **Gains**: A vector of integers representing the value of each item.
- **Weights**: A vector of integers representing the weight of each item.
- **Max Weight**: The knapsack's capacity (maximum allowable total weight).

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
1. The program initializes a `KnapsackSA` object with the provided data and capacity.
2. It runs the Simulated Annealing algorithm to find a near-optimal solution.
3. The output includes:
   - Progress updates every 1000 iterations (iteration number, temperature, current gain, best gain).
   - Final results, including the best solution (binary vector), total gain, total weight, and execution time.

### Sample Output
```
Starting simulated annealing...
Initial solution gain: 512
Initial temperature: 1000
Iteration: 1000, Temp: 590.49, Current gain: 520, Best gain: 530
...
Simulated annealing completed!
Total iterations: 12345
Final temperature: 0.0098

=== RESULTS ===
Best solution: 11001001001011001010
Gain: 620
Weight: 850/879
Time taken: 245.67 milliseconds
```

## Code Structure
The code is organized in a single C++ file with a `KnapsackSA` class that encapsulates the Simulated Annealing logic. Key components include:

### Class: `KnapsackSA`
- **Constructor**: Initializes the problem with gains, weights, and max weight; sets up random number generators.
- **Methods**:
  - `evaluate`: Computes the total gain and weight of a solution.
  - `isFeasible`: Checks if a solution's total weight is within the capacity.
  - `generateInitialSolution`: Creates a random feasible initial solution.
  - `getNeighbor`: Generates a neighbor by flipping 1-3 random bits.
  - `solve`: Runs the Simulated Annealing algorithm and returns the best solution and execution time.
  - `printSolution`: Displays the final solution, gain, weight, and runtime.

### Main Function
- Defines sample problem data (gains, weights, max weight).
- Creates a `KnapsackSA` object and runs the solver.
- Prints the results.

## Algorithm Parameters
The Simulated Annealing algorithm uses the following parameters, defined in the `solve` method:
- **Initial Temperature**: `1000.0` — High to allow exploration of diverse solutions.
- **Final Temperature**: `0.01` — Low to focus on exploitation near the end.
- **Cooling Rate**: `0.95` — Reduces temperature by 5% each iteration for accepted solutions.

These parameters can be tuned for different problem sizes or desired runtimes.

## Customization
To use the solver with different data:
1. Modify the `TC` vector and `maxWeight` in the `main` function.
2. Ensure `TC` has two rows: `TC[0]` for gains and `TC[1]` for weights, with equal lengths.
3. Adjust algorithm parameters (`initialTemp`, `finalTemp`, `coolingRate`) in the `solve` method if needed.

## Limitations
- The algorithm may not always find the global optimum, as Simulated Annealing is a heuristic method.
- Performance depends on parameter tuning and problem size.
- The current implementation assumes non-negative gains and weights.

## Future Improvements
- Add support for dynamic parameter tuning based on problem size.
- Implement alternative neighbor generation strategies (e.g., swapping items).
- Add visualization of the optimization process.
- Support saving results to a file.

## License
This project is provided as-is for educational purposes. Feel free to modify and use it as needed.
