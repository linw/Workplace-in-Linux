/*
 * =====================================================================================
 *
 *       Filename:    AndQuery.hpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-4-19 15:44:07
 *       Compiler:    gcc
 *       Description: TextQuery class AndQuery
 *
 * =====================================================================================
 */
#ifndef _TEXTQUERY_ANDQUERY_H
#define _TEXTQUERY_ANDQUERY_H
class AndQuery: public BinaryQuery
{
    friend Query operator&(const Query&, const Query&);
    AndQuery(Query left, Query right):BinaryQuery(left, right, "&") { }
    virtual ~AndQuery();
    std::set<line_no> eval(const TextQuery&) const;
};
#endif