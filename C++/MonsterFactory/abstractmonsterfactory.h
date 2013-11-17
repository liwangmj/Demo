#ifndef ABSTRACTMONSTERFACTORY_H
#define ABSTRACTMONSTERFACTORY_H

class AbstractMonsterType;
class LightMonster;
class HeavyMonster;

class AbstractMonsterFactory
{
public:
    virtual LightMonster* createOneLevelMonster() = 0;
    virtual HeavyMonster* createTwoLevelMonster() = 0;
};

#endif // ABSTRACTMONSTERFACTORY_H
