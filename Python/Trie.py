'''A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

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
'''


class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end_of_word = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.is_end_of_word = True

    def search(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                return False
            node = node.children[char]
        return node.is_end_of_word

    def startsWith(self, prefix):
        node = self.root
        for char in prefix:
            if char not in node.children:
                return False
            node = node.children[char]
        return True

# Example usage:
# trie = Trie()
# trie.insert("apple")
# search_result = trie.search("apple")  # Should return True
# starts_with_result = trie.startsWith("app")  # Should return True


# Create a Trie object
trie = Trie()

# Insert words into the Trie
trie.insert("apple")
trie.insert("app")

# Search for words
search1 = trie.search("apple")   # Should return True
search2 = trie.search("app")     # Should return True
search3 = trie.search("ap")      # Should return False
search4 = trie.search("application") # Should return False

# Check for prefixes
startsWith1 = trie.startsWith("app")  # Should return True
startsWith2 = trie.startsWith("ap")   # Should return True
startsWith3 = trie.startsWith("banana") # Should return False

print("Search 'apple':", search1)
print("Search 'app':", search2)
print("Search 'ap':", search3)
print("Search 'application':", search4)
print("StartsWith 'app':", startsWith1)
print("StartsWith 'ap':", startsWith2)
print("StartsWith 'banana':", startsWith3)
