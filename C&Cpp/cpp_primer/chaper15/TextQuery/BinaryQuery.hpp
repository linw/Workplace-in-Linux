/*
 * =====================================================================================
 *
 *       Filename:    BinaryQuery.hpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-4-19 15:36:57
 *       Compiler:    gcc
 *       Description: TextQuery class BinaryQuery
 *
 * =====================================================================================
 */
#ifndef _TEXTQUERY_BINARYQUERY_H
#define _TEXTQUERY_BINARYQUERY_H
class BinaryQuery:public QueryBase {
protected:
    BinaryQuery(Query left, Query right, std::string op):
        lhs(left), rhs(right), oper(op) { }
    std::ostream& display(std::ostream &os) const
    { return os << "(" << lhs << " " << oper << " "
                << rhs << ")";}
    const Query lhs, rhs;
    const std::string oper;
};
#endif