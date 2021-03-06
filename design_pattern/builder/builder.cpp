/*
 * =====================================================================================
 *
 *       Filename:    builder.cpp
 *       Author:      linwei
 *       E-mail:      kinglw8729@gmail.com
 *       Created:     2012-08-04 20:49:55
 *       Last Edit:   
 *       Compiler:    gcc
 *       Description: 建造者模式:将一个复杂对象的构建与它的表示分离开来,使得同样的构建过程
 *                             可以创建不同的表示.也就是把一个对象的操作利用一个类来管理
 *                             建造过程,从而实现类的建造过程
 * =====================================================================================
 */
#include <iostream>
#include <vector>
#include <string>
using std::endl;
using std::cout;
using std::vector;
using std::string;
class Product
{
public:
  Product(){
    parts.clear();
  };
  Product(const Product& p){
    parts = vector<string>(p.parts);
  };
  virtual ~Product(){};
private:
  vector<string> parts;
public:
  void add(string part);
  void show();
};

void Product::add(string part)
{
  parts.push_back(part);
}
void Product::show()
{
  for(vector<string>::iterator iter = parts.begin();
      iter != parts.end();
      ++iter){
    cout<<iter->c_str()<<endl;
  }
}


class Builder
{
public:
  Builder() {};
  Builder(const Builder& b) {};
  virtual ~Builder() {};
public:
  virtual void buildPartA() = 0;
  virtual void buildPartB() = 0;
  virtual Product* getResult() = 0;
  virtual const Product* getResult() const = 0;
};

class ConcreteBuilder1:public Builder
{
public:
  ConcreteBuilder1(){
    product = new Product();
  };
  ConcreteBuilder1(const ConcreteBuilder1& cb) {
    if(cb.product != NULL){
      product = new Product(*cb.product);
    }
    product = NULL;
  };
  virtual ~ConcreteBuilder1(){
    if(product != NULL)
      delete product;
  };
private:
  Product* product;
public:
  void buildPartA();
  void buildPartB();
  Product* getResult();
  const Product* getResult() const;
};

void ConcreteBuilder1::buildPartA()
{
  product->add("partA");
}

void ConcreteBuilder1::buildPartB()
{
  product->add("partB");
}

Product* ConcreteBuilder1::getResult()
{
  return product;
}

const Product* ConcreteBuilder1::getResult() const
{
  return (const Product*) product;
}




class ConcreteBuilder2:public Builder
{
public:
  ConcreteBuilder2(){
    product = new Product();
  };
  ConcreteBuilder2(const ConcreteBuilder2& cb) {
    if(cb.product != NULL){
      product = new Product(*cb.product);
    }
    product = NULL;
  };
  virtual ~ConcreteBuilder2(){
    if(product != NULL)
      delete product;
  };
private:
  Product* product;
public:
  void buildPartA();
  void buildPartB();
  Product* getResult();
  const Product* getResult() const;
};

void ConcreteBuilder2::buildPartA()
{
  product->add("partC");
}

void ConcreteBuilder2::buildPartB()
{
  product->add("partD");
}

Product* ConcreteBuilder2::getResult()
{
  return product;
}

const Product* ConcreteBuilder2::getResult() const
{
  return (const Product*) product;
}





class Director
{
public:
  Director() {};
  Director(const Director& _d) {};
  virtual ~Director(){};
public:
  void Construct(Builder* builder);
};

void Director::Construct(Builder* builder)
{
  builder->buildPartA();
  builder->buildPartB();
}


int main()
{
  ConcreteBuilder1* p = new ConcreteBuilder1();
  ConcreteBuilder2 * q = new ConcreteBuilder2();
  Director d;
  d.Construct(p);
  d.Construct(q);
  p->getResult()->show();
  q->getResult()->show();
  return 0;
}
