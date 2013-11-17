#ifndef FACTORY_H
#define FACTORY_H

class Product;

class Factory
{
public:
    virtual Product *createProductA() = 0;
    virtual Product *createProductB() = 0;

};

class ConcreteFactoryA : public Factory
{
public:
    ~ConcreteFactoryA();
    ConcreteFactoryA();

    Product *createProductA();
    Product *createProductB();

};

class ConcreteFactoryB : public Factory
{
public:
    ~ConcreteFactoryB();
    ConcreteFactoryB();

    Product *createProductA();
    Product *createProductB();
};

#endif // FACTORY_H
