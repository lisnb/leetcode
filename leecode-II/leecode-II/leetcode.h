#ifndef __LEETCODE_H_
#define __LEETCODE_H_

#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

template<typename T>
struct _leetcode_listnode{
    T val;
    _leetcode_listnode *next;
    _leetcode_listnode() :val(T()), next(nullptr){}
    _leetcode_listnode(T x) : val(x), next(nullptr){}
};

template<typename T>
void lc_printlist(_leetcode_listnode<T> *head)
{
    if (head == nullptr)
    {
        cout << "null list" << endl;
        return;
    }
    _leetcode_listnode<T> *tmp(head);
    while (tmp->next != nullptr)
    {
        cout << tmp->val << " -> ";
        tmp = tmp->next;
    }
    cout << tmp->val << endl;
}


template<typename T>
_leetcode_listnode<T> *lc_createlist(vector<T> &vals, bool print = false)
{
    if (vals.empty())
        return nullptr;
    _leetcode_listnode<T> *head = new _leetcode_listnode<T>(vals.front());
    _leetcode_listnode<T> *tmphead = head;
    for (vector<T>::iterator cval = vals.begin() + 1; cval != vals.end(); ++cval)
    {
        tmphead->next = new _leetcode_listnode<T>(*cval);
        tmphead = tmphead->next;
    }
    if (print)
        lc_printlist(head);
    return head;
}


template<typename T>
void lc_destroylist(_leetcode_listnode<T> *head)
{
    _leetcode_listnode<T> *tmp(head);
    while (head != nullptr)
    {
        tmp = head->next;
        delete head;
        head = tmp;
    }
}

template<typename T>
struct _leetcode_randomlistnode{
    T label;
    _leetcode_randomlistnode *next, *random;
    _leetcode_randomlistnode(T x) :label(x), next(nullptr), random(nullptr){};
};


template<typename T>
struct _leetcode_interval{
    T start;
    T end;
    _leetcode_interval() :start(T()), end(T()){}
    _leetcode_interval(T s, T e) :start(s), end(e){}
};


template<typename T>
struct _leetcode_treenode{
    T val;
    _leetcode_treenode *left;
    _leetcode_treenode *right;
    _leetcode_treenode() :val(T()), left(nullptr), right(nullptr){}
    _leetcode_treenode(T x) :val(x), left(nullptr), right(nullptr){}
};


template<typename T>
void lc_destroytree(_leetcode_treenode<T> *root)
{
    if (root == nullptr)
        return;
    lc_destroytree(root->left);
    lc_destroytree(root->right);
    delete root;
}





template<typename T>
void lc_serializetree( _leetcode_treenode<T> *root, vector<T> &sequence, T placeholder = T())
{
    typedef _leetcode_treenode<T> treenode;
    if (root == nullptr)
        return;
    deque<treenode *> queue;
    queue.push_back(root);
    treenode *tmp;
    int levelsize(0);
    sequence.push_back(root->val);
    while (!queue.empty())
    {
        levelsize = queue.size();
        while (levelsize-- > 0)
        {
            tmp = queue.front();
            queue.pop_front();
            if (tmp->left != nullptr)
            {
                sequence.push_back(tmp->left->val);
                queue.push_back(tmp->left);
            }
            else
                sequence.push_back(placeholder);
            if (tmp->right != nullptr)
            {
                sequence.push_back(tmp->right->val);
                queue.push_back(tmp->right);
            }
            else
                sequence.push_back(placeholder);
            --levelsize;
        }
    }
}

template<typename T>
_leetcode_treenode<T> *lc_deserializetree(vector<T> &sequence, T placeholder = T())
{
    typedef _leetcode_treenode<T> treenode;
    if (sequence.empty())
        return nullptr;
    treenode *root = new treenode(sequence.at(0));
    treenode *tmp;
    size_t index(1), levelsize(0);
    deque<treenode *> queue;
    queue.push_back(root);
    while (index < sequence.size())
    {
        levelsize = queue.size();
        while (index < sequence.size() && levelsize-- > 0)
        {
            tmp = queue.front();
            queue.pop_front();
            if (sequence.at(index) != placeholder)
            {
                tmp->left = new treenode(sequence.at(index));
                queue.push_back(tmp->left);
            }
            ++index;
            if (index < sequence.size() && sequence.at(index) != placeholder)
            {
                tmp->right = new treenode(sequence.at(index));
                queue.push_back(tmp->right);
            }
            ++index;
            --levelsize;
        }
    }
    return root;
}


#endif