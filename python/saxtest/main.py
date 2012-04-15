# coding=utf-8
import sys, string
from xml.sax import handler, make_parser
import codecs
import re

class TestHandler(handler.ContentHandler):             
    def __init__(self): 
        self.__upTag = ''
        self.__ispage = False  
        self.__outFile = open("D:\data_text.dat","wb")
        self.__text = ''
        self.__comp = re.compile('''{{infobox [\s\S]* }}''')
        pass
        
    def startDocument(self):      
        print "Document Start ...",
        
    def endDocument(self):         
        print "Document End ...",
        
    def startElement(self, name, attrs): 
#        print 'start tag:', name
        if name == 'text':
            self.__ispage = True
            self.__text = ''
 
        
    def endElement(self, name):
#        print 'end tag:', name   
        if name == 'text' and self.__ispage == True:
            self.__ispage = False
            text = self.__comp.search(self.__text)

            depth = 1
            # print depth
            _text = '{{'
            if text is not None:
                bs = ''
                text = text.group().encode('utf8')
                # for s in text:
                #     print s
                for s in text[2::]:
                    # print s.encode('utf8'),
                    # print bs
                    # print s
                    # print 'in'
                    _text = _text + s
                    if s == '{' and bs == '{':
                        depth = depth + 1
                        # print 'hello'
                    if s == '}' and bs == '}':
                        depth = depth - 1
                        # print 'not hello'
                    if depth <= 0:
                        break
                    bs = s
                _text = _text + '\n'
                # print _text
                # print _text.encode('utf8')
                # if _text is not None:
                # print _text.encode('utf8')
                self.__outFile.write(_text)

    def characters(self, chrs):
        if self.__ispage:
            self.__text = self.__text + chrs
            # self.__outFile.write(chrs.encode('utf8'))

        
   
def test():   
    handler = TestHandler()
    parser = make_parser()
    parser.setContentHandler(handler)
    f = open(sys.argv[1], 'r')    
    parser.parse(f)    
    f.close()
   
if __name__ == '__main__':
    # test()
    from timeit import Timer
    t1 = Timer("test()","from __main__ import test")
    print t1.timeit(1)