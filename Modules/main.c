#include <stdio.h>
#include <stdlib.h>
#include <constants.h>
//#include <intelfpgaup/accel.h>
#include <blocks.c>
#include <ball.c>
#include <bar.c>


int checkWin(Block blocksList[]) {
    for (int i = 0; i < QUANTITY_BLOCKS; i++) {
        if ((blocksList[i].flagVisible == 1) && (blocksList[i].life != -1))
            return 1;
    }

    return 0;
}

int checkLose(Ball *ball) {
    if (ball->ballPositionY > (SCREEN_Y - 20 + BAR_WIDHT))
        return 0;
    else 
        return 1;
}


int main() {

    /* Inicializar os elementos do jogo */

    Block blocksList[QUANTITY_BLOCKS];
    /* em andamento... */

    Ball ball;
    ball.ballPositionX = SCREEN_X / 2;
    ball.ballPositionY = SCREEN_Y - 60;
    ball.ballSpeedX = 2;
    ball.ballSpeedY = 5;
    
    Bar bar;
    bar.coordX = SCREEN_X / 2;
    bar.coordY = SCREEN_Y - 20;

    int score = 0;


    /* Inicializações */

    int ready, tap, dtap, velX, velY, velZ, mg_per_lsb;

    accel_open();

    accel_init();

    accel_calibrate();


    /* Loop principal do jogo */
    while (checkWin(blocksList) && checkLose(&ball)) {

        accel_read(&ready, &tap, &dtap, &velX, &velY, &velZ, &mg_per_lsb);

        /* Movimentar a barra */
        moveBar(&bar, velX);

        /* Movimentar a bola */
        moveBall(&ball, blocksList, &bar);     

        removeBlocks(blocksList, &score, &ball);
    }


    return 0;
}
