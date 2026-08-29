#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int maxCount = 0;
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            // Increment the count of the current character
            count[s[right] - 'A']++;
            
            // Keep track of the most frequent character in the current window
            maxCount = max(maxCount, count[s[right] - 'A']);

            // If the window size minus the most frequent character count is greater than k,
            // it means we need more than k replacements, which is not allowed.
            // So, shrink the window from the left.
            if ((right - left + 1) - maxCount > k) {
                count[s[left] - 'A']--;
                left++;
            }

            // The window size is valid, update the maximum length
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main() {
    Solution obj;

    // Test case 1
    string s1 = "ABAB";
    int k1 = 2;
    cout << "Test 1: s='ABAB', k=2 -> " << obj.characterReplacement(s1, k1) << endl;

    // Test case 2
    string s2 = "AABABBA";
    int k2 = 1;
    cout << "Test 2: s='AABABBA', k=1 -> " << obj.characterReplacement(s2, k2) << endl;

    // Test case 3
    string s3 = "AAAA";
    int k3 = 2;
    cout << "Test 3: s='AAAA', k=2 -> " << obj.characterReplacement(s3, k3) << endl;

    return 0;
}
