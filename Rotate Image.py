#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: LiSnB
# @Date:   2015-01-07 09:06:40
# @Last Modified by:   LiSnB
# @Last Modified time: 2015-01-09 09:22:40
# @Email: lisnb.h@gmail.com

"""
# @comment here:

"""

class Solution:
    # @param matrix, a list of lists of integers
    # @return a list of lists of integers
    def rotate(self, matrix):
        if not matrix:
            return None
        n = len(matrix)
        if n<=1:
            return matrix
        
        m = n/2 if n%2==0 else n/2+1
        
        i = 0
        r=[0,1,2]
        while i<m:
            j=0
            while j<n-2*i-1:
                x,y = i+j,i
                t = matrix[x][y]
                for k in r:
                    xx,yy = n-1-y,x
                    matrix[x][y]=matrix[xx][yy]
                    x,y=xx,yy
                matrix[x][y]=t
                j+=1
            i+=1
        return matrix
        


if __name__ == '__main__':
    # matrix=[
    # 	[1,2,3,4],
    # 	[5,6,7,8],
    # 	[9,10,11,12],
    # 	[13,14,15,16]
    # ]

    n = 5
    matrix = []
    k=0
    for i in range(n):
    	tl = range(k,n+k)[::]
    	print tl
    	matrix.append(tl)
    	k+=n


    s=Solution()

    # print  s.rotate(matrix)
    m2 = s.rotate(matrix)

    for i in m2:
    	print i 







    