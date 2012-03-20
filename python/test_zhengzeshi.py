#!/usr/bin/python
# -*- coding: utf-8 -*-

'''
#=============================================================================
#
#     FileName: test_zhengzeshi.py
#         Desc: 
#
#       Author: lin wei<kinglw8729@gmail.com>
#
#      Created: 2012年3月20日11:00:10
#      Version: 
#      History:
#
#=============================================================================
'''

def main():
    import re
    match = re.match('Hello[ \t]*(.*)world (.*)', 'Hello     Python python world python')
    print match.groups()
    m = [1,2,3,4,6,5,9]
    m.sort()
    m.reverse()
    print m
    pass

if __name__ == '__main__':
    main()