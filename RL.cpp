#include <bits/stdc++.h>
#include <chrono>
using namespace std;

void printVector(const vector<int>& v) {
    for (int val : v) cout << val << " ";
    cout << endl;
}

void printMatrix(const vector<vector<int>>& mat) {
    for (const auto& row : mat) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
}

int calculateGain(const vector<vector<int>>& TC, const vector<int>& solution) {
    int gain = 0;
    for (size_t i = 0; i < solution.size(); ++i)
        gain += TC[0][i] * solution[i];
    return gain;
}

int calculateWeight(const vector<vector<int>>& TC, const vector<int>& solution) {
    int weight = 0;
    for (size_t i = 0; i < solution.size(); ++i)
        weight += TC[1][i] * solution[i];
    return weight;
}

vector<vector<int>> generateNeighbors(const vector<int>& solution) {
    int n = solution.size();
    vector<vector<int>> neighbors;

    for (int i = 0; i < n; ++i) {
        vector<int> neighbor = solution;
        neighbor[i] = 1 - neighbor[i];
        neighbors.push_back(neighbor);
    }
    return neighbors;
}
vector<int> findBestNeighbor(const vector<vector<int>>& TC, const vector<vector<int>>& neighbors, int maxWeight) {
    vector<int> bestSolution;
    int bestGain = 0;

    for (const auto& neighbor : neighbors) {
        int gain = calculateGain(TC, neighbor);
        int weight = calculateWeight(TC, neighbor);
        if (weight <= maxWeight && gain > bestGain) {
            bestGain = gain;
            bestSolution = neighbor;
        }
    }
    return bestSolution;
}

vector<int> localSearch(const vector<vector<int>>& TC, vector<int> initialSolution, int maxWeight) {
    vector<int> currentSolution = initialSolution;
    int currentGain = calculateGain(TC, currentSolution);
    int iter = 1;

    while (true) {
        cout << "Iteration " << iter << ":\n";
        
        auto neighbors = generateNeighbors(currentSolution);
        auto bestNeighbor = findBestNeighbor(TC, neighbors, maxWeight);
        if (bestNeighbor.empty() || calculateGain(TC, bestNeighbor) <= currentGain) {
            cout << "No better neighbor found. Stopping.\n";
            break;
        }

        currentSolution = bestNeighbor;
        currentGain = calculateGain(TC, currentSolution);

        cout << "Current Solution: ";
        printVector(currentSolution);
        cout << "Current Gain: " << currentGain << endl;
        cout << "-----------------------------\n";

        iter++;
    }

    return currentSolution;
}

int main() {

vector<vector<int>> TC = {
   
    { 91, 72, 90, 46, 55, 8, 35, 75, 61, 15, 77, 40, 63, 75, 29, 75, 17, 78, 40, 44 },
    { 84, 83, 43, 4, 44, 6, 82, 92, 25, 83, 56, 18, 58, 14, 48, 70, 96, 32, 68, 92 }
};
int maxWeight =  879 ;


    

    vector<int> initialSolution(TC[0].size(),0);

    auto start = chrono::high_resolution_clock::now();
    vector<int> bestSolution = localSearch(TC, initialSolution, maxWeight);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << "\nBest Solution Found: ";
    printVector(bestSolution);
    cout << "Total Gain: " << calculateGain(TC, bestSolution) << endl;
    cout << "Total Weight: " << calculateWeight(TC, bestSolution) << endl;
    cout << "Execution Time: " << duration.count()*0.001 << " seconds" << endl;

    return 0;
}
