#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        
        vector<int> freq(26, 0);
        
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        
        for (int count : freq) {
            if (count != 0) return false;
        }
        
        return true;
    }
};

int main() {
    Solution solution;
    
    cout << "isAnagram(\"anagram\", \"nagaram\"): " 
         << (solution.isAnagram("anagram", "nagaram") ? "true" : "false") << endl;
    
    cout << "isAnagram(\"rat\", \"car\"): " 
         << (solution.isAnagram("rat", "car") ? "true" : "false") << endl;
    
    cout << "isAnagram(\"listen\", \"silent\"): " 
         << (solution.isAnagram("listen", "silent") ? "true" : "false") << endl;
    
    cout << "isAnagram(\"a\", \"ab\"): " 
         << (solution.isAnagram("a", "ab") ? "true" : "false") << endl;
    
    return 0;
}
