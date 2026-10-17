#include <iostream>
#include <cstdint>
#include <bitset>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        
        for (int i = 0; i < 32; i++) {
            // Shift result left to make room for the next bit
            result <<= 1;
            // Extract the last bit of n and add it to result
            result |= (n & 1);
            // Shift n right to process the next bit
            n >>= 1;
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    
    uint32_t num1 = 0b00000010100101000001111010011100;
    uint32_t rev1 = solution.reverseBits(num1);
    cout << "Input:    " << bitset<32>(num1) << " (" << num1 << ")" << endl;
    cout << "Reversed: " << bitset<32>(rev1) << " (" << rev1 << ")" << endl;
    cout << endl;
    
    uint32_t num2 = 0b11111111111111111111111111111101;
    uint32_t rev2 = solution.reverseBits(num2);
    cout << "Input:    " << bitset<32>(num2) << " (" << num2 << ")" << endl;
    cout << "Reversed: " << bitset<32>(rev2) << " (" << rev2 << ")" << endl;
    
    return 0;
}
