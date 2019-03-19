///////////////////////////////////////
//   Datos estadisticos				  /
//   Fecha: 17/03/2019                /
// Autor: Arturo Bautista de Jesus   /
//	 Version: 1.0                     / 
///////////////////////////////////////


/*librerias*/
#include<stdio.h>
#include<time.h>
#include <math.h>


/*prototipos de las funciones*/
void generarDA(int vector[]);
void frecuenciaDatos(int vector[]);
void medidasEstadisticas();
void datosAleatorios(int vector[]);
float obtenerPromedio(int vector[]);
float obtenerVarianza(int vector[]);
float obtenerDesviacion(float varianza, int vector[]);

int datosA[50];/*vector donde se almacenaran los numeros aleatorios*/
float arrayF[10][5];

 /*arreglo bidimensional que almacenara la frecuencia absoluta*/

int main(){
	
	int opcion; /*variable auxiliar para el ciclo do while*/
	do{
		
		system("cls"); /*limpiamos lo que haya en pantalla*/
		/*menu principal*/
		printf("Generar datos aleatorios ... [1]\n");
		printf("Frecuencia de los datos  ... [2]\n");
		printf("Medidas estadisticas     ... [3]\n");
		printf("Salir                    ... [4]\n");
		printf("Elija una opcion: "); scanf("%i",&opcion);
		
		switch(opcion){
			case 1:
				generarDA(datosA);
				break;
			case 2:
				frecuenciaDatos(datosA);
				break;
			case 3:
				medidasEstadisticas(datosA);
				break;
			
		}	
		
	}while(opcion != 4);
}

/*Funciones*/

void generarDA(int vector[]){
	
	system("cls");
	printf("Generar Datos Aleatorios \n\n");
	
	datosAleatorios(vector); /*funcion que genera los datos aleatorios y los guarda en el vector*/
	
	getch();
}

void frecuenciaDatos(int vector[]){
	system("cls");
	printf("Frecuencia de los datos \n\n");
	
	int lista[] = {1,2,3,4,5,6,7,8,9,10};
	float fa[10] = {};
	float fr[10] = {}, division = 0.00;
	float fac[10] = {};
	float fra[10] = {};
	float array[10][5] = {{1,0,0,0,0},
						 {2,0,0,0,0},
						 {3,0,0,0,0},
						 {4,0,0,0,0},
						 {5,0,0,0,0},
						 {6,0,0,0,0},
						 {7,0,0,0,0},
						 {8,0,0,0,0},
						 {9,0,0,0,0},
						 {10,0,0,0,0}}
						 ;
	int i,j,tam = 50;
	
	
	
	for(i = 0; i < tam; i++){
		for(j = 0; j < 10; j++){
			if(vector[i] == lista[j]){
				fa[j]++;	
			}
		}
	}
	for(i = 0; i < 10; i++){
		array[i][1] = fa[i];
	}
	
	for(i = 0; i < 10; i++){
		division = (fa[i]/50);
		fr[i] = division;
		array[i][2] = fr[i];
	}
	
	float suma = 0;
	for(i = 0; i < 10; i++){
		suma = suma + fa[i]; 
		fac[i] = suma;
		array[i][3] = fac[i];
	}
		
	 suma = 0;
	for(i = 0; i < 10; i++){
		suma = suma + fr[i]; 
		fra[i] = suma;
	}
	
	for(i = 0; i < 10; i++){
		array[i][4] = fra[i];
	}

	printf("Rango de los datos  || Frecuencia absoluta || Frecuencia relativa || Frecuencia acumulada || Frecuencia relativa acumulada \n");
	for(i = 0; i < 10; i++){
		for(j = 0; j < 5; j++){
			
			printf("  %.1f -                    ",array[i][j]);
		}
		
		printf("\n");
	}
	
	getch();
	
}

void medidasEstadisticas(int vector[]){
	float varianza,desviacion,media;
	
	varianza = obtenerVarianza(vector);
	desviacion = obtenerDesviacion(varianza,vector);
	media = obtenerPromedio(vector);
	int moda = obtenerModa(vector);
	
	system("cls");
	printf("\n Medidas Estadisticas \n");
	
	printf("La media es: %.2f\n",media);
	printf("La varianza es: %.2f \n",varianza);
	printf("La desviación estandar es: %.2f \n",desviacion);
	printf("La moda es: %i\n",moda);
	
	getch();
}
int obtenerModa(int vector[]){
	int rango,i,tam = 50;
	int mas_grande;
	int valor_moda;
	int frecuencias[11] = {0};
	for ( i = 0; i < tam; i++ ) {
	frecuencias[ vector[i] ]++;
	}

	for ( rango = 1; rango <= tam; rango++ ) {
	if ( frecuencias[rango] > mas_grande ) {
			mas_grande = frecuencias[rango];
			valor_moda = rango;
		}
	}
	
	return valor_moda;
}
float obtenerPromedio(int vector[]){
	float suma = 0;
	int i, tam = 50;
	for(i = 0; i < tam; i++){
		suma+=vector[i];
	}
	
	return suma/tam;
}	
float obtenerVarianza(int vector[]){
	
	int tam = 50, i;
	float promedio = obtenerPromedio(vector);
	float varianza = 0;
	for(i = 0; i < tam; i++){
		varianza+= pow((vector[i] - promedio),2.0);
	}	
	
	return varianza / (tam -1);
}

float obtenerDesviacion(float varianza, int vector[]){
	
	if(varianza == 0){
		float varianza = obtenerVarianza(vector);
	}
	return sqrt(varianza);
}
void datosAleatorios(int vector[]){
	srand(time(NULL));
	int i;
	for(i = 0; i < 50; i++){
		
		vector[i] = 1 + rand() %((10+1) - 1);/*genera un numero aleatorio y lo guarda en la posicion i del arreglo*/	
	}
	
	int j;
	for(j = 0; j < 50; j++){
		printf("Dato %i: %i \n",j+1,vector[j]);/*imprime los numeros aleatorios guardados en el vector*/
	}
}












