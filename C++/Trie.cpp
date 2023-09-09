/* A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
 

Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, search, and startsWith.
 */



#include <iostream>
#include <unordered_map>

class TrieNode {
public:
    bool isEndOfWord;
    std::unordered_map<char, TrieNode*> children;

    TrieNode() : isEndOfWord(false) {}
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const std::string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (!current->children[ch]) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }

    bool search(const std::string& word) {
        TrieNode* node = findWordNode(word);
        return node != nullptr && node->isEndOfWord;
    }

    bool startsWith(const std::string& prefix) {
        TrieNode* node = findWordNode(prefix);
        return node != nullptr;
    }

    ~Trie() {
        deleteTrie(root);
    }

private:
    TrieNode* root;

    TrieNode* findWordNode(const std::string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (!current->children[ch]) {
                return nullptr;
            }
            current = current->children[ch];
        }
        return current;
    }

    void deleteTrie(TrieNode* node) {
        if (!node) return;
        for (auto& pair : node->children) {
            deleteTrie(pair.second);
        }
        delete node;
    }
};

int main() {
    Trie* trie = new Trie();

    // Insert words into the Trie
    trie->insert("apple");
    trie->insert("app");

    // Search for words
    bool search1 = trie->search("apple");   // Should return true
    bool search2 = trie->search("app");     // Should return true
    bool search3 = trie->search("ap");      // Should return false
    bool search4 = trie->search("application"); // Should return false

    // Check for prefixes
    bool startsWith1 = trie->startsWith("app");  // Should return true
    bool startsWith2 = trie->startsWith("ap");   // Should return true
    bool startsWith3 = trie->startsWith("banana"); // Should return false

    // Print the results
    std::cout << "Search 'apple': " << search1 << std::endl;
    std::cout << "Search 'app': " << search2 << std::endl;
    std::cout << "Search 'ap': " << search3 << std::endl;
    std::cout << "Search 'application': " << search4 << std::endl;
    std::cout << "StartsWith 'app': " << startsWith1 << std::endl;
    std::cout << "StartsWith 'ap': " << startsWith2 << std::endl;
    std::cout << "StartsWith 'banana': " << startsWith3 << std::endl;

    // Clean up
    delete trie;

    return 0;
}
