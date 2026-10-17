#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.size() < t.size()) return "";
        
        // Frequency map for characters in t
        unordered_map<char, int> tFreq;
        for (char c : t) tFreq[c]++;
        
        int required = tFreq.size(); // Number of unique characters in t that must be present
        int formed = 0;              // Number of unique characters in current window matching required frequency
        
        unordered_map<char, int> windowFreq;
        
        int left = 0;
        int minLen = INT_MAX, minStart = 0;
        
        for (int right = 0; right < s.size(); right++) {
            // Expand the window by adding character from the right
            char c = s[right];
            windowFreq[c]++;
            
            // Check if the frequency of this character matches t's requirement
            if (tFreq.count(c) && windowFreq[c] == tFreq[c]) {
                formed++;
            }
            
            // Try to contract the window from the left while it's valid
            while (formed == required) {
                // Update the minimum window
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }
                
                // Remove the leftmost character
                char leftChar = s[left];
                windowFreq[leftChar]--;
                if (tFreq.count(leftChar) && windowFreq[leftChar] < tFreq[leftChar]) {
                    formed--;
                }
                left++;
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};

int main() {
    Solution solution;
    
    cout << "minWindow(\"ADOBECODEBANC\", \"ABC\"): " 
         << solution.minWindow("ADOBECODEBANC", "ABC") << endl;
    
    cout << "minWindow(\"a\", \"a\"): " 
         << solution.minWindow("a", "a") << endl;
    
    cout << "minWindow(\"a\", \"aa\"): " 
         << solution.minWindow("a", "aa") << endl;
    
    cout << "minWindow(\"aa\", \"aa\"): " 
         << solution.minWindow("aa", "aa") << endl;
    
    return 0;
}
