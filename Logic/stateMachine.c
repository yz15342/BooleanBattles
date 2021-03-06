#include "stateMachine.h"
#include <stdio.h>

void runStateMachine()
{
    battleState currentState = START;
    battleState* pState = &currentState;
    enemy newEnemy;
    enemy* pEnemy = &newEnemy;
    int attack = 0, enemyHealth, playerHealth, result = 0;
    int *pEnemyHealth = &enemyHealth, *pPlayerHealth = &playerHealth;

    while(result == 0){
        switch(currentState){
            case START:
                playerHealth = 3;
                newEnemy = createEnemy(pState, pEnemyHealth);
                break;
            case PLAYERINPUT:
                attack = playerInput(pState);
                break;
            case PLAYERACTION:
                damageState(attack, pEnemy, pPlayerHealth, pEnemyHealth, pState);
                break;
            case WIN:
                result = 1;
                break;
            case LOSE:
                result = -1;
                break;
        }
    }
}
