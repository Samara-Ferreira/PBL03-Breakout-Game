typedef struct {
    int coordX;         /* x do canto superior esquerdo */ 
    int coordY;         /* y do canto superior esquerdo */
    int flagVisible;    /* flag para saber se o bloco esta visivel */
    int life;           /* vida do bloco */ 
    int points;         /* pontos do bloco */
} Block;


int detect_collision(int x_rect, int y_rect, int length_rect, int width_rect,  int x_boll, int y_boll, int ray, int *x_point, 
int *y_point) {

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


/* Função para remover os blocos */
void removeBlocks(Block blocksList[], int index, int *score) {
    if (blocksList[index].life == 1) {
        blocksList[index].flagVisible = 0;

        /* Pontuação do jogo */
        (*score) += blocksList[index].points;
    }

    else if (blocksList[index].life != -1)
        blocksList[index].life--;
}

