/*
 * =====================================================================================
 *
 *       Filename:    WordQuery.hpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-4-17 14:44:23
 *       Compiler:    gcc
 *       Description: TextQuery class Query
 *
 * =====================================================================================
 */
#ifndef _TEXTQUERY_WORDQUERY_H
#define _TEXTQUERY_WORDQUERY_H
#include <iostream>
#include <string>
#include "QueryBase.hpp"
using namespace std;
class WordQuery: public QueryBase
{
    friend class Query;
    WordQuery(const std::string &s):query_word(s) { }
    virtual ~WordQuery();
    std::set<line_no> eval(const TextQuery &t) const{
        return t.run_query(query_word);
    }
    std::ostream& display(std::ostream &os) const{
        return os << query_word;
    }
    std::string query_word;
};
#endif

