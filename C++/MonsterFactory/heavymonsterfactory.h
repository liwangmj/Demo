#ifndef HEAVYMONSTERFACTORY_H
#define HEAVYMONSTERFACTORY_H

#include "abstractmonsterfactory.h"

class HeavyMonsterFactory : public AbstractMonsterFactory
{
public:
    ~HeavyMonsterFactory();
    static HeavyMonsterFactory* interface();

    LightMonster *createOneLevelMonster();
    HeavyMonster* createTwoLevelMonster();

protected:
    HeavyMonsterFactory();

private:
    static HeavyMonsterFactory* _interface;

};

#endif // HEAVYMONSTERFACTORY_H
