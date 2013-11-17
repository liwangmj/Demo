#include "factory.h"
#include "product.h"

#include <iostream>

int main()
{
    Factory *facA = new ConcreteFactoryA;
    Factory *facB = new ConcreteFactoryB;

    std::cout << std::endl;

    Product *p1 = facA->createProductA();
    Product *p2 = facA->createProductB();

    std::cout << std::endl;

    Product *p11 = facB->createProductA();
    Product *p12 = facB->createProductB();


    return 0;
}

