#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>


void consumer(){

        char c;
        char turn;
        FILE *TURN, *DATA;

        // open in APPEND mode
        if ( (DATA = fopen("DATA.txt", "w+")) == NULL ){
                perror("fopen DATA.txt failed");
                exit(EXIT_FAILURE);
        }

	// LOOP until internal break
	while(1){
	        // open TURN READ-ONLY
                if ( (TURN = fopen("TURN.txt", "r")) == NULL ){
                        perror("fopen TURN.txt failed");
                        exit(EXIT_FAILURE);
                }

                turn = fgetc(TURN);
                fclose(TURN);
		// printf("Turn is: %d\n", turn);
                // if it's not the consumer's turn, wait and check again in 500ms
                if (turn == '0')
                {
                        usleep(500);
                        continue;
                } else if (turn == '2') {
			break;
		}

                // get next char from file and print
                c = fgetc(DATA);
		printf("%c", c);

                // consumer is done for this round, give turn to producer
                // without locks, having the prod/cons give each other permission
                // is the only way to avoid rc
                // overwrite TURN
                if ( (TURN = fopen("TURN.txt", "w")) == NULL ){
                        perror("fopen TURN.txt failed");
                        exit(EXIT_FAILURE);
                }
                fprintf(TURN, "0");
                fclose(TURN);
        }
        fclose(DATA);
}
