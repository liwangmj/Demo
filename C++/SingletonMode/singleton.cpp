#include "singleton.h"

#include <iostream>

Singleton* Singleton::_interface = 0;

Singleton::Singleton()
{
    std::cout << "Singleton new OK!" << std::endl;
}

Singleton* Singleton::interface()
{
    if (0 == _interface) {
        _interface = new Singleton;
    }
    return _interface;
}
