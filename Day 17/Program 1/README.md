
# 🌳 Implement Trie (Prefix Tree) – Line by Line Explanation (C++)

## 📌 Problem Statement (LeetCode #208 – Medium)

A **trie** (pronounced as "try") or **prefix tree** is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the `Trie` class:
* `Trie()` Initializes the trie object.
* `void insert(String word)` Inserts the string `word` into the trie.
* `boolean search(String word)` Returns `true` if the string `word` is in the trie (i.e., was inserted before), and `false` otherwise.
* `boolean startsWith(String prefix)` Returns `true` if there is a previously inserted string `word` that has the prefix `prefix`, and `false` otherwise.

---

# 🧠 Approach: Tree Node with Array

The key insight is:

> A Trie is essentially a tree where each node represents a character.
> Since words consist of lowercase English letters, each node can have up to 26 children. We can represent these children using an array of pointers of size 26.
> We also need a boolean flag `isEndOfWord` to distinguish between a word that was explicitly inserted (e.g., "app") and a word that just exists as a prefix to another word (e.g., "apple").

---

# 🧾 C++ Code

```cpp
class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() { root = new TrieNode(); }
    
    void insert(string word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - 'a';
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - 'a';
            if (current->children[index] == nullptr) return false;
            current = current->children[index];
        }
        return current->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* current = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (current->children[index] == nullptr) return false;
            current = current->children[index];
        }
        return true;
    }
};
```

---

# 🔍 Line-by-Line Explanation

---

### 🔹 The TrieNode Class

```cpp
class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;
    // ... constructor initializes all to nullptr
};
```
* Every node has a `children` array of size 26. Index 0 corresponds to 'a', index 1 to 'b', etc.
* If `children[0]` is not null, it means the letter 'a' is the next character in some word.

---

### 🔹 Insert Method

```cpp
TrieNode* current = root;
for (char c : word) {
    int index = c - 'a';
    if (current->children[index] == nullptr) {
        current->children[index] = new TrieNode();
    }
    current = current->children[index];
}
current->isEndOfWord = true;
```
* We start at the `root`.
* For every character, we calculate its index (`c - 'a'`).
* If that path doesn't exist (`nullptr`), we create a new node.
* We move `current` down to that child node.
* Once the loop finishes, we are at the node representing the final character. We set `isEndOfWord = true`.

---

### 🔹 Search & StartsWith

Both methods traverse the tree exactly like `insert`, but instead of creating nodes, they return `false` if they hit a `nullptr` (meaning the path doesn't exist).
The only difference is the return statement:
* `search`: Returns `current->isEndOfWord` (it must be a complete word, not just a prefix).
* `startsWith`: Returns `true` (if we traversed the whole prefix without hitting null, the prefix exists).

---

# ⏱️ Complexity Analysis

### 🔹 Time Complexity: **O(L)**
* Where `L` is the length of the word. Insert, search, and startsWith all run in `O(L)` time.

### 🔹 Space Complexity: **O(N × L × 26)**
* Where `N` is the number of words. The Trie takes considerable space because of the fixed size 26 array in every node.
