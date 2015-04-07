#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: LiSnB
# @Date:   2015-01-15 19:57:21
# @Last Modified by:   LiSnB
# @Last Modified time: 2015-01-20 09:07:49
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
    def sortList(self, head):
        if not head:
            return None
        if not head.next:
            return head
        self.sortlist(head,None)
        return head

    def sortlist(self,head,tail):
        if not head or not head.next or head == tail:
            return 
        pivot=head.val 
        nh = head 
        j = head.next 
        while j!=tail:
            if j.val < pivot:
                nh.val,j.val = j.val, nh.val 
                nh=nh.next
            j = j.next 
        
        if nh == head:
            # self.sortlist(head->next,nh)
            self.sortlist(nh.next,tail)            
        else:
            self.sortlist(head,nh)
            self.sortlist(nh,tail)
            
    def getmid(self,head):
        p = head
        q = head
        while q:
            if q.next:
                q=q.next
            else:
                break
            p = p.next
            q = q.next
        return p

    def merge(self,head1,head2):
        if not head1:
            return head2
        if not head2:
            return head1
        head = None
        p1 = head1
        p2 = head2
        if head1.val < head2.val:
            head = head1
            p1 = p1.next
        else:
            head = head2
            p2 = p2.next
        t = head
        while p1 and p2:
            if p1.val < p2.val:
                t.next = p1
                p1 = p1.next
            else:
                t.next = p2
                p2 = p2.next
            t=t.next
        if not p1:
            t.next = p2
        if not p2:
            t.next = p1
        return head 

    def mergesort(self,head):
        self.printList(head)
        if not head or not head.next:
            return head
        if not head.next.next:
            if head.val > head.next.val:
                head.val ,head.next.val = head.next.val , head.val 
            return head 
        midpre = self.getmid(head)
        mid = midpre.next
        midpre.next = None
        head1 = self.mergesort(head)
        head2 = self.mergesort(mid)
        return self.merge(head1,head2)






    def printList(self,head):
        vals=[]
        t = head
        while t:
            vals.append(t.val)
            t = t.next
        print len(vals),':','->'.join([str(x) for x in vals])
    def createList(self,array):
        head = ListNode(array[0])
        t = head 
        for a in array[1:]:
            t.next = ListNode(a)
            t = t.next
        # self.printList(head)
        return head 


        



if __name__ == '__main__':
    # array = [4,1,5,2,8,3,9,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2]
    array = [1,2,1]
    s = Solution()
    head = s.createList(array)
    s.printList(head)
    head = s.mergesort(head)
    s.printList(head)








    