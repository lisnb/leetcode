#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: LiSnB
# @Date:   2015-01-06 13:14:50
# @Last Modified by:   LiSnB
# @Last Modified time: 2015-01-06 20:08:21
# @Email: lisnb.h@gmail.com

"""
# @comment here:

"""

def dp(n):
    if n==0:
        return []
    pas=[]
    pas.append(set(['()']))
    for i in range(1,n):
        tl=[]
        for j in pas[i-1]:
            tl.append('()%s'%j)
            tl.append('%s()'%j)
            tl.append('(%s)'%j)
        pas.append(set(tl))
    return list(pas[n-1])

def enum(n):
    from itertools import permutations
    rs = permutations('()'*n)
    pas = []
    t=[]
    for r in rs:
        t=[]
        for p in r:
            if p=='(':
                t.append(p)
            else:
                if len(t)==0:
                    t.append(')')
                    break
                if t[-1]=='(':
                    t.pop()
        if len(t)==0:
            pas.append(''.join(r))
    return list(set(pas)) 

def backtrack(n):
    l=[]
    _backtrack(n,l)
    return l

def _backtrack(n,l,s='(',ln=1,rn=0):
    if ln > n or rn > n:
        return 
    if ln == rn == n:
        l.append(s)
        return 
    if ln < rn:
        return
    _backtrack(n,l,s+'(',ln+1,rn)
    _backtrack(n,l,s+')',ln,rn+1)







if __name__ == '__main__':
    # print dp(6)
    print backtrack(4)







    