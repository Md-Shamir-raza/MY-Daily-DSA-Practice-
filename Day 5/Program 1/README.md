
# 🔠 Group Anagrams – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #49 – Medium)

Given an array of strings `strs`, group the **anagrams** together. You can return the answer in **any order**.

An **anagram** is a word formed by rearranging the letters of another word, using all the original letters exactly once.

Example:

```
Input:  strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
```

More examples:

```
Input:  [""]       → Output: [[""]]
Input:  ["a"]      → Output: [["a"]]
```

---

# 🧠 Approach: Sort + Hash Map

The key insight is:

> Two strings are anagrams if and only if their **sorted versions are identical**.

For example:
```
"eat" → sorted → "aet"
"tea" → sorted → "aet"
"ate" → sorted → "aet"
```

All three produce the same sorted key `"aet"`, so they belong to the same group.

### Strategy:

1. For each string, sort it to produce a **key**.
2. Use a **hash map** where the key is the sorted string and the value is a list of original strings.
3. Collect all groups from the hash map.

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;

        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            anagramMap[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& pair : anagramMap) {
            result.push_back(pair.second);
        }

        return result;
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 `unordered_map<string, vector<string>> anagramMap;`

* A **hash map** that maps:
  - **Key**: Sorted version of the string (the "anagram signature")
  - **Value**: Vector of all original strings that share this sorted form

* Example state after processing `["eat", "tea", "ate"]`:
```
{
  "aet" → ["eat", "tea", "ate"]
}
```

---

### 🔹 `for (const string& s : strs)`

* Iterate through every string in the input array.
* `const string&` avoids making copies for efficiency.

---

### 🔹 `string key = s;`

* Create a copy of the current string.
* We'll sort this copy to use as the hash map key.
* We keep the original `s` intact to store it in the group.

---

### 🔹 `sort(key.begin(), key.end());`

* Sort the characters of the key string alphabetically.
* This transforms any anagram into the same canonical form.

```
"eat" → "aet"
"tea" → "aet"
"tan" → "ant"
"nat" → "ant"
"bat" → "abt"
```

---

### 🔹 `anagramMap[key].push_back(s);`

* Use the sorted key to find (or create) the corresponding group.
* Add the **original** string `s` to that group.

#### Step by step with `["eat","tea","tan","ate","nat","bat"]`:

| String | Sorted Key | Map State |
| ------ | ---------- | --------- |
| "eat"  | "aet"      | {"aet": ["eat"]} |
| "tea"  | "aet"      | {"aet": ["eat","tea"]} |
| "tan"  | "ant"      | {"aet": ["eat","tea"], "ant": ["tan"]} |
| "ate"  | "aet"      | {"aet": ["eat","tea","ate"], "ant": ["tan"]} |
| "nat"  | "ant"      | {"aet": ["eat","tea","ate"], "ant": ["tan","nat"]} |
| "bat"  | "abt"      | {"aet": [...], "ant": [...], "abt": ["bat"]} |

---

### 🔹 Collect Results

```cpp
vector<vector<string>> result;
for (auto& pair : anagramMap) {
    result.push_back(pair.second);
}
```

* Iterate through all key-value pairs in the map.
* Each `pair.second` is a vector of anagrams → add it to result.

---

### 🔹 `return result;`

* Return all the grouped anagrams.

---

# 📊 Step-by-Step Example

Input:

```
strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
```

### Phase 1: Build the Map

| Step | String | Sorted Key | Group |
| ---- | ------ | ---------- | ----- |
| 1    | "eat"  | "aet"      | ["eat"] |
| 2    | "tea"  | "aet"      | ["eat", "tea"] |
| 3    | "tan"  | "ant"      | ["tan"] |
| 4    | "ate"  | "aet"      | ["eat", "tea", "ate"] |
| 5    | "nat"  | "ant"      | ["tan", "nat"] |
| 6    | "bat"  | "abt"      | ["bat"] |

### Phase 2: Collect Groups

```
Result = [
  ["eat", "tea", "ate"],
  ["tan", "nat"],
  ["bat"]
]
```

✅ Final Answer = **[["eat","tea","ate"], ["tan","nat"], ["bat"]]**

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(n × k log k)**

* `n` = number of strings.
* `k` = maximum length of a string.
* For each string, sorting takes `O(k log k)`.
* Total: `O(n × k log k)`.

---

### 🔹 Space Complexity: **O(n × k)**

* The hash map stores all `n` strings.
* Each string has at most `k` characters.

---

# ⚔️ Comparison With Other Approaches

| Approach                        | Time Complexity  | Space Complexity |
| ------------------------------- | ---------------- | ---------------- |
| Brute Force (Compare All Pairs) | O(n² × k)       | O(n × k)         |
| Sort Key + Hash Map             | O(n × k log k)  | O(n × k)         |
| Character Count Key + Hash Map  | O(n × k)        | O(n × k)         |

The sort-based approach is clean and intuitive. The character count approach is slightly faster but more complex to implement 🚀

---

# 💡 Alternative: Character Count Key

Instead of sorting, you can use a **character frequency array** as the key:

```cpp
string key = "";
int count[26] = {0};
for (char c : s) count[c - 'a']++;
for (int i = 0; i < 26; i++) {
    key += "#" + to_string(count[i]);
}
```

This gives **O(n × k)** time complexity (no sorting needed).

---

# ⭐ Key Concepts Learned

* Using **sorting** to create canonical forms for comparison
* **Hash map grouping** — a powerful pattern for classification problems
* Anagram detection through character equivalence
* Trade-off between sorting-based vs counting-based approaches
* Working with `unordered_map<string, vector<string>>`

---

# 🏆 Why This Problem Is Important

* One of the **most frequently asked** medium problems
* Teaches hash map grouping — used in many real-world applications
* Tests string manipulation and data structure selection
* Foundation for understanding hashing and canonical forms
* Commonly asked at Amazon, Google, Microsoft, Meta, Bloomberg
