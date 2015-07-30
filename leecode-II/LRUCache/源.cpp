#include "../leecode-II/leetcode.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>


using namespace std;




/*
template<typename T>
struct _leetcode_listnode{
    T val;
    _leetcode_listnode *next;
    _leetcode_listnode() :val(T()), next(nullptr){}
    _leetcode_listnode(T x) : val(x), next(nullptr){}
};
typedef _leetcode_listnode<pair<int, int>> ListNode;

class LRUCacheTLE{
public:
    LRUCacheTLE(int capacity) {
        _capacity = capacity;
        _size = 0;
        _head = new ListNode();
    }

    ~LRUCacheTLE()
    {
        auto t(this->_head), tt(this->_head);
        while (t != nullptr)
        {
            tt = t->next;
            delete t;
            t = tt;
        }
    }
    int get(int key) {
        if (_size <= 0)
            return -1;
        auto node = _search(key);
        if (node->next->val.first == key)
        {
            _move(node);
            return _head->next->val.second;
        }
        return - 1;
        
    }
    void set(int key, int value) {
        auto node = this->_search(key);
        if (node == _head || node->next->val.first != key)
        {
            
            auto t = new ListNode(make_pair(key, value));
            t->next = _head->next;
            _head->next = t;
            if (_size<_capacity)
                ++_size;
            return;
        }
        node->next->val.second = value;
        _move(node);
    }
private:
    ListNode *_search(int key)
    {
        int tpos(1);
        auto t(this->_head);
        while (t->next != nullptr && tpos++ < this->_size)
        {
            if (t->next->val.first == key)
                break;
            t = t->next;
        }
        return t;
    }

    void _move(ListNode *node)
    {
        auto t = node->next;
        node->next = t->next;
        t->next = _head->next;
        _head->next = t;
    }

    
private:
    int _size;
    int _capacity;
    ListNode *_head;
};


*/


class LRUCache{
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end())
            return -1;
        update(it);
        return cache[key].first;
    }

    void set(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end())
            update(it);
        else
        {
            if (cache.size() == _capacity)
            {
                cache.erase(data.back());
                data.pop_back();
            }
            data.push_front(key);
        }
        cache[key] = { value, data.begin() };
    }
private:
    int _capacity;
    list<int> data;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    void update(unordered_map<int, pair<int, list<int>::iterator>>::iterator it)
    {
        int key = it->first;
        data.erase(it->second.second);
        data.push_front(key);
        it->second.second = data.begin();
    }
};



int main()
{
    LRUCache lru(3);
    cout << lru.get(1) << endl;
    lru.set(1, 10);
    cout << lru.get(1) << endl;
    lru.set(2, 20);
    cout << lru.get(2) << endl;
    cout << lru.get(1) << endl;
    lru.set(3, 30);
    cout << lru.get(3) << endl;
    cout << lru.get(2) << endl;
    lru.set(4, 40);
    cout << lru.get(1) << endl;
    cout << lru.get(2) << endl;
    cout << lru.get(3) << endl;
    cout << lru.get(4) << endl;
    lru.set(5, 50);
    lru.set(6, 60);
    cout << lru.get(1) << endl;
    cout << lru.get(2) << endl;
    cout << lru.get(3) << endl;
    cout << lru.get(4) << endl;
    cout << lru.get(5) << endl;
    cout << lru.get(6) << endl;
    system("pause");
    return 0;
    
}