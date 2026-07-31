#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) return s;

        int start = 0;  // Start index of the longest palindrome
        int maxLen = 1;  // Length of the longest palindrome

        // Try each character (and each gap between characters) as center
        for (int i = 0; i < n; i++) {
            // Case 1: Odd-length palindrome (single character center)
            int left = i, right = i;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > maxLen) {
                    start = left;
                    maxLen = right - left + 1;
                }
                left--;
                right++;
            }

            // Case 2: Even-length palindrome (two character center)
            left = i;
            right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > maxLen) {
                    start = left;
                    maxLen = right - left + 1;
                }
                left--;
                right++;
            }
        }

        return s.substr(start, maxLen);
    }
};

int main() {
    Solution obj;

    // Test case 1
    string s1 = "babad";
    cout << "Test 1: \"" << s1 << "\" -> \"" << obj.longestPalindrome(s1) << "\"" << endl;

    // Test case 2
    string s2 = "cbbd";
    cout << "Test 2: \"" << s2 << "\" -> \"" << obj.longestPalindrome(s2) << "\"" << endl;

    // Test case 3
    string s3 = "a";
    cout << "Test 3: \"" << s3 << "\" -> \"" << obj.longestPalindrome(s3) << "\"" << endl;

    // Test case 4
    string s4 = "racecar";
    cout << "Test 4: \"" << s4 << "\" -> \"" << obj.longestPalindrome(s4) << "\"" << endl;

    // Test case 5
    string s5 = "aacabdkacaa";
    cout << "Test 5: \"" << s5 << "\" -> \"" << obj.longestPalindrome(s5) << "\"" << endl;

    return 0;
}
