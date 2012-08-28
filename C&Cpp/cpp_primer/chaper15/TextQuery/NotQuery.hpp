/*
 * =====================================================================================
 *
 *       Filename:    NotQuery.hpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-4-19 15:27:54
 *       Compiler:    gcc
 *       Description: TextQuery class NotQuery
 *
 * =====================================================================================
 */
#ifndef _TEXTQUERY_NOTQUERY_H
#define _TEXTQUERY_NOTQUERY_H
class NotQuery:public QueryBase{
    friend Query operator~(const Query &);
    NotQuery(Query q):query(q) {}
    std::set<line_no> eval(const TextQuery&) const;
    std::ostream& display(std::ostream &os) const {
        return os << "~(" << query << ")"; 
    }
    const Query query;
};
#endif