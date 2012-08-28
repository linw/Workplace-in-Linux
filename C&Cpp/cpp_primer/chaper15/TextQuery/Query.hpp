/*
 * =====================================================================================
 *
 *       Filename:    Query.hpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-4-17 14:44:23
 *       Compiler:    gcc
 *       Description: TextQuery class Query
 *
 * =====================================================================================
 */
#ifndef _TEXTQUERY_QUERY_H
#define _TEXTQUERY_QUERY_H
#include <iostream>
#include <string>
inline Query operator~(const Query &oper){
    return new NotQuery(oper);
}
inline Query operator|(const Query &lhs, const Query &rhs){
    return new OrQuery(lhs,rhs);
}
inline Query operator&(const Query &lhs, const Query &rhs){
    return new AndQuery(lhs,rhs);
}
class Query
{
    friend Query operator~(const Query &);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
public:
    Query(const std::string&); // builds a new WordQuery
    // copy control to manage pointers and use counting
    Query(const Query &c): q(c.q), use(c.use) { ++*use;}
    virtual ~Query();
    Query& operator=(const Query&);

    std::set<TextQuery::line_no>
        eval(const TextQuery &t) const { return q->eval(t);}
    std::ostream &display(std::ostream &os) const
                              { return q->display(os);}
private:
    Query(QueryBase *query):q(query), use(new std::size_t(1)) { }
    QueryBase *q;
    std::size_t *use;
    void decr_use(){ if(--*use == 0) {delete q; delete use;} }
};
#endif
