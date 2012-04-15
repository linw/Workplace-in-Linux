/*
 * =====================================================================================
 *
 *       Filename:    Library.hpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-4-11 21:57:11
 *       Compiler:    gcc
 *       Description: 习题 15.4 下面类中哪些可以设为virtual
 *     class Library
 *     {
 *     public:
 *       bool check_out(const LibMember&);
 *       bool check_in(const LibMember&);
 *       bool is_late(const Date& today);
 *       double apply_fine();
 *       ostream& print(ostream& = cout);
 *       Date due_date() const;
 *       Date date_borrowed() const;
 *       string title() const;
 *       const LibMember& member() const;
 *     };
 *
 * =====================================================================================
 */
#ifndef _CHAPER15_LIBRARY_H
#define _CHAPER15_LIBRARY_H
class Library
{
public:
    virtual bool check_out(const LibMember&);
    virtual bool check_in(const LibMember&);
    bool is_late(const Date& today); //公用
    double apply_fine();  //公用
    virtual ostream& print(ostream& = cout); 
    Date due_date() const;  //公用
    Date date_borrowed() const;  //公用
    virtual string title() const;
    const LibMember& member() const;  //公用
    Library(arguments);
    virtual ~Library();

    /* data */
};
#endif