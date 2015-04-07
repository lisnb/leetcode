# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param a ListNode
    # @return a ListNode
    def swapPairs(self, head):
        if not head or not head.next:
            return head
        nhead = ListNode(-1)
        nhead.next = head 
        i = nhead
        j = nhead.next 
        while j and j.next:
            t = j.next.next 
            j.next.next = j 
            i.next = j.next
            j.next = t
            i = i.next.next
            j = i.next 
        return nhead.next 

    
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
        a=range(1,5)
        s = Solution()
        head = s.createList(a)
        # s.reorderList(head)
        # head = s.reverseList(head)
        # head = s.findMid(head)
        # s.reorderList2(head)
        head = s.swapPairs(head)
        s.printList(head)  