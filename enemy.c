#include "enemy.h"
#include <string.h>

struct enemy createEnemy()
{
    enemy newEnemy;
    enemy* pEnemy;
    pEnemy = &newEnemy;
    int tmp[] = {101, 110, 111};
    newEnemy.solutions = sizeof(tmp) / sizeof(tmp[0]);
    newEnemy.equation = "(F || W) && G";
    fillWeaknessArray(pEnemy, tmp);
    fillWeaknessFiller(pEnemy);
    return newEnemy;
}

void fillWeaknessArray(enemy* pEnemy, int weaknesses[])
{
    int i;
    for(i = 0; i < (*pEnemy).solutions; i++){
        (*pEnemy).weakness[i] = weaknesses[i];
    }
    return;
}

void fillWeaknessFiller(enemy* pEnemy)
{
    int i;
    for(i = (*pEnemy).solutions; i < ATTACKCOMBOS; i++){
        (*pEnemy).weakness[i] = FILLER;
    }
    return;
}

void testEnemy()
{
    int i;
    enemy newEnemy;
    newEnemy = createEnemy();
    if(newEnemy.weakness[0] != 101){
        fail("Weakness 0 set incorrectly");
    }
    if(newEnemy.weakness[1] != 110){
        fail("Weakness 1 set incorrectly");
    }
    if(newEnemy.weakness[2] != 111){
        fail("Weakness 2 set incorrectly");
    }
    if(newEnemy.solutions != 3){
        fail("Solutions set incorrectly");
    }
    if(strcmp(newEnemy.equation, "(F || W) && G") != 0){
        fail("Equation set incorrectly");
    }
    for(i = newEnemy.solutions; i < ATTACKCOMBOS; i++){
        if(newEnemy.weakness[i] != FILLER){
            fail("Filler weakness not set");
        }
    }

    succeed("Enemy module ok");
}


