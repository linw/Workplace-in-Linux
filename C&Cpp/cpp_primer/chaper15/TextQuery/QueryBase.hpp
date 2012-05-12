/*
 * =====================================================================================
 *
 *       Filename:    QueryBase.hpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-4-17 14:44:23
 *       Compiler:    gcc
 *       Description: TextQuery base class QueryBase
 *
 * =====================================================================================
 */
#ifndef _TEXTQUERY_QUERYBASE_H
#define _TEXTQUERY_QUERYBASE_H
#include <iostream>
class QueryBase
{
    friend class Query;
protected:
    typedef TextQuery::line_no line_no;
    QueryBase();
    virtual ~QueryBase();
private:    
    virtual std::set<line_no>
        eval(const TextQuery&) const = 0;
    virtual std::ostream&
        display(std::ostream& = std::cout) const = 0;
};
#endif