/*
 * =====================================================================================
 *
 *       Filename:    OrQuery.hpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-4-19 15:53:30
 *       Compiler:    gcc
 *       Description: TextQuery class AndQuery
 *
 * =====================================================================================
 */
#ifndef _TEXTQUERY_ORQUERY_H
#define _TEXTQUERY_ORQUERY_H
class OrQuery:public BinaryQuery{
    friend Query operator|(const Query&, const Query&);
    OrQuery(Query left, Query right):
            BinaryQuery(left, right, "|") { }
    std::set<line_no> eval(const TextQuery&) const;
};
#endif