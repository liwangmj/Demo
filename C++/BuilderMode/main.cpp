#include "builder.h"
#include "product.h"
#include "director.h"

#include <iostream>

int main()
{
    Director *d = new Director(new ConcreteBuilder);
    d->construct();
    return 0;
}

