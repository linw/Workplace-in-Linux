#!/usr/bin/python
# -*- coding: utf-8 -*-

'''
#=============================================================================
#
#     FileName: test.py
#         Desc: 
#
#       Author: lin wei<kinglw8729@gmail.com>
#
#      Created: 2012年3月20日10:11:11
#      Version: 
#      History:
#
#=============================================================================
'''
print "linv"
raw_input("Press Enter to Exit!")
#print i
# reload(this)
import this
reload(this)
L = [1,2]
L.append(L)
print L
import math
print math.pi
import random
print random.random()*100%100
print random.random()