#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: LiSnB
# @Date:   2014-10-23 21:33:47
# @Last Modified by:   LiSnB
# @Last Modified time: 2014-10-23 21:37:03
# @Email: lisnb.h@gmail.com

"""
# @comment here:

"""

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @return a ListNode
    def deleteDuplicates(self, head):
        t = head
        while t:
            if t.next:
                if t.next.val == t.val:
                    t.next = t.next.next
                else:
                    t = t.next

    def show(self,head):
        t = head
        while t:
            print t.val
            t = t.next




if __name__ == '__main__':
	k = [1,1,2,3,3]
    head = ListNode(0)
    t = head
    for i in k:
        t.next = ListNode(i)
        t = t.next
    









	