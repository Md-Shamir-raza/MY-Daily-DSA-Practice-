#include<iostream>
#include<string>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) return 0;

        unordered_set<char> charSet;
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < n; right++) {
            // If character already exists in the window, shrink from left
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                left++;
            }

            // Add current character to the set
            charSet.insert(s[right]);

            // Update maximum length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main() {
    Solution obj;

    // Test case 1
    string s1 = "abcabcbb";
    cout << "Test 1: \"" << s1 << "\" -> " << obj.lengthOfLongestSubstring(s1) << endl;

    // Test case 2
    string s2 = "bbbbb";
    cout << "Test 2: \"" << s2 << "\" -> " << obj.lengthOfLongestSubstring(s2) << endl;

    // Test case 3
    string s3 = "pwwkew";
    cout << "Test 3: \"" << s3 << "\" -> " << obj.lengthOfLongestSubstring(s3) << endl;

    // Test case 4
    string s4 = "";
    cout << "Test 4: \"" << s4 << "\" -> " << obj.lengthOfLongestSubstring(s4) << endl;

    // Test case 5
    string s5 = "dvdf";
    cout << "Test 5: \"" << s5 << "\" -> " << obj.lengthOfLongestSubstring(s5) << endl;

    return 0;
}
