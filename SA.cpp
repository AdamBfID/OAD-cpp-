#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

class KnapsackSA {
private:
    vector<vector<int>> TC;
    int maxWeight;
    vector<int> gains;
    vector<int> weights;
    int n;
    mt19937 rng;
    uniform_real_distribution<double> uniform_dist;
    uniform_int_distribution<int> bit_dist;
    
public:
    KnapsackSA(vector<vector<int>>& data, int capacity) : 
        TC(data), maxWeight(capacity), uniform_dist(0.0, 1.0), rng(random_device{}()) {
        gains = TC[0];
        weights = TC[1];
        n = gains.size();
        bit_dist = uniform_int_distribution<int>(0, n-1);
    }

    pair<int, int> evaluate(const vector<int>& solution) {
        int totalGain = 0;
        int totalWeight = 0;
        for (int i = 0; i < n; i++) {
            if (solution[i] == 1) {
                totalGain += gains[i];
                totalWeight += weights[i];
            }
        }
        return {totalGain, totalWeight};
    }
    
 
    bool isFeasible(const vector<int>& solution) {
        int totalWeight = evaluate(solution).second;
        return totalWeight <= maxWeight;
    }
    
 
    vector<int> generateInitialSolution() {
        vector<int> solution(n, 0);
        
    
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        shuffle(indices.begin(), indices.end(), rng);
        
        int currentWeight = 0;
        for (int idx : indices) {
            if (currentWeight + weights[idx] <= maxWeight) {
                solution[idx] = 1;
                currentWeight += weights[idx];
            }
        }
        
        return solution;
    }
    
  
    vector<int> getNeighbor(const vector<int>& current) {
        vector<int> neighbor = current;
        
 
        int numFlips = 1 + (rng() % 3);
        for (int i = 0; i < numFlips; i++) {
            int pos = bit_dist(rng);
            neighbor[pos] = 1 - neighbor[pos];
        }
        
        return neighbor;
    }
    

    pair<vector<int>, int> solve() {
        auto start = high_resolution_clock::now();

        double initialTemp = 1000.0;
        double finalTemp = 0.01;
        double coolingRate = 0.95;

        vector<int> currentSolution = generateInitialSolution();
        vector<int> bestSolution = currentSolution;
        
        int currentGain = evaluate(currentSolution).first;
        int bestGain = currentGain;
        
        double temperature = initialTemp;
        
        cout << "Starting simulated annealing..." << endl;
        cout << "Initial solution gain: " << currentGain << endl;
        cout << "Initial temperature: " << temperature << endl;
        
        int iterations = 0;
        
        while (temperature > finalTemp) {
          
            vector<int> neighbor = getNeighbor(currentSolution);
            if (!isFeasible(neighbor)) {
                continue;
            }
            
            int neighborGain = evaluate(neighbor).first;
            int deltaF = neighborGain - currentGain;
            
            bool acceptSolution = false;
            
            if (deltaF > 0) {
                acceptSolution = true;
            } else {
                double probability = exp(deltaF / temperature);
                double randomVal = uniform_dist(rng);
                if (probability > randomVal) {
                    acceptSolution = true;
                }
            }
            
            if (acceptSolution) {
                currentSolution = neighbor;
                currentGain = neighborGain;
                
               
                if (currentGain > bestGain) {
                    bestSolution = currentSolution;
                    bestGain = currentGain;
                }
                
             
                temperature *= coolingRate;
            }
        
            
            iterations++;
            
           
            if (iterations % 1000 == 0) {
                cout << "Iteration: " << iterations << ", Temp: " << temperature 
                     << ", Current gain: " << currentGain << ", Best gain: " << bestGain << endl;
            }
        }
        
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        double milliseconds = duration.count();
        
        cout << "\nSimulated annealing completed!" << endl;
        cout << "Total iterations: " << iterations << endl;
        cout << "Final temperature: " << temperature << endl;
        
        return {bestSolution, milliseconds};
    }
    
    void printSolution(const vector<int>& solution, double timeMilliseconds) {
        auto [gain, weight] = evaluate(solution);
        
        cout << "\n=== RESULTS ===" << endl;
        cout << "Best solution: ";
        for (int bit : solution) {
            cout << bit;
        }
        cout << endl;
        cout << "Gain: " << gain << endl;
        cout << "Weight: " << weight << "/" << maxWeight << endl;
        cout << "Time taken: " << timeMilliseconds << " milliseconds" << endl;
    }
};

int main() {
   
    vector<vector<int>> TC = {
    
    { 91, 72, 90, 46, 55, 8, 35, 75, 61, 15, 77, 40, 63, 75, 29, 75, 17, 78, 40, 44 },
   
    { 84, 83, 43, 4, 44, 6, 82, 92, 25, 83, 56, 18, 58, 14, 48, 70, 96, 32, 68, 92 }
};
int maxWeight =  879 ;

    
    
    KnapsackSA sa(TC, maxWeight);
    auto [bestSolution, timeMilliseconds] = sa.solve();
    sa.printSolution(bestSolution, timeMilliseconds);
    
    return 0;
}
