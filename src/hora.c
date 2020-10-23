#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>      //Se importan las librerias para el corecto funcionamiento del algoritmo
#include <time.h>
#include <signal.h>

int main(){
	while(1){
		printf("Programa hora ejecutandose . PID=%d\n", getpid());     //El primer while imprimira continuamente el PID por pantalla
		while(1){
			printf("Listo para recibir la señal SIGUSR1\n");
			signal(SIGUSR1,TyF);             //con la libreria signal se importa una funcion la cual tomara la señaal y ejecutara nuestra funcion TyH
			sleep(11);
		}
	}
}

void TyF(int sig){             // se crea una funcion para obtener la fecha y la hora
	time_t tiempo;         // usando la libreria time obtenemos los datos de la fecha y hora
	char* fecha; 
	tiempo= time(NULL);
	fecha=ctime(&tiempo);
	printf("señal recibida SIGUSR1: %s", fecha);//una vez obtenidos los datos se muestran por pantalla
}
