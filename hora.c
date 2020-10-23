#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

void TyF(int sig){
	time_t tiempo; 
	char* fecha; 
	tiempo= time(NULL);
	fecha=ctime(&tiempo);
	printf("señal recibida SIGUSR1: %s", fecha);
}

int main(){
	while(1){
		printf("Programa hora ejecutandose . PID=%d\n", getpid());
		while(1){
			printf("Listo para recibir la señal SIGUSR1\n");
			signal(SIGUSR1,TyF);
			sleep(11);
		}
	}
}
