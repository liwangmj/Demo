#include "heavymonsterfactory.h"
#include "lightmonster.h"
#include "heavymonster.h"

#include <iostream>

HeavyMonsterFactory* HeavyMonsterFactory::_interface = 0;

HeavyMonsterFactory::HeavyMonsterFactory()
{
}

HeavyMonsterFactory::~HeavyMonsterFactory()
{
}

LightMonster* HeavyMonsterFactory::createOneLevelMonster()
{
    return new LightMonster;
}

HeavyMonster *HeavyMonsterFactory::createTwoLevelMonster()
{
    return new HeavyMonster;
}

HeavyMonsterFactory* HeavyMonsterFactory::interface()
{
    if (0 == _interface) {
        _interface = new HeavyMonsterFactory;
    }
    return _interface;
}
