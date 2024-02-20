#include "prototype.h"

void bola9x9 (int coordX, int coordY, short cor) {
    video_box(coordX - 1, coordY - 4, coordX + 1, coordY - 4, cor);
	video_box(coordX - 3, coordY - 3, coordX + 3, coordY - 2, cor);
	video_box(coordX - 4, coordY - 1, coordX + 4, coordY + 1, cor);
	video_box(coordX - 3, coordY + 2, coordX + 3, coordY + 3, cor);
	video_box(coordX - 1, coordY + 4, coordX + 1, coordY + 4, cor);
}

int detect_collision(int x_rect, int y_rect, int length_rect, int width_rect,  int x_boll, int y_boll, int ray, int *x_point, int *y_point) {

    *x_point = x_boll;  /* Ponto de impacto em x */
    *y_point = y_boll;  /* ponto de impacto em y */
    
    /* Procurar o ponto mais proximo do circulo no eixo x */
    if (x_boll < x_rect)
        (*x_point) = x_rect;
    else if (x_boll > x_rect + length_rect) 
        (*x_point) = x_rect + length_rect;

    /* Procurar o ponto mais proximo do circulo no eixo y */
    if (y_boll < y_rect)
        (*y_point) = y_rect;
    else if (y_boll > y_rect + width_rect) 
        (*y_point) = y_rect + width_rect;

    /* Calcular distancia e verificar se a bola esta dentro bloco */
    int dist_x = x_boll - *x_point;
    int dist_y = y_boll - *y_point;
    int distance = round(sqrt(dist_x * dist_x + dist_y * dist_y));

    if (distance <= ray)
        return 1;

    return 0;
}

/* Buscar o tipo de colisão */
int getTypeCollision(Ball *ball, Block blocksList[], Bar *bar) {
    int x_point, y_point;

    /* Paredes: colisão na parte superior à esquerda */
    if ((ball->ballPositionX - COLLISION_RADIUS == WALL_WIDHT_X) && (ball->ballPositionY - COLLISION_RADIUS == (WALL_WIDHT_X + WALL_WIDHT_Y)))
        return 1;
        
    /* Paredes: colisão na parte superior à direita */ 
    else if ((ball->ballPositionX + COLLISION_RADIUS == (SCREEN_X - WALL_WIDHT_X) && (ball->ballPositionY - COLLISION_RADIUS == (WALL_WIDHT_X + WALL_WIDHT_Y))))
        return 1;

    /* Barra e parede */
    else if ((detect_collision(bar->coordX - BAR_SIZE, bar->coordY - BAR_WIDHT, (BAR_SIZE * 2 + 1), (BAR_WIDHT * 2 + 1), ball->ballPositionX, 
    ball->ballPositionY, COLLISION_RADIUS, &x_point, &y_point) == 1) && ((ball->ballPositionX - COLLISION_RADIUS == WALL_WIDHT_X) || (ball->ballPositionX + COLLISION_RADIUS == (SCREEN_X - WALL_WIDHT_X)))) 
    	return 5; 

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
            if (y_point == blocksList[i].coordY && (x_point >= blocksList[i].coordX && x_point <= (blocksList[i].coordX + BLOCK_LENGTH))){
            	if (x_point == blocksList[i].coordX && x_point == (blocksList[i].coordX + BLOCK_LENGTH) && ball->ballSpeedY < 0)
            		return 2;
                return 3;
            }

            /* Colisão na parte inferior */
            else if (y_point == (blocksList[i].coordY + BLOCK_WIDHT) && (x_point >= blocksList[i].coordX && x_point <= (blocksList[i].coordX + BLOCK_LENGTH))){
            	if (x_point == blocksList[i].coordX && x_point == (blocksList[i].coordX + BLOCK_LENGTH) && ball->ballSpeedY > 0)
            		return 2;
                return 3;
              }

            /* Colisão à esquerda */
            else if (y_point > blocksList[i].coordY && y_point < (blocksList[i].coordY + BLOCK_WIDHT) && x_point == blocksList[i].coordX)
                return 2;

            /* Colisão à direita */
            else if (y_point > blocksList[i].coordY && y_point < (blocksList[i].coordY + BLOCK_WIDHT) && x_point == (blocksList[i].coordX + BLOCK_LENGTH))
                return 2;
        }
    }

    return -1;
}


/* Função para mover a bola e evitar colisões */
int getMoveBall(Ball *ball, Block blocksList[], Bar *bar) {
    Ball auxBall = *ball;

    int pontosIntermediarios = 100;
    float tempo = 0.0;
    int typeCollision;

    /* Verificação de colisão nos pontos intermediários */
    for (int i = 0; i <= pontosIntermediarios; i++) {
        tempo =  i / (float)  pontosIntermediarios;

        /* Valores para verificar se há colisão */
        auxBall.ballPositionX = (int) round(ball->ballPositionX + ball->ballSpeedX * tempo);
        auxBall.ballPositionY = (int) round(ball->ballPositionY  + ball->ballSpeedY * tempo);

        /* Verifica se houve colisão */
        typeCollision = getTypeCollision(&auxBall, blocksList, bar);

        if (typeCollision != -1 &&  ball->collision != typeCollision && ball->collision != 5) { 

            printf("\nAUX: posicao x: %d;    posicao y: %d\n", auxBall.ballPositionX, auxBall.ballPositionY);
            printf("BALL: posicao x: %d;    posicao y: %d\n", ball->ballPositionX, ball->ballPositionY);	
            printf("tipo de colisao: %d\n", typeCollision);

            *ball = auxBall;
            ball->collision = typeCollision;

            return typeCollision;
        }
    }

    /* Sem colisão */
    ball->ballPositionX += ball->ballSpeedX;
    ball->ballPositionY += ball->ballSpeedY;
    ball->collision = -1;

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
        if (ball->ballPositionX < bar->coordX && (bar->coordX - ball->ballPositionX) / 6 != 0 ){
            ball->ballSpeedX = -(bar->coordX - ball->ballPositionX) / 6;

        } else if (ball->ballPositionX > bar->coordX && (bar->coordX - ball->ballPositionX) / 6 != 0 ){
            ball->ballSpeedX = (ball->ballPositionX - bar->coordX) / 6;

        } break;

    case (5):
        ball->ballSpeedX = -ball->ballSpeedX;
        ball->ballSpeedY = -ball->ballSpeedY;
        break;    

    }
}