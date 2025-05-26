#include <bits/stdc++.h>
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

vector<int> findBestNeighbor(const vector<vector<int>>& TC, const vector<vector<int>>& neighbors,
                             const vector<vector<int>>& tabuList, int maxWeight) {
    vector<int> bestSolution;
    int bestGain = 0;

    for (const auto& neighbor : neighbors) {
        if (find(tabuList.begin(), tabuList.end(), neighbor) == tabuList.end()) {
            int gain = calculateGain(TC, neighbor);
            int weight = calculateWeight(TC, neighbor);
            if (weight <= maxWeight && gain > bestGain) {
                bestGain = gain;
                bestSolution = neighbor;
            }
        }
    }
    return bestSolution;
}
vector<int> tabuSearch(const vector<vector<int>>& TC, vector<int> initialSolution, int maxIterations, int maxWeight, int tabuTenure) {
    vector<int> currentSolution = initialSolution;
    vector<int> bestSolution = initialSolution;
    vector<vector<int>> tabuList;

    for (int iter = 1; iter <= maxIterations; ++iter) {
        cout << "Iteration " << iter << ":\n";
        tabuList.push_back(currentSolution);

        auto neighbors = generateNeighbors(currentSolution);
        auto bestNeighbor = findBestNeighbor(TC, neighbors, tabuList, maxWeight);

        if (!bestNeighbor.empty()) {
            currentSolution = bestNeighbor;
            if (calculateGain(TC, currentSolution) > calculateGain(TC, bestSolution)) {
                bestSolution = currentSolution;
            }
        }

        cout << "Current Best Neighbor: ";
        printVector(currentSolution);
        cout << "Sbest: ";
        printVector(bestSolution);
        cout << "-----------------------------\n";

        if (tabuList.size() > tabuTenure)
            tabuList.erase(tabuList.begin());
    }

    return bestSolution;
}

// Main function
int main() {
    
    vector<vector<int>> TC = {
        {7, 4, 3, 3},   
        {13, 12, 8, 10} 
    };
    vector<int> initialSolution = {0, 1, 0, 1}; 
    int maxIterations = 5;
    int maxWeight = 30;
    int tabuTenure = 2;

    vector<int> bestSolution = tabuSearch(TC, initialSolution, maxIterations, maxWeight, tabuTenure);

    cout << "\nBest Solution Found: ";
    printVector(bestSolution);
    cout << "Total Gain: " << calculateGain(TC, bestSolution) << endl;
    cout << "Total Weight: " << calculateWeight(TC, bestSolution) << endl;

    return 0;
}
