
# 🥇 Kth Largest Element in an Array – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #215 – Medium)

Given an integer array `nums` and an integer `k`, return the `k`th largest element in the array.

Note that it is the `k`th largest element in the sorted order, not the `k`th distinct element.

Can you solve it without sorting?

Example:

```
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Explanation: The sorted array is [1,2,3,4,5,6]. The 2nd largest element is 5.
```

More examples:

```
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
```

---

# 🧠 Approach: Min-Heap (Priority Queue)

The key insight is:

> If we want the `k`th *largest* element, we can maintain a collection of the `k` largest elements we've seen so far.
> A **Min-Heap** is perfect for this. It keeps the *smallest* of its elements at the top. If we maintain a min-heap of size `k`, the smallest element in that heap (the top) will be exactly the `k`th largest element of the array!

### Why not just sort?
Sorting the array takes `O(N log N)` time. Using a min-heap of size `k` takes `O(N log k)` time. If `k` is small compared to `N`, this is much faster! Also, the heap approach works for streaming data where the array size is not known in advance.

*(Note: There is also an `O(N)` average-case solution using Quickselect, but the Heap approach is the most standard and practical `O(N log k)` solution).*

---

# 🧾 C++ Code

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums) {
            minHeap.push(num);
            
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 Initialize the Min-Heap

```cpp
priority_queue<int, vector<int>, greater<int>> minHeap;
```
* In C++, `priority_queue` by default is a **Max-Heap** (largest element at the top).
* To make it a **Min-Heap**, we must specify three template parameters:
  1. `int`: The type of data.
  2. `vector<int>`: The underlying container used to implement the heap.
  3. `greater<int>`: The comparator function that forces the smallest element to the top.

---

### 🔹 Iterate Through the Array

```cpp
for (int num : nums) {
    minHeap.push(num);
```
* We push every number in the array into the min-heap. The heap automatically reorganizes itself in `O(log k)` time.

---

### 🔹 Maintain Heap Size

```cpp
    if (minHeap.size() > k) {
        minHeap.pop();
    }
}
```
* If the size of the heap ever exceeds `k`, we immediately `pop()` the top element.
* Since it's a min-heap, the top element is the **smallest** element currently in the heap.
* By popping the smallest element, we ensure that the heap only ever contains the **`k` largest elements seen so far**.

---

### 🔹 Return the Result

```cpp
return minHeap.top();
```
* After iterating through all numbers, the heap contains exactly the `k` largest elements from the entire array.
* The element at the top of the min-heap is the smallest of those `k` largest elements.
* Therefore, the top element is exactly the **`k`th largest element**!

---

# 📊 Step-by-Step Example

Input: `nums = [3,2,1,5,6,4]`, `k = 2`

We want a Min-Heap of max size 2.

1. **Insert 3**: Heap = `[3]`
2. **Insert 2**: Heap = `[2, 3]` (2 is at the top)
3. **Insert 1**: Heap = `[1, 2, 3]`. Size > 2. Pop `1`. Heap = `[2, 3]`
4. **Insert 5**: Heap = `[2, 3, 5]`. Size > 2. Pop `2`. Heap = `[3, 5]`
5. **Insert 6**: Heap = `[3, 5, 6]`. Size > 2. Pop `3`. Heap = `[5, 6]`
6. **Insert 4**: Heap = `[4, 5, 6]`. Size > 2. Pop `4`. Heap = `[5, 6]`

Loop finishes.
`minHeap.top()` is `5`.

✅ Result is **5**.

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(N log k)**
* `N` is the number of elements in `nums`.
* We iterate through all `N` elements.
* For each element, pushing to and popping from a heap of size `k` takes `O(log k)` time.
* Total time is `O(N log k)`.

---

### 🔹 Space Complexity: **O(k)**
* We store at most `k` elements in the priority queue at any given time.

---

# ⭐ Key Concepts Learned
* **Priority Queues (Heaps)**: Understanding how a heap maintains partial order.
* **Min-Heap Trick**: Using a Min-Heap to find the "Top K Largest" items (and conversely, a Max-Heap for "Top K Smallest").
* **C++ STL**: How to override the default Max-Heap in C++ to create a Min-Heap using `greater<int>`.

---

# 🏆 Why This Problem Is Important
* Very common interview question (Facebook/Meta asks this constantly).
* Tests knowledge of Heaps, which are critical for scheduling algorithms and stream processing.
