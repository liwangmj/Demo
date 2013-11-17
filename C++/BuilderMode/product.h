#ifndef PRODUCT_H
#define PRODUCT_H

class Product
{
public:
    ~Product();
    Product();

    void producePart();
};

class ProductPart
{
public:
    ~ProductPart();
    ProductPart();

    ProductPart* buildPart();
};

#endif // PRODUCT_H
