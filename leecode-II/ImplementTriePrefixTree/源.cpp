#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode():wordcnt(0), isend(0) {
        childs = new TrieNode*[26];
        for (auto i = 0; i < 26; ++i)
            childs[i] = nullptr;
    }

    char character;
    int wordcnt;
    bool isend;
    TrieNode **childs;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    ~Trie()
    {
        deletetree(root);
    }

    void deletetree(TrieNode *node)
    {
        if (root == nullptr)
            return;
        for (auto i = 0; i < 26;++i)
        {
            if (node->childs[i] != nullptr)
                deletetree(node->childs[i]);
        }
        delete[]node->childs;
        delete node;
    }

    // Inserts a word into the trie.
    void insert(string word) {
        if (word.empty())
            return;
        auto tmp = root;
        int index(-1);
        for (auto ch : word)
        {
            index = ch - 'a';
            if (tmp->childs[index] == nullptr)
                tmp->childs[index] = new TrieNode();
            tmp->childs[index]->wordcnt++;
            tmp = tmp->childs[index];
        }
        tmp->isend = true;
        
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        if (word.empty())
            return false;
        auto tmp = root;
        int index(-1);
        for (auto ch : word)
        {
            index = ch - 'a';
            if (tmp->childs[index] == nullptr)
                return false;
            tmp = tmp->childs[index];
        }
        return tmp->isend;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        if (prefix.empty())
            return false;
        auto tmp = root;
        int index(-1);
        for (auto ch : prefix)
        {
            index = ch - 'a';
            if (tmp->childs[index] == nullptr)
                return false;
            tmp = tmp->childs[index];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");



int main()
{
    Trie trie;
    trie.insert("something");
    trie.insert("someone");
    trie.insert("somebody");
    cout << trie.search("someone") << endl;
    cout << trie.search("somewhere") << endl;
    cout << trie.startsWith("some") << endl;
    cout << trie.startsWith("s") << endl;
    cout << trie.startsWith("someh") << endl;
    system("pause");
    return 0;
}