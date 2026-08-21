
# 📊 Top K Frequent Elements – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #347 – Medium)

Given an integer array `nums` and an integer `k`, return the `k` **most frequent** elements. You may return the answer in **any order**.

Example:

```
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Explanation: 1 appears 3 times, 2 appears 2 times, 3 appears 1 time. The top 2 most frequent are 1 and 2.
```

More examples:

```
Input: nums = [1], k = 1
Output: [1]
```

---

# 🧠 Approach: Hash Map + Min-Heap

The key insight is:

> We need to count frequencies first. This is a classic use case for a Hash Map.
> Then, we need to find the "Top K" of those frequencies. Just like finding the "Kth Largest Element", we can use a **Min-Heap** of size `k` to track the most frequent elements seen so far.
> Since we need to associate the frequency back to the original number, our heap will store `(frequency, number)` pairs.

*(Note: There is also an `O(N)` solution using Bucket Sort, but the Heap approach is highly versatile and generalizes better to streaming data where frequencies update dynamically).*

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        for (int num : nums) {
            countMap[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (auto& pair : countMap) {
            minHeap.push({pair.second, pair.first});
            
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 Step 1: Count Frequencies

```cpp
unordered_map<int, int> countMap;
for (int num : nums) {
    countMap[num]++;
}
```
* We use an `unordered_map` where the key is the number and the value is its frequency.
* We iterate through the array and increment the count for each number. Takes `O(N)` time.

---

### 🔹 Step 2: Initialize Min-Heap of Pairs

```cpp
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
```
* We create a min-heap that stores `pair<int, int>`.
* C++ `pair`s are compared by their first element by default. We will store pairs as `(frequency, element)`. This means the heap will naturally sort itself based on frequencies!
* `greater<pair<int, int>>` ensures it's a min-heap (smallest frequency at the top).

---

### 🔹 Step 3: Populate and Maintain the Heap

```cpp
for (auto& pair : countMap) {
    minHeap.push({pair.second, pair.first});
    
    if (minHeap.size() > k) {
        minHeap.pop();
    }
}
```
* We iterate through our `countMap`. Note that `pair.first` is the number and `pair.second` is the frequency.
* We push `{frequency, element}` into the heap.
* If the heap grows larger than `k`, we `pop()`. Since it's a min-heap sorted by frequency, this pops the element with the **lowest frequency**, keeping only the `k` highest frequencies in the heap.

---

### 🔹 Step 4: Extract Results

```cpp
vector<int> result;
while (!minHeap.empty()) {
    result.push_back(minHeap.top().second);
    minHeap.pop();
}
return result;
```
* We create a `result` vector.
* We pop everything remaining in the heap. The heap contains exactly `k` items.
* `minHeap.top().second` retrieves the original number (the second part of the pair).
* Because the problem allows any order, we just push them to the result and return.

---

# 📊 Step-by-Step Example

Input: `nums = [1,1,1,2,2,3]`, `k = 2`

**1. Hash Map Counting:**
`countMap` = `{ 1: 3,  2: 2,  3: 1 }`

**2. Max Heap of size k=2:**
- Insert `{3, 1}` (Freq 3, Num 1): Heap = `[{3,1}]`
- Insert `{2, 2}` (Freq 2, Num 2): Heap = `[{2,2}, {3,1}]`
- Insert `{1, 3}` (Freq 1, Num 3): Heap = `[{1,3}, {2,2}, {3,1}]`. Size > 2. Pop top (lowest freq).
  - Pops `{1,3}`. Heap is back to `[{2,2}, {3,1}]`.

**3. Extract Result:**
- Pop `{2,2}` -> add `2` to result.
- Pop `{3,1}` -> add `1` to result.

✅ Result = **[2, 1]** (or [1, 2], order doesn't matter).

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(N log k)**
* Building the Hash Map takes `O(N)` time.
* Iterating through the Hash Map takes `O(U)` where `U` is the number of unique elements (worst case `U = N`).
* Pushing/popping from a heap of size `k` takes `O(log k)`. Thus, the heap phase takes `O(N log k)`.
* Total time: `O(N + N log k) = O(N log k)`.

---

### 🔹 Space Complexity: **O(N)**
* The `unordered_map` takes `O(N)` space in the worst case (all elements unique).
* The `priority_queue` takes `O(k)` space.
* Total space: `O(N)`.

---

# ⭐ Key Concepts Learned
* **Combining Data Structures**: Using Hash Maps for counting, combined with Heaps for ordering.
* **C++ Pairs in Priority Queues**: Using `std::pair` inside a priority queue and understanding that they are sorted lexicographically (first element first).

---

# 🏆 Why This Problem Is Important
* Frequently asked in technical interviews as a follow-up to counting frequencies.
* Tests your ability to chain multiple concepts (hashing + heaps) together efficiently.
