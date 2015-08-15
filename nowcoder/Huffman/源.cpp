#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <map>
#include <string>

using namespace std;

template<typename T>
struct _nc_huffman_node
{
    T key;
    _nc_huffman_node *left, *right;
    _nc_huffman_node(T key) :key(key),left(nullptr), right(nullptr){}
};

typedef _nc_huffman_node<char> HuffmanNode;


template<typename T>
struct _cmp_huffman
{
    bool operator ()(const T &lh, const T&rh) const
    {
        return lh.first > rh.first;
    }
};

typedef pair<int, char> item;
typedef pair<int, HuffmanNode*> witem;
typedef vector<item> vitems;
typedef priority_queue<witem, vector<witem>, _cmp_huffman<witem>> huffheap; \
typedef pair<char, string> huffmancode;

witem buildhuffman(vitems &items)
{
    huffheap heap;
    for (auto item : items)
    {
        auto tnode = new HuffmanNode(item.second);
        heap.push(make_pair(item.first, tnode));
    }
    for (auto i = 0; i + 1 < items.size(); ++i)
    {
        auto lh = heap.top();
        heap.pop();
        auto rh = heap.top();
        heap.pop();
        auto tnode = new HuffmanNode('\0');
        tnode->left = lh.second;
        tnode->right = rh.second;
        heap.push(make_pair(lh.first + rh.first, tnode));
    }
    return heap.top();
}


void dfsbacktrack(vector<huffmancode> &encoding, string &prefix, HuffmanNode *root)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        encoding.push_back(make_pair(root->key, prefix));
        return;
    }
    if (root->left != nullptr)
    {
        prefix.push_back('0');
        dfsbacktrack(encoding, prefix, root->left);
        prefix.pop_back();
    }
    if (root->right != nullptr)
    {
        prefix.push_back('1');
        dfsbacktrack(encoding, prefix, root->right);
        prefix.pop_back();
    }
}

void huffmanencode(vitems &items, vector<huffmancode> &encoding)
{
    auto huffmantree = buildhuffman(items);
    if (huffmantree.second == nullptr)
        return;
    else
    {
        string prefix("");
        dfsbacktrack(encoding, prefix, huffmantree.second);
    }

}



int main()
{
    vector<item> test = { { 2, 'F' }, { 3, 'O' }, { 4, 'R' }, { 4, 'G' }, { 5, 'E' }, { 7, 'T' } };
    vector<huffmancode> encoding;
    encoding.reserve(test.size());
    huffmanencode(test, encoding);
    for (auto encode : encoding)
    {
        cout << encode.first << " " << encode.second << endl;
    }
    string A("abc"), B("cb");
    cout << *find_first_of(A.begin(), A.end(), B.begin(), B.end()) << endl;
    system("pause");
    return 0;
}


