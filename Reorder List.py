# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @return nothing
    def reorderList(self, head):
        if not head or not head.next or not head.next.next:
            return head 
        i = head.next
        while i.next.next:
            i = i.next
        i.next.next = head.next
        head.next = i.next
        i.next = None 
        # return head 
    def reorderList2(self,head):
        if not head or not head.next or not head.next.next:
            return head 
        mid = self.findMid(head)
        head2 = mid.next
        mid.next = None 
        head2 = self.reverseList(head2)
        self.merge(head,head2)

    def merge(self,head1,head2):

        head = head1
        p1 = head1.next
        p2 = head2
        while p2:
            head.next = p2
            p2 = p1
            head = head.next
            p1=head.next 
        return head1

        # p1 = head2
        # p2 = head1.next 
        # while p1 or p2:
        #     if p1:
        #         head.next = p1
        #         p1=p1.next
        #         head=head.next
        #     if p2:
        #         head.next = p2
        #         p2=p2.next
        #         head=head.next
        # return head1

    def findMid(self,head):
        if not head or not head.next or not head.next.next:
            return head 
        i = head 
        j = head 
        while j.next and j.next.next:
            j = j.next.next
            i = i.next
        return i 
    def reverseList(self,head):
        if not head:
            return head 
        j =  head.next 
        head.next = None
        while j:
            t = j.next
            j.next = head 
            head = j
            j =t 
        return head 

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
        a=range(8)
        s = Solution()
        head = s.createList(a)
        # s.reorderList(head)
        # head = s.reverseList(head)
        # head = s.findMid(head)
        s.reorderList2(head)
        s.printList(head)  