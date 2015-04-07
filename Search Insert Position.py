#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: LiSnB
# @Date:   2014-10-23 20:40:29
# @Last Modified by:   LiSnB
# @Last Modified time: 2014-10-23 21:32:08
# @Email: lisnb.h@gmail.com

"""
# @comment here:

"""
class Solution:
    # @param A, a list of integers
    # @param target, an integer to be inserted
    # @return integer
    def searchInsert(self, A, target):
        pivot,b,e= len(A)/2,0,len(A)-1
        while(b<=e):
            print b,pivot,e,A[pivot]
            if target == A[pivot]:
                return pivot
            elif target < A[pivot]:
                e = pivot-1
                if e<b:
                    e+=1
                    break
                pivot = (b+e)/2
            else:
                b = pivot+1
                if e<b:
                    b-=1
                    break
                pivot = (b+e)/2
        
        print b,pivot,e,A[pivot]
        return b if target<A[b] else e+1





if __name__ == '__main__':
    s = Solution()

    print s.searchInsert([1,2,4,8,9],6)







