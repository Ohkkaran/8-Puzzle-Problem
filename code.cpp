#include <bits/stdc++.h>
using namespace std;

int N = 3;  // Size of the puzzle

// Manhattan Distance Heuristic function
int manhattanDistance(vector<vector<int>>& state, vector<vector<int>>& goal) {
    int distance = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (state[i][j] != 0) {
                for (int x = 0; x < N; ++x) {
                    for (int y = 0; y < N; ++y) {
                        if (state[i][j] == goal[x][y]) {
                            distance += abs(i - x) + abs(j - y);
                        }
                    }
                }
            }
        }
    }
    return distance;
}

// Get the possible neighboring states
vector<vector<vector<int>>> getNeighbors(vector<vector<int>>& state) {
    vector<vector<vector<int>>> neighbors;
    int x, y;
    
    // Find the position of the empty space (0)
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (state[i][j] == 0) {
                x = i;
                y = j;
                break;
            }
        }
    }
    
    // Possible moves: up, down, left, right
    vector<pair<int, int>> moves = {{x-1, y}, {x+1, y}, {x, y-1}, {x, y+1}};
    
    for (auto& move : moves) {
        int newX = move.first, newY = move.second;
        if (newX >= 0 && newX < N && newY >= 0 && newY < N) {
            vector<vector<int>> newState = state;
            swap(newState[x][y], newState[newX][newY]);
            neighbors.push_back(newState);
        }
    }
    
    return neighbors;
}

// Hill Climbing algorithm
vector<vector<int>> hillClimbing(vector<vector<int>>& start, vector<vector<int>>& goal) {
    vector<vector<int>> currentState = start;
    int currentCost = manhattanDistance(currentState, goal);
    
    while (true) {
        vector<vector<vector<int>>> neighbors = getNeighbors(currentState);
        vector<vector<int>> nextState;
        int nextCost = currentCost;
        
        // Explore all neighbors and find the one with the least cost
        for (auto& neighbor : neighbors) {
            int neighborCost = manhattanDistance(neighbor, goal);
            if (neighborCost < nextCost) {
                nextState = neighbor;
                nextCost = neighborCost;
            }
        }
        
        // If no better neighbor is found, return the current state
        if (nextCost >= currentCost) {
            return currentState;
        }
        
        currentState = nextState;
        currentCost = nextCost;
    }
}

// Print the state of the puzzle
void printPuzzle(vector<vector<int>>& state) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << state[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    // Initial and goal state for the 8-puzzle problem
    vector<vector<int>> startState = {
        {1, 2, 3},
        {4, 0, 5},
        {7, 8, 6}
    };

    vector<vector<int>> goalState = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };

    cout << "Initial state:" << endl;
    printPuzzle(startState);

    // Run the hill climbing algorithm
    vector<vector<int>> resultState = hillClimbing(startState, goalState);

    cout << "Result state:" << endl;
    printPuzzle(resultState);

    int resultCost = manhattanDistance(resultState, goalState);
    cout << "Manhattan distance: " << resultCost << endl;

    return 0;
}
