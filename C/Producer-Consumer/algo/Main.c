#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void producer();
void consumer();

int main(){

	int pid;
	pid = fork();

	if( pid < 0 ) {
		perror("Creating child process failed");
		exit(EXIT_FAILURE);
	} else if (pid == 0){
		producer();
	} else {
		consumer();
	}
}
