#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.length() < p.length()) return result;

        vector<int> pCount(26, 0);
        vector<int> sCount(26, 0);

        // Count frequencies of characters in string p
        for (char c : p) {
            pCount[c - 'a']++;
        }

        int pLen = p.length();
        
        // Sliding window over string s
        for (int i = 0; i < s.length(); i++) {
            // Add the new character to the window
            sCount[s[i] - 'a']++;

            // Remove the character that fell out of the window (if window size > pLen)
            if (i >= pLen) {
                sCount[s[i - pLen] - 'a']--;
            }

            // Compare the frequency arrays
            if (sCount == pCount) {
                // i is the right end of the window. The start index is i - pLen + 1
                result.push_back(i - pLen + 1);
            }
        }

        return result;
    }
};

// Helper function to print a vector
void printVector(const vector<int>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution obj;

    // Test case 1
    string s1 = "cbaebabacd";
    string p1 = "abc";
    cout << "Test 1: s='cbaebabacd', p='abc' -> ";
    printVector(obj.findAnagrams(s1, p1));

    // Test case 2
    string s2 = "abab";
    string p2 = "ab";
    cout << "Test 2: s='abab', p='ab' -> ";
    printVector(obj.findAnagrams(s2, p2));

    // Test case 3
    string s3 = "a";
    string p3 = "ab";
    cout << "Test 3: s='a', p='ab' -> ";
    printVector(obj.findAnagrams(s3, p3));

    return 0;
}
