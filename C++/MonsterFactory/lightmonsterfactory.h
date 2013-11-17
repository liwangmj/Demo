#ifndef LIGHTMONSTERFACTORY_H
#define LIGHTMONSTERFACTORY_H

#include "abstractmonsterfactory.h"

class LightMonsterFactory : public AbstractMonsterFactory
{
public:
    ~LightMonsterFactory();
    static LightMonsterFactory* interface();

    LightMonster* createOneLevelMonster();
    HeavyMonster* createTwoLevelMonster();

protected:
    LightMonsterFactory();

private:
    static LightMonsterFactory* _interface;

};

#endif // LIGHTMONSTERFACTORY_H
