/*
 * =====================================================================================
 *
 *       Filename:    Sales_item.h
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2011年12月22日 18时41分17秒
 *       Compiler:    gcc
 *       Description: 
 *
 * =====================================================================================
 */

#ifndef SALES_ITEM_H
#define SALES_ITEM_H
#include <string>
class SalesItem {
public:
    // operation on SalesItem objects
    double AvgPrice() const;
    bool SameIsbn(const SalesItem &rhs) const
    { return isbn == rhs.isbn; }
    // default constructor needed to initialize members of built-in type
   SalesItem(): units_sold(0), revenue(0.0) { }
private:
   std::string isbn;
   unsigned units_sold;
   double revenue;
};

double SalesItem::avg_price() const
{
    if(units_sold)
        return revenue/units_sold;
    else
        return 0;
}
#endif
