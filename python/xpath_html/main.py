# coding:utf-8
'''
2012-6-7 15:12:43
linwei
'''

import xpath
import sys
import os
import urllib2
import xpath
import xml.dom.minidom
import libxml2dom
reload(sys)
sys.setdefaultencoding('utf-8')
'''
Fetch the target html  
返回一个uncode编码的页面
'''
def gethtml(url,encode_format):
    #如果没有设置编码模式，则默认为utf-8编码
    if not (type(encode_format) is type('') and len(encode_format) > 0) :
        encode_format = 'utf-8'
    #  req = urllib2.Request(url)u
    res = urllib2.urlopen(url)
    return res.read().decode(encode_format)

def get_the_thing_i_need(html_str):
#    html_str1 = '''<root><a1>skdjfsl</a1><a2>skdjflsjdf</a2><div class="box-left"><h3>skdjflsdfj</h3></div></root>'''
    # try:
    #     my_xml = xml.dom.minidom.parseString(html_str)
       
    # except Error:
    #     print "error in get the thing i nedd"
    #     return []
    my_xml = libxml2dom.parseString(html_str,html=1)
    return my_xml.xpath('''/div''',my_xml)
  #  return xpath.find('''/div''',my_xml)



if __name__ == '__main__':
    print 'hello'
    f = open('a.dat','w')
#    s = '''http://juetuzhi.net/'''
    s = '''http://www.juetuzhi.net'''
    print get_the_thing_i_need(gethtml(s,'utf-8'))
    # try:
    #     f.write(get_the_thing_i_need(gethtml(s,'big5')))
    # except xml.parsers.expat.ExpatError:
    #     print "error"
    # finally:
    #     f.close()
