/*
实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。

示例:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // 返回 true
trie.search("app");     // 返回 false
trie.startsWith("app"); // 返回 true
trie.insert("app");   
trie.search("app");     // 返回 true
说明:

你可以假设所有的输入都是由小写字母 a-z 构成的。
保证所有输入均为非空字符串。

*/

class TrieNode {
    public:
    TrieNode* child[26];
    bool isWord;
    TrieNode() : isWord(false) {
        for(auto &a : child) a = NULL;
    }
};

class Trie {
    private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root;
        for(auto &a : word) {
            int i = a - 'a';
            if(!p->child[i]) {
                p->child[i] = new TrieNode();
                
            }
            p = p->child[i];
            
        }
        p->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = root;
        for(auto &a : word) {
            int i = a - 'a';
            if(!p->child[i]) {
                return false;
            }
            p = p->child[i];
        }
        return p->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for(auto &a : prefix) {
            int i = a - 'a';
            if(!p->child[i]) {
                return false;
            }
            p = p->child[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
