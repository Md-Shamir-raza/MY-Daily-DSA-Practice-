
# 🔎 Two Sum – Line by Line Explanation (C++)

## ✅ Header Files

```cpp
#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<unordered_map>
using namespace std;
```

### Explanation:

* `#include<iostream>` → Used for input and output (like `cout`, `cin`).
* `#include<vector>` → Used to create dynamic arrays (vector).
* `#include<unordered_map>` → Used to create a hash table (for fast searching).
* Other headers (`iomanip`, `cmath`, `algorithm`, `map`) are not required for this solution.
* `using namespace std;` → So we don’t have to write `std::` before every standard library object.

---

# ✅ Class Definition

```cpp
class Solution {
```

We create a class named `Solution`.
This is common in coding platforms like LeetCode.

---

# ✅ Function Definition

```cpp
vector<int> twoSum(vector<int>& nums, int target)
```

### Explanation:

* `vector<int>` → The function returns a vector of integers.
* `nums` → Input array (passed by reference for efficiency).
* `target` → The number we want to achieve by adding two numbers from the array.

---

# ✅ Creating Hash Map

```cpp
unordered_map<int, int> hash_map;
```

### What is this?

It stores:

```
number → index
```

Example:
If nums = {2,7,11}
It stores:

```
2 → 0
7 → 1
11 → 2
```

### Why?

So we can check in **O(1)** time if a required number exists.

---

# ✅ Result Vector

```cpp
vector<int> result;
```

This will store the two indices that form the answer.

---

# ✅ Loop Through Array

```cpp
for (int i = 0; i < nums.size(); ++i)
```

We iterate through every element in the array.

`i` is the index.

---

# ✅ Calculate Complement

```cpp
int complement = target - nums[i];
```

If:

```
target = 6
nums[i] = 2
```

Then:

```
complement = 6 - 2 = 4
```

We now check if **4 exists in the array**.

---

# ✅ Check If Complement Exists

```cpp
if (hash_map.find(complement) != hash_map.end())
```

### What this means:

* `hash_map.find(complement)` → Search for complement
* If found → it returns iterator
* If NOT found → it returns `hash_map.end()`

So this line checks:
👉 "Is the required number already stored in the map?"

---

# ✅ If Found → Return Answer

```cpp
result.push_back(hash_map[complement]);
result.push_back(i);
return result;
```

* `hash_map[complement]` → gives index of complement
* `i` → current index

So we push both indices and return.

---

# ✅ If Not Found → Store Current Number

```cpp
hash_map[nums[i]] = i;
```

We store:

```
number → index
```

So that future elements can use it.

---

# ✅ If No Solution Found

```cpp
return result;
```

If no pair exists, an empty vector is returned.

---

# ✅ Main Function

```cpp
int main(){
```

Program execution starts here.

---

# ✅ Create Object

```cpp
Solution obj;
```

We create an object of class `Solution`.

---

# ✅ Test Case

```cpp
vector<int> nums = {3,2,4};
int target = 6;
```

Input:

```
3 + 2 + 4
Target = 6
```

---

# ✅ Call Function

```cpp
vector<int> ans = obj.twoSum(nums, target);
```

We call the function and store the result.

---

# ✅ Print Answer (Correct Way)

```cpp
for(auto i : ans) {
    cout << i << " ";
}
```

This prints the indices stored in `ans`.

---

# 🧠 How This Algorithm Works (Logic Summary)

1. Traverse array once.
2. For each element:

   * Calculate required complement.
   * Check if it exists in hash map.
   * If yes → return indices.
   * If no → store current element in map.
3. Time Complexity = **O(n)**
4. Space Complexity = **O(n)**

---

# 🔥 Example Walkthrough

Input:

```
nums = {3,2,4}
target = 6
```

Step-by-step:

| i | nums[i] | complement | Map       | Action                 |
| - | ------- | ---------- | --------- | ---------------------- |
| 0 | 3       | 3          | {}        | Store 3→0              |
| 1 | 2       | 4          | {3→0}     | Store 2→1              |
| 2 | 4       | 2          | {3→0,2→1} | Found 2 → Return (1,2) |

Output:

```
1 2
```

---

# ⭐ Why This is Better Than Brute Force?

Brute force:

* Check every pair
* Time Complexity = **O(n²)**

Hashing:

* Only one loop
* Time Complexity = **O(n)**

Huge improvement for large arrays 🚀

# ⏱️ Complexity Analysis
🔹 Time Complexity: O(n)

We traverse the array only once.

🔹 Space Complexity: O(n)

In worst case, we store all elements in hash map.

# ⚔️ Comparison With Brute Force
Approach	Time Complexity	Space Complexity
Brute Force	O(n²)	O(1)
Hash Map (Optimized)	O(n)	O(n)

Using hashing improves performance significantly for large inputs 🚀
