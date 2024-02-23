#include "prototype.h"


int checkWin(Block blocksList[]) {
    for (int i = 0; i < QUANTITY_BLOCKS; i++) {
        if ((blocksList[i].flagVisible == 1) && (blocksList[i].life != -1))
            return 1;
    }

    return 0;
}

int checkLose(Ball *ball) {
    if (ball->ballPositionY > (SCREEN_Y - 25))
        return 0;
    else 
        return 1;
}

void reset_data (Ball *ball, Bar *bar, int *score) {

    ball->ballPositionX = SCREEN_X / 2;
    ball->ballPositionY = SCREEN_Y - 120;
    ball->ballSpeedX = 1;
    ball->ballSpeedY = 1;
    ball->collision = -1;
    
    bar->coordX = SCREEN_X / 2;
    bar->coordY = SCREEN_Y - 20;

    *score = 0;

}

int main() {

     /* Inicializar os elementos do jogo */
 
    int score;
    Block blocksList[QUANTITY_BLOCKS];
    Ball ball;
    Bar bar;
    
    reset_data (&ball, &bar, &score);

    int state_game, buttons;

    KEY_open();


    int ready, tap, dtap, velX, velY, velZ, mg_per_lsb;

    accel_open();

    accel_init();

    accel_calibrate();

    video_open();
    
    makeBlocks (blocksList);
    
    while (1) {
    
    	state_game = 0;
    	reset_data (&ball, &bar, &score);
	    makeBlocks (blocksList);
    	
        /* Loop principal do jogo */
        while (checkWin(blocksList) && checkLose(&ball)) {
        
            KEY_read(&buttons);
            change_state(&state_game, &buttons);
            
            video_clear();
            video_erase();
            
            if (state_game == 0) {
                
                reset_data (&ball, &bar, &score);
                makeBlocks (blocksList);
                create_menu();
                video_show();
            
            } else if (state_game == 1) {
            
                game_field (blocksList, score, state_game);
                
                bola9x9 (ball.ballPositionX, ball.ballPositionY, 0xFfe0);
                video_box( bar.coordX - BAR_SIZE, bar.coordY - BAR_WIDHT, bar.coordX + BAR_SIZE,bar.coordY + BAR_WIDHT , 0xFC18);
            
                video_show();

                accel_read(&ready, &tap, &dtap, &velX, &velY, &velZ, &mg_per_lsb);

                /* Movimentar a barra */
                moveBar(&bar, velX); 

                /* Movimentar a bola */
                moveBall(&ball, blocksList, &bar);
             

                removeBlocks(blocksList, &score, &ball);
            
            } else if (state_game == 2) {

                game_field (blocksList, score, state_game);
                bola9x9 (ball.ballPositionX, ball.ballPositionY, 0xFC18);
                video_box( bar.coordX - BAR_SIZE, bar.coordY - BAR_WIDHT, bar.coordX + BAR_SIZE,bar.coordY + BAR_WIDHT , 0xFC18);
                video_show();
            
            } else if (state_game == 3) {

                game_field (blocksList, score, state_game);
                bola9x9 (ball.ballPositionX, ball.ballPositionY, 0xFC18);
                video_box( bar.coordX - BAR_SIZE, bar.coordY - BAR_WIDHT, bar.coordX + BAR_SIZE,bar.coordY + BAR_WIDHT , 0xFC18);
                video_show();
            }
            
        }

        if (checkLose(&ball) == 0) {

            do {

                KEY_read(&buttons);

                video_clear();
                video_erase();
                screen_defeat(score);
                video_show();

            } while (buttons != 1);

        }

        else {

            screen_victory_continuous();

        }
    
    }
    

   
    return 0;
}

