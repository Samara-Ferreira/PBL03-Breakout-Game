#include "constants.h"
#include "blocks.c"
#include "bar.c"

typedef struct {
    int ballPositionX;
    int ballPositionY;
    int ballSpeedX;
    int ballSpeedY;
} Ball;


/* Buscar o tipo de colisão */
int getTypeCollision(Ball *ball, Block blocksList[], Bar *bar) {
    int x_point, y_point;

    /* Paredes: colisão na parte superior à esquerda */
    if ((ball->ballPositionX - COLLISION_RADIUS == WALL_WIDHT_X) && (ball->ballPositionY - COLLISION_RADIUS == (WALL_WIDHT_X + WALL_WIDHT_Y)))
        return 1;
        
    /* Paredes: colisão na parte superior à direita */ 
    else if ((ball->ballPositionX + COLLISION_RADIUS == (SCREEN_X - WALL_WIDHT_X) && (ball->ballPositionY - COLLISION_RADIUS == (WALL_WIDHT_X + WALL_WIDHT_Y))))
        return 1;

    /* Paredes: colisões na esquerda e direita */  
    else if ((ball->ballPositionX - COLLISION_RADIUS == WALL_WIDHT_X) || (ball->ballPositionX + COLLISION_RADIUS == (SCREEN_X - WALL_WIDHT_X)))
        return 2;

    /* Paredes: colisão na parte superior */
    else if ((ball->ballPositionY - COLLISION_RADIUS == (WALL_WIDHT_X + WALL_WIDHT_Y)))
        return 3;

    /* Colisões na barra */
    else if ((detect_collision(bar->coordX - BAR_SIZE, bar->coordY - BAR_WIDHT, (BAR_SIZE * 2 + 1), (BAR_WIDHT * 2 + 1), ball->ballPositionX, 
    ball->ballPositionY, COLLISION_RADIUS, &x_point, &y_point)) == 1)
        return 4;

    /* Colisões nos blocos */
    for (int i = 0; i < QUANTITY_BLOCKS; i++) {

        if ((detect_collision(blocksList[i].coordX, blocksList[i].coordY, BLOCK_LENGTH, BLOCK_WIDHT, ball->ballPositionX, ball->ballPositionY, 
        COLLISION_RADIUS, &x_point, &y_point) == 1) && (blocksList[i].flagVisible == 1)) {

            /* Colisão na parte superior */
            if (y_point == blocksList[i].coordY && (x_point >= blocksList[i].coordX && x_point <= (blocksList[i].coordX + BLOCK_LENGTH)))
                return 3;

            /* Colisão na parte inferior */
            else if (y_point == (blocksList[i].coordY + BLOCK_WIDHT) && (x_point >= blocksList[i].coordX && x_point <= (blocksList[i].coordX + BLOCK_LENGTH)))
                return 3;

            /* Colisão à esquerda */
            else if (y_point > blocksList[i].coordY && y_point < (blocksList[i].coordY + BLOCK_WIDHT) && x_point == blocksList[i].coordX)
                return 2;

            /* Colisão à direita direita */
            else if (y_point > blocksList[i].coordY && y_point < (blocksList[i].coordY + BLOCK_WIDHT) && x_point == (blocksList[i].coordX + BLOCK_LENGTH))
                return 2;
        }
    }

    return -1;
}


/* Função para mover a bola e evitar colisões */
int getMoveBall(Ball *ball, Block blocksList[], Bar *bar) {
    Ball auxBall = *ball;

    int pontosIntermediarios = 20;
    float tempo = 0.0;

    /* Verificação de colisão nos pontos intermediários */
    for (int i = 0; i <= pontosIntermediarios; i++) {
        tempo = (float) i / pontosIntermediarios;

        /* Valores para verificar se há colisão */
        auxBall.ballPositionX += round(auxBall.ballSpeedX * tempo);
        auxBall.ballPositionY += round(auxBall.ballSpeedY * tempo);

        /* Verifica se houve colisão */
        int typeCollision = getTypeCollision(&auxBall, blocksList, bar);

        if (typeCollision != -1) {
            ball = &auxBall;
            return typeCollision;
        }
    }

    /* Sem colisão */
    ball->ballPositionX += ball->ballSpeedX;
    ball->ballPositionY += ball->ballSpeedY;
    return -1;
}


/* Verificação dos possíveis casos de colisão */
void moveBall(Ball *ball, Block blocksList[], Bar *bar) {

    switch (getMoveBall(ball, blocksList, bar)) {
    
    case (1):
        ball->ballSpeedX = -ball->ballSpeedX;
        ball->ballSpeedY = -ball->ballSpeedY;
        break;

    case (2):
        ball->ballSpeedX = -ball->ballSpeedX;
        break;

    case (3):
        ball->ballSpeedY = -ball->ballSpeedY;
        break;

    case (4):
        ball->ballSpeedY = -ball->ballSpeedY;

        /* Variação da velocidade no eixo x */
        if (ball->ballPositionX <= bar->coordX)
            ball->ballSpeedX = -(bar->coordX - ball->ballPositionX);
        else
            ball->ballSpeedX = ball->ballPositionX - bar->coordX;
        break;
    }
}



