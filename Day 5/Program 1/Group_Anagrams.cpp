#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Map: sorted string -> list of anagrams
        unordered_map<string, vector<string>> anagramMap;

        for (const string& s : strs) {
            // Sort the string to get the "key" for anagram group
            string key = s;
            sort(key.begin(), key.end());

            // Add original string to the corresponding group
            anagramMap[key].push_back(s);
        }

        // Collect all groups into the result
        vector<vector<string>> result;
        for (auto& pair : anagramMap) {
            result.push_back(pair.second);
        }

        return result;
    }
};

// Helper function to print groups
void printGroups(vector<vector<string>>& groups) {
    cout << "[" << endl;
    for (auto& group : groups) {
        cout << "  [";
        for (int i = 0; i < group.size(); i++) {
            cout << "\"" << group[i] << "\"";
            if (i < group.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
}

int main() {
    Solution obj;

    // Test case 1
    vector<string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    cout << "Test 1:" << endl;
    vector<vector<string>> ans1 = obj.groupAnagrams(strs1);
    printGroups(ans1);

    // Test case 2
    vector<string> strs2 = {""};
    cout << "\nTest 2:" << endl;
    vector<vector<string>> ans2 = obj.groupAnagrams(strs2);
    printGroups(ans2);

    // Test case 3
    vector<string> strs3 = {"a"};
    cout << "\nTest 3:" << endl;
    vector<vector<string>> ans3 = obj.groupAnagrams(strs3);
    printGroups(ans3);

    // Test case 4
    vector<string> strs4 = {"listen", "silent", "hello", "world", "enlist"};
    cout << "\nTest 4:" << endl;
    vector<vector<string>> ans4 = obj.groupAnagrams(strs4);
    printGroups(ans4);

    return 0;
}
