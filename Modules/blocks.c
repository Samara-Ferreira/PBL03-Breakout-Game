#include "prototype.h"

void makeBlocks (Block blocksList[]) {

	int i, j, count = 0;
	short colors[6] = {0xf012, 0xe800, 0xf301, 0xdd82, 0x5ec, 0xf37}; //rosa forte, vermelho escuro, laranja, amarelo dourado, ciano claro, verde vivo

	for (i = 0; i < 6; i++) { 
	
	    for (j = 0; j < 8; j++) {
	    
		blocksList[count].coordX =  5 + (39 * j);
		blocksList[count].coordY = 20 + (i * 14);
		blocksList[count].flagVisible = 1; 
		blocksList[count].life   =  1;
		blocksList[count].points =  11 - (i * 2); 
		blocksList[count].color  =  colors[i];

		count++;  
        }  
	}  
	
}

/* Função para remover os blocos */
void removeBlocks (Block blocksList[], int *score,  Ball *ball) {

    int x_point, y_point;

    for (int i = 0; i < QUANTITY_BLOCKS; i++) {
     

        if ((detect_collision(blocksList[i].coordX, blocksList[i].coordY, BLOCK_LENGTH, BLOCK_WIDHT, ball->ballPositionX, ball->ballPositionY, 
        COLLISION_RADIUS, &x_point, &y_point) == 1) && (blocksList[i].flagVisible == 1)) {
            if (blocksList[i].life == 1) {
                blocksList[i].flagVisible = 0;

                /* Pontuação do jogo */
                (*score) += blocksList[i].points;
            }
            else if (blocksList[i].life != -1)
                blocksList[i].life--;
        }
    }
}