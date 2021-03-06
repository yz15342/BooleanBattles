/*Checks player and enemy are both still alive. Triggers win/lose conditions if not.*/

#include "checkAttack.h"

int damageState(int attack, enemy* pEnemy, int* enemyHealth, int* playerHealth, battleState* pState);
void implementDamage(int attack, enemy* pEnemy, int* enemyHealth, int* playerHealth);
int checkHealth(int enemyHealth, int playerHealth, battleState* pState);
int loseBattle();
int winBattle();
int subTestDamage(int attack, int* pTurns);
