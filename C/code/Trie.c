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

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEnd;
} TrieNode;

typedef struct {
    TrieNode* root;
} Trie;

TrieNode* createTrieNode() {
    TrieNode* newNode = (TrieNode*)malloc(sizeof(TrieNode));
    if (newNode) {
        newNode->isEnd = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            newNode->children[i] = NULL;
        }
    }
    return newNode;
}

Trie* trieCreate() {
    Trie* trie = (Trie*)malloc(sizeof(Trie));
    if (trie) {
        trie->root = createTrieNode();
    }
    return trie;
}

void trieInsert(Trie* obj, char* word) {
    TrieNode* node = obj->root;
    while (*word) {
        int index = *word - 'a';
        if (!node->children[index]) {
            node->children[index] = createTrieNode();
        }
        node = node->children[index];
        word++;
    }
    node->isEnd = true;
}

bool trieSearch(Trie* obj, char* word) {
    TrieNode* node = obj->root;
    while (*word) {
        int index = *word - 'a';
        if (!node->children[index]) {
            return false;
        }
        node = node->children[index];
        word++;
    }
    return node->isEnd;
}

bool trieStartsWith(Trie* obj, char* prefix) {
    TrieNode* node = obj->root;
    while (*prefix) {
        int index = *prefix - 'a';
        if (!node->children[index]) {
            return false;
        }
        node = node->children[index];
        prefix++;
    }
    return true;
}

void freeTrieNode(TrieNode* node) {
    if (!node) {
        return;
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            freeTrieNode(node->children[i]);
        }
    }
    free(node);
}

void trieFree(Trie* obj) {
    if (obj) {
        freeTrieNode(obj->root);
        free(obj);
    }
}



int main() {
    Trie* obj = trieCreate();

    // Insert words
    trieInsert(obj, "apple");
    trieInsert(obj, "app");

    // Search for words
    bool search1 = trieSearch(obj, "apple");   // Should return true
    bool search2 = trieSearch(obj, "app");     // Should return true
    bool search3 = trieSearch(obj, "ap");      // Should return false
    bool search4 = trieSearch(obj, "application"); // Should return false

    // Check for prefixes
    bool startsWith1 = trieStartsWith(obj, "app");  // Should return true
    bool startsWith2 = trieStartsWith(obj, "ap");   // Should return true
    bool startsWith3 = trieStartsWith(obj, "banana"); // Should return false

    printf("Search 'apple': %d\n", search1);
    printf("Search 'app': %d\n", search2);
    printf("Search 'ap': %d\n", search3);
    printf("Search 'application': %d\n", search4);
    printf("StartsWith 'app': %d\n", startsWith1);
    printf("StartsWith 'ap': %d\n", startsWith2);
    printf("StartsWith 'banana': %d\n", startsWith3);

    trieFree(obj);

    return 0;
}
