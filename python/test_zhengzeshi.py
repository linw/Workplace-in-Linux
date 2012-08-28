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
    p = re.compile('''{{infobox [\s\S]* }}''')
    m = p.search('''asdsad{{infobox sldfjsld
        sdjflsdjfl
        sdfjlsdjflsjdf
        sdjflsjdflsjdf
        fsldjfl}}sdf
        }}''')
    print m.group()
    p = re.compile('''(?:\(?(?:[\w]+|\(?)\+(?:[\w]+|\)?)\)?)+''') 
    m = p.search('''sjdfl(a+(a+(a+b))+c)skjdjf''')
    print m.group()
    pass

if __name__ == '__main__':
    main()