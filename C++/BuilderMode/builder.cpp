#include "builder.h"
#include "product.h"

#include <iostream>
//#include <string>

Builder::Builder()
{
}

Builder::~Builder()
{

}

ConcreteBuilder::ConcreteBuilder()
{

}

ConcreteBuilder::~ConcreteBuilder()
{

}

void ConcreteBuilder::buildPartA(const string &buildPara)
{
    std::cout << "Step1:Build PartA.." << std::endl;
}

void ConcreteBuilder::buildPartB(const string &buildPara)
{
    std::cout << "Step1:Build PartB.." << std::endl;
}

void ConcreteBuilder::buildPartC(const string &buildPara)
{
    std::cout << "Step1:Build PartC.." << std::endl;
}

Product* ConcreteBuilder::getProduct()
{
    buildPartA("pre-defined");
    buildPartB("pre-defined");
    buildPartC("pre-defined");

    return new Product;
}
