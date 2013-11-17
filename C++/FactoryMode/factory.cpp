#include "factory.h"
#include "product.h"

#include <iostream>

ConcreteFactoryA::ConcreteFactoryA()
{
    std::cout << "ConcreteFactoryA...." << std::endl;
}

ConcreteFactoryA::~ConcreteFactoryA()
{
}

Product* ConcreteFactoryA::createProductA()
{
    return new ConcreteProductA;
}
Product* ConcreteFactoryA::createProductB()
{
    return new ConcreteProductB;
}

ConcreteFactoryB::ConcreteFactoryB()
{
    std::cout << "ConcreteFactoryB...." << std::endl;
}

ConcreteFactoryB::~ConcreteFactoryB()
{
}

Product* ConcreteFactoryB::createProductA()
{
    return new ConcreteProductA;
}
Product* ConcreteFactoryB::createProductB()
{
    return new ConcreteProductB;
}
