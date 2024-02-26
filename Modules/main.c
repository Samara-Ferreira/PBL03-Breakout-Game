#include "prototype.h"

/**
 * Função para veriicar se todos os blocos foram destruídos e o jogador ganhou o jogo
 * @param blocksList Lista de blocos
 * @return 1 se o jogador ganhou, 0 caso contrário     
*/
int checkWin(Block blocksList[]) {
    for (int i = 0; i < QUANTITY_BLOCKS; i++) {
        if ((blocksList[i].flagVisible == 1) && (blocksList[i].life != -1))
            return 1;
    }
    return 0;
}

/**
 * Função para verificar se o jogador perdeu o jogo
 * @param ball Bola
 * @return 0 se o jogador perdeu, 1 caso contrário  
*/
int checkLose(Ball *ball) {
    if (ball->ballPositionY > (SCREEN_Y - 25))
        return 0;
    return 1;
}

/**
 * Função para posicionar os elementos no jogo ao iniciar uma partida
 * @param ball Bola
 * @param bar Barra
 * @param score Pontuação
 * @return void
*/
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

    /*Inicializar dos perifericos*/

    /*Botões*/
    int state_game, buttons;
    KEY_open    ();
    KEY_read    (&buttons);

    /*Acelerômetro*/
    int ready, tap, dtap, velX, velY, velZ, mg_per_lsb;
    accel_open      ();
    accel_init      ();
    accel_calibrate ();

    /*Vídeo*/
    video_open();

    /* Inicializar os elementos do jogo */
    int score;
    Block blocksList[QUANTITY_BLOCKS];
    Ball ball;
    Bar bar;

    /*Loop principal do jogo*/
    while (1) { 
    
        /*Posiciona elementos e iniciar a maquina de estado da tela*/
    	state_game = 0;         
    	reset_data (&ball, &bar, &score);
	    makeBlocks (blocksList);
    	
        /*Loop da patida do jogo*/
        while (checkWin(blocksList) && checkLose(&ball)) {  // Enquanto o jogador não perdeu e não ganhou o jogo
        
            // Leitura dos botões e mudança de estado
            KEY_read        (&buttons);
            change_state    (&state_game, &buttons);

            video_clear     ();
            video_erase     ();
            
            /* switch para mudar a tela de acordo com o estado */
            if (state_game == 0) {          // Tela inicial
                reset_data  (&ball, &bar, &score);
                makeBlocks  (blocksList);
                create_menu ();
                video_show  ();
            
            } else if (state_game == 1) {       // Tela do jogo
            
                /*Desenhar elementos do jogo*/       
                game_field  (blocksList, score, state_game);
                bola9x9     (ball.ballPositionX, ball.ballPositionY, 0xffe0);
                video_box   (bar.coordX - BAR_SIZE, bar.coordY - BAR_WIDHT, bar.coordX + BAR_SIZE,bar.coordY + BAR_WIDHT , 0xfc18);
                video_show  ();

                /*Leitura do acelerômetro */
                accel_read  (&ready, &tap, &dtap, &velX, &velY, &velZ, &mg_per_lsb);

                /*Movimentação dos elementos do jogo*/
                moveBar     (&bar, velX); 
                moveBall    (&ball, blocksList, &bar);

                /*Verificação de colisão e remoção de blocos*/
                removeBlocks(blocksList, &score, &ball);
            
            } else if (state_game == 2) { // Estado de pausa

                /*Desenhar elementos do jogo*/ 
                game_field  (blocksList, score, state_game);
                bola9x9     (ball.ballPositionX, ball.ballPositionY, 0xFC18);
                video_box   (bar.coordX - BAR_SIZE, bar.coordY - BAR_WIDHT, bar.coordX + BAR_SIZE,bar.coordY + BAR_WIDHT , 0xFC18);
                video_show  ();
            
            } else if (state_game == 3) {   // Tela de pause/exit

                /*Desenhar elementos do jogo*/ 
                game_field  (blocksList, score, state_game);
                bola9x9     (ball.ballPositionX, ball.ballPositionY, 0xFC18);
                video_box   ( bar.coordX - BAR_SIZE, bar.coordY - BAR_WIDHT, bar.coordX + BAR_SIZE,bar.coordY + BAR_WIDHT , 0xFC18);
                video_show  ();
            }
        }
        /*Finalização do jogo*/

        if (checkLose(&ball) == 0) { // Se o jogador perdeu     
            do {
                KEY_read(&buttons);  // Aguarda o jogador apertar o botão 1 para voltar ao menu

                video_clear();
                video_erase();
                screen_defeat(score);
                video_show();
            } while (buttons != 1);
        }
        else {                  // Se o jogador ganhou
            screen_victory();
        }
    }
   
    return 0;
}

