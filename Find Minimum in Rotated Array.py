#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: LiSnB
# @Date:   2015-01-09 11:01:40
# @Last Modified by:   LiSnB
# @Last Modified time: 2015-01-09 11:21:54
# @Email: lisnb.h@gmail.com

"""
# @comment here:

"""

class Solution:
    # @param num, a list of integer
    # @return an integer
    def findMin(self, num):
        print num
        if not len(num):
            return None
        l = len(num)
        if l<=2:
            return min(num)
        pivot = l/2
        print pivot
        if num[0]<num[-1]:
            return num[0]
        if num[pivot]<num[pivot-1] and num[pivot]<num[pivot+1]:
            return num[pivot]
        # if num[0]<num[pivot-1] and num[pivot+1]<num[-1]:
        #     return num[pivot] if num[pivot]<num[pivot+1] else num[pivot+1]
        else:
            if num[0]>num[pivot-1]:
                return self.findMin(num[0:pivot])
            else:
                return self.findMin(num[pivot+1:])
        
    



if __name__ == '__main__':
    s=Solution()
    num = [3,3,3,3,3,3,4,4,4,4,4,4,6,6,6,6,6,6,6,6,1,1,1,1,2]
    num2 = [0,0,0]
    print s.findMin(num2)






	