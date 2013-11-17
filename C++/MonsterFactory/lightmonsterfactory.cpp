#include "lightmonsterfactory.h"
#include "lightmonster.h"
#include "heavymonster.h"

#include <iostream>

LightMonsterFactory* LightMonsterFactory::_interface = 0;

LightMonsterFactory::LightMonsterFactory()
{
}

LightMonsterFactory::~LightMonsterFactory()
{
}

LightMonster* LightMonsterFactory::createOneLevelMonster()
{
    return new LightMonster;
}

HeavyMonster *LightMonsterFactory::createTwoLevelMonster()
{
    return new HeavyMonster;
}

LightMonsterFactory* LightMonsterFactory::interface()
{
    if (0 == _interface) {
        _interface = new LightMonsterFactory;
    }

    return _interface;
}
