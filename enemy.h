/*Retrieves or generates information about our enemy*/

#include "base.h"

#define ATTACKCOMBOS 8
#define FILLER -99

struct enemy{
    int weakness[ATTACKCOMBOS];
    int solutions;
    char* equation;
};

struct enemy createEnemy();
void fillWeaknessArray(enemy* pEnemy, int weaknesses[]);
void fillWeaknessFiller(enemy* pEnemy);
