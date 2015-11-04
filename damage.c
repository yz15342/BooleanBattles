#include "damage.h"
#include <stdio.h>

int damageState(int fire, int water, int grass, enemy* pEnemy, int* enemyHealth, int* playerHealth)
{
    implementDamage(fire, water, grass, pEnemy, enemyHealth, playerHealth);
    return checkHealth(*enemyHealth, *playerHealth);
}

void implementDamage(int fire, int water, int grass, enemy* pEnemy, int* enemyHealth, int* playerHealth)
{
    int attack = 100 * grass + 10 * water + fire;
    if(checkAttack(attack, pEnemy)){
        (*enemyHealth)--;
    }
    else{
        (*playerHealth)--;
    }
    return;
}

int checkHealth(int enemyHealth, int playerHealth)
{
    if(playerHealth <= 0){
        return loseBattle();
    }
    else if(enemyHealth <= 0){
        return winBattle();
    }
    return 0;
}

int loseBattle()
{
    printf("You lose. Sorry :(\n");
    return -1;
}

int winBattle()
{
    printf("You win! Congratz!\n");
    return 1;
}

void testDamage()
{
    int i, j, k, l = 0, turns = 0;
    int *pTurns = &turns;
    int results[ATTACKCOMBOS][2];
    for(i = 0; i <= 1; i++){
        for(j = 0; j <= 1; j++){
            for(k = 0; k <= 1; k++){
                turns = 0;
                results[l][0] = subTestDamage(i, j, k, pTurns);
                results[l][1] = turns;
                l++;
            }
        }
    }
    for(l = 0; l < 5; l++){
        if(results[l][0] != -1){
            fail("Lose check failed.");
        }
    }
    for(l = 5; l < ATTACKCOMBOS; l++){
        if(results[l][0] != 1){
            fail("Win check failed.");
        }
    }
    for(l = 0; l < ATTACKCOMBOS; l++){
        if(results[l][1] != 3){
            fail("Turn counter failed.");
        }
    }
    succeed("Damage ok");

}

int subTestDamage(int grass, int water, int fire, int* pTurns)
{
    int playerHealth = 3, enemyHealth = 3, result = 0;
    int *pPlayerHealth = &playerHealth, *pEnemyHealth = &enemyHealth;
    enemy newEnemy = createEnemy();
    enemy* pEnemy = &newEnemy;
    while(result == 0){
        result = damageState(fire, water, grass, pEnemy, pEnemyHealth, pPlayerHealth);
        (*pTurns)++;
    }
    return result;
}