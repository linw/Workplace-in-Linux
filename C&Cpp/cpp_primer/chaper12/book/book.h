/*
 * =====================================================================================
 *
 *
 *       Filename:    book.h
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2011年12月31日 13时04分03秒
 *       Compiler:    gcc
 *       Description: A book class
 *
 * =====================================================================================
 */
#ifndef CPP_PRIMER_CHAPER12_BOOK_H_
#define CPP_PRIMER_CHAPER12_BOOK_H_
#include <string>
class Book{
public:
  std::string name;
  std::string author;
  std::string isbn;
  std::string publisher;
  Book();
  Book(std::string _name, std::string _author, std::string _isbn, std::string publisher);
  Book(std::string _name);
  Book(std::istream _is);
  virtual ~Book();
}
#endif
