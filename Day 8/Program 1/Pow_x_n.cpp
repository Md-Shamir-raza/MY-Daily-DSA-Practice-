#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        // Handle edge case: convert n to long long to handle INT_MIN
        long long power = n;

        // If power is negative, invert x and make power positive
        if (power < 0) {
            x = 1.0 / x;
            power = -power;
        }

        double result = 1.0;

        // Binary exponentiation
        while (power > 0) {
            // If power is odd, multiply result by x
            if (power % 2 == 1) {
                result *= x;
            }

            // Square x and halve the power
            x *= x;
            power /= 2;
        }

        return result;
    }
};

int main() {
    Solution obj;

    // Test case 1
    cout << "Test 1: pow(2.0, 10) = " << obj.myPow(2.0, 10) << endl;

    // Test case 2
    cout << "Test 2: pow(2.1, 3) = " << obj.myPow(2.1, 3) << endl;

    // Test case 3
    cout << "Test 3: pow(2.0, -2) = " << obj.myPow(2.0, -2) << endl;

    // Test case 4
    cout << "Test 4: pow(3.0, 0) = " << obj.myPow(3.0, 0) << endl;

    // Test case 5
    cout << "Test 5: pow(0.5, -3) = " << obj.myPow(0.5, -3) << endl;

    // Test case 6
    cout << "Test 6: pow(1.0, 2147483647) = " << obj.myPow(1.0, 2147483647) << endl;

    return 0;
}
