#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>


void producer(){
	
	char c;
	char turn;
	FILE *file, *TURN, *DATA;

	// open READ-ONLY
	if ( (file = fopen("test.txt", "r")) == NULL){
		perror("fopen file failed");
		exit(EXIT_FAILURE);
	}

	c = fgetc(file);
	// open in APPEND mode
	if ( (DATA = fopen("DATA.txt", "w+")) == NULL ){
		perror("fopen DATA.txt failed");
		exit(EXIT_FAILURE);
	}

	while(!feof(file)){
		// open TURN READ-ONLY
		if ( (TURN = fopen("TURN.txt", "r")) == NULL ){
			perror("fopen TURN.txt failed");
			exit(EXIT_FAILURE);
		}

		turn = fgetc(TURN);
		fclose(TURN);
		// if it's not the producer's turn, wait and check again in 500ms
		if (turn != '0')
		{
			usleep(500);
			continue;
		}

		
		

		// write char to end of file
		//printf("%c", c);	
		fprintf(DATA, "%c", c);
		fflush(DATA);
	
		// get next char from file
		c = fgetc(file);

		// producer is done for this round, give turn to consumer
		// without locks, having the prod/cons give each other permission
		// is the only way to avoid rc
		// overwrite TURN
		if ( (TURN = fopen("TURN.txt", "w")) == NULL ){
			perror("fopen TURN.txt failed");
			exit(EXIT_FAILURE);
		}
		fprintf(TURN, "1");
		fclose(TURN);
	}
	fprintf(DATA, "%s", "\n\0");
	fclose(DATA);
	// ON prod exit, put 2 in TURN to tell cons about it
	if ( (TURN = fopen("TURN.txt", "w")) == NULL ){
		perror("fopen TURN.txt failed");
		exit(EXIT_FAILURE);
	}
	fprintf(TURN, "2");
	fclose(TURN);
}
