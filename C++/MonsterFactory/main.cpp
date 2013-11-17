#include "heavymonsterfactory.h"
#include "lightmonsterfactory.h"
#include "heavymonster.h"
#include "lightmonster.h"

#include <iostream>

int main() {
    AbstractMonsterFactory *lightMonsterFactory = LightMonsterFactory::interface();
    AbstractMonsterType *lm = lightMonsterFactory->createOneLevelMonster();
    AbstractMonsterType *hm = lightMonsterFactory->createTwoLevelMonster();

    AbstractMonsterFactory *heavyMonsterFactory = HeavyMonsterFactory::interface();
    AbstractMonsterType *lm1 = lightMonsterFactory->createOneLevelMonster();
    AbstractMonsterType *hm2 = lightMonsterFactory->createTwoLevelMonster();

    delete lm, hm, lm1, hm2;

    return 0;
}

