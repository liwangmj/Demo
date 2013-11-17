#ifndef BUILDER_H
#define BUILDER_H

class Product;
class string;
//#include <string>

class Builder
{
public:
    virtual ~Builder();
    virtual void buildPartA(const string &buildPara) = 0;
    virtual void buildPartB(const string &buildPara) = 0;
    virtual void buildPartC(const string &buildPara) = 0;
    virtual Product* getProduct() = 0;

protected:
    Builder();
};

class ConcreteBuilder : public Builder
{
public:
    ConcreteBuilder();
    ~ConcreteBuilder();

    void buildPartA(const string &buildPara);
    void buildPartB(const string &buildPara);
    void buildPartC(const string &buildPara);
    Product* getProduct();

};

#endif // BUILDER_H
