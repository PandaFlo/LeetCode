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


 class TrieNode {
    TrieNode[] children;
    boolean isEnd;
    
    public TrieNode() {
        children = new TrieNode[26];
        isEnd = false;
    }
}

class TrieN {
    private TrieNode root;
    
    public TrieN() {
        root = new TrieNode();
    }
    
    public void insert(String word) {
        TrieNode node = root;
        for (char ch : word.toCharArray()) {
            if (node.children[ch - 'a'] == null) {
                node.children[ch - 'a'] = new TrieNode();
            }
            node = node.children[ch - 'a'];
        }
        node.isEnd = true;
    }
    
    public boolean search(String word) {
        TrieNode node = root;
        for (char ch : word.toCharArray()) {
            if (node.children[ch - 'a'] == null) {
                return false;
            }
            node = node.children[ch - 'a'];
        }
        return node.isEnd;
    }
    
    public boolean startsWith(String prefix) {
        TrieNode node = root;
        for (char ch : prefix.toCharArray()) {
            if (node.children[ch - 'a'] == null) {
                return false;
            }
            node = node.children[ch - 'a'];
        }
        return true;
    }
}


public class Trie {
    public static void main(String[] args) {
        TrieN trie = new TrieN();

        // Insert words
        trie.insert("apple");
        trie.insert("app");

        // Search for words
        boolean search1 = trie.search("apple");   // Should return true
        boolean search2 = trie.search("app");     // Should return true
        boolean search3 = trie.search("ap");      // Should return false
        boolean search4 = trie.search("application"); // Should return false

        // Check for prefixes
        boolean startsWith1 = trie.startsWith("app");  // Should return true
        boolean startsWith2 = trie.startsWith("ap");   // Should return true
        boolean startsWith3 = trie.startsWith("banana"); // Should return false

        System.out.println("Search 'apple': " + search1);
        System.out.println("Search 'app': " + search2);
        System.out.println("Search 'ap': " + search3);
        System.out.println("Search 'application': " + search4);
        System.out.println("StartsWith 'app': " + startsWith1);
        System.out.println("StartsWith 'ap': " + startsWith2);
        System.out.println("StartsWith 'banana': " + startsWith3);
    }
}
