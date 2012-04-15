# coding=utf-8
import codecs

def main():
    file = codecs.open('''E:\zhwiki-latest-pages-articles.xml''', 'rb', 'utf-8')
    for line in file:
        print line.encode('utf8')
        pass
    pass
if __name__ == '__main__':
    main()