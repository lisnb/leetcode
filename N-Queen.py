#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: LiSnB
# @Date:   2015-02-06 09:50:16
# @Last Modified by:   LiSnB
# @Last Modified time: 2015-02-06 09:51:48
# @Email: lisnb.h@gmail.com

"""
# @comment here:

"""

class NQueen(object):
    """docstring for NQueen"""
    def __init__(self, n):
        super(NQueen, self).__init__()
        self.n = n
        self.chessboard = [[0]*n for x in range(n)]

    



if __name__ == '__main__':
    nqueen = NQueen(10)
    print nqueen.chessboard







    