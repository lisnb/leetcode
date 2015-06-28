#ifndef __LEETCODE_H_
#define __LEETCODE_H_

#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
struct _leetcode_listnode{
    T val;
    _leetcode_listnode *next;
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
_leetcode_listnode<T> *lc_createlist(vector<T> &vals, bool print=false)
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
    while (head!=nullptr)
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

#endif