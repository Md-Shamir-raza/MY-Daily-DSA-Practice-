#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;
        int currentTank = 0;
        int startingStation = 0;

        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            
            // Add the net gas gained/lost at this station to our current tank
            currentTank += gas[i] - cost[i];

            // If currentTank drops below 0, we can't reach the next station
            if (currentTank < 0) {
                // Therefore, this station (and any previous station we tried) cannot be the start.
                // The earliest possible start is the next station.
                startingStation = i + 1;
                // Reset the tank for the new starting point attempt
                currentTank = 0;
            }
        }

        // If the total gas available is less than total cost, it's impossible to complete the circuit
        if (totalGas < totalCost) {
            return -1;
        }

        // Otherwise, there is a unique solution, and we found it!
        return startingStation;
    }
};

int main() {
    Solution obj;

    // Test case 1
    vector<int> gas1 = {1, 2, 3, 4, 5};
    vector<int> cost1 = {3, 4, 5, 1, 2};
    cout << "Test 1: -> " << obj.canCompleteCircuit(gas1, cost1) << endl; // Expected: 3

    // Test case 2
    vector<int> gas2 = {2, 3, 4};
    vector<int> cost2 = {3, 4, 3};
    cout << "Test 2: -> " << obj.canCompleteCircuit(gas2, cost2) << endl; // Expected: -1

    return 0;
}
