#!/usr/bin/python
# -*- coding: utf-8 -*-

import pdb
from pprint import *

'''
Given a binary matrix, find the maximum size rectangle binary-sub-matrix with all 1’s.
Input :   0 1 1 0
          1 1 1 1
          1 1 1 1
          1 1 0 0
Output :  1 1 1 1
          1 1 1 1
'''

def max_rect(inp):
    max_vals = [[(0,0) for _ in range(len(inp[0]))] for _ in range(len(inp))]

    for i, x in enumerate(inp):
        for j, y in enumerate(x):
            if y == 0:
                max_vals[i][j] = (0, 0)
            else:
                row_val = 1 
                col_val = 1 

                if i:
                    row_val, r = max_vals[i-1][j]
                    row_val += 1

                if j:
                    c, col_val = max_vals[i][j-1]
                    col_val += 1

                max_vals[i][j] = (row_val, col_val)

    
    pprint(max_vals)


inp = [
        [ 0, 1, 1, 0],
        [1, 1, 1, 1],
        [1, 1, 1, 1],
        [1, 1, 0, 0]
        ]

pprint(inp)
max_rect(inp)
