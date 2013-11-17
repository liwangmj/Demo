#include "product.h"

#include <iostream>

Product::Product()
{
    producePart();
    std::cout << "return a product" << std::endl;
}

Product::~Product()
{
}

void Product::producePart()
{
    std::cout << "build part of product.." << std::endl;
}

ProductPart::ProductPart()
{

}

ProductPart::~ProductPart()
{

}

ProductPart* ProductPart::buildPart()
{
    return new ProductPart;
}
