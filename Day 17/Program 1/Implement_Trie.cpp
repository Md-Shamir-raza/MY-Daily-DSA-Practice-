#include <iostream>
#include <string>
#include <vector>
using namespace std;

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
    Trie() {
        root = new TrieNode();
    }
    
    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - 'a';
            // If the character node doesn't exist, create it
            if (current->children[index] == nullptr) {
                current->children[index] = new TrieNode();
            }
            // Move to the next node
            current = current->children[index];
        }
        // Mark the end of the word
        current->isEndOfWord = true;
    }
    
    // Returns true if the word is in the trie.
    bool search(string word) {
        TrieNode* current = root;
        for (char c : word) {
            int index = c - 'a';
            if (current->children[index] == nullptr) {
                return false;
            }
            current = current->children[index];
        }
        return current->isEndOfWord;
    }
    
    // Returns true if there is any word in the trie that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* current = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (current->children[index] == nullptr) {
                return false;
            }
            current = current->children[index];
        }
        return true;
    }
};

int main() {
    Trie* obj = new Trie();
    
    cout << "insert('apple')" << endl;
    obj->insert("apple");
    
    cout << "search('apple') -> " << (obj->search("apple") ? "true" : "false") << endl;   // return True
    cout << "search('app') -> " << (obj->search("app") ? "true" : "false") << endl;       // return False
    cout << "startsWith('app') -> " << (obj->startsWith("app") ? "true" : "false") << endl; // return True
    
    cout << "insert('app')" << endl;
    obj->insert("app");
    
    cout << "search('app') -> " << (obj->search("app") ? "true" : "false") << endl;       // return True

    delete obj;
    return 0;
}
