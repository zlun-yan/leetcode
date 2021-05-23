//
// Created by ZlunYan on 2021/5/23.
//

#include <string>
#include <vector>
using namespace std;

class Trie {
private:
    bool isEnd;
    vector<Trie*> children;
public:
    /** Initialize your data structure here. */
    Trie(): isEnd(false), children(26) {}

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *root = this;
        for (char ch : word) {
            if (root->children[ch - 'a'] == nullptr) root->children[ch - 'a'] = new Trie();
            root = root->children[ch - 'a'];
        }
        root->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *root = this;
        for (char ch : word) {
            if (root->children[ch - 'a'] != nullptr) root = root->children[ch - 'a'];
            else return false;
        }
        return root->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *root = this;
        for (char ch : prefix) {
            if (root->children[ch - 'a'] != nullptr) root = root->children[ch - 'a'];
            else return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */