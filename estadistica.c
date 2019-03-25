///////////////////////////////////////
//   Datos estadisticos	              /
//   Fecha: 17/03/2019                /
// Autor: Arturo Bautista de Jesus    /
//	 Version: 1.0                 / 
///////////////////////////////////////


/*librerias*/
#include<stdio.h>
#include<time.h>
#include <math.h>


/*prototipos de las funciones*/
void generarDA(int vector[]);
void frecuenciaDatos(int vector[]);
void medidasEstadisticas();
float obtenerPromedio(int vector[]);
float obtenerVarianza(int vector[]);
float obtenerDesviacion(float varianza, int vector[]);

int datosA[50];/*vector donde se almacenaran los numeros aleatorios*/
float arrayF[10][5]; /*matriz que almacenara los datos de la tabla de frecuencias*/


int main(){/*programa principal, cuerpo del programa etc..*/
	
	int opcion; /*variable auxiliar para el ciclo do while*/
	do{
		
		system("cls"); /*limpiamos lo que haya en pantalla*/
		/*menu principal*/
		printf("Generar datos aleatorios ... [1]\n");
		printf("Frecuencia de los datos  ... [2]\n");
		printf("Medidas estadisticas     ... [3]\n");
		printf("Salir                    ... [4]\n");
		printf("Elija una opcion: "); 
		scanf("%i",&opcion);/*almacena el valor tecleado en la variable*/
		
		switch(opcion){
			case 1:
				/* si elijio la opcion 1 el programa se dirijara a este case*/
				generarDA(datosA);/*manda a llamar la funcion que genera los datos aleatorios*/
				break;
			case 2:
				/* si elijio la opcion 2 el programa se dirijara a este case*/
				frecuenciaDatos(datosA);/*manda a llamar la funcion que muestra las tablas de frecuencias de los datos*/
				break;
			case 3:
				/* si elijio la opcion 3 el programa se dirijara a este case*/
				medidasEstadisticas(datosA);/*manda a llamar a la funcion que muestra las medidas estadisticas*/
				break;
			
		}	
		
	}while(opcion != 4);/*repetira todas las intrucciones que esten dentro del "do while" mientras la variable opcion siga siendo diferente de 4*/  
}

/*Funciones*/

void generarDA(int vector[]){
	
	system("cls");/*limpia lo que hay en pantalla*/
	printf("Generar Datos Aleatorios \n\n");/*imprime mensaje en pantalla*/
	
	srand(time(NULL));/*inicializa el generador de numeros aleatorios*/
	
	int i;
	for(i = 0; i < 50; i++){
		
		vector[i] = 1 + rand() %((10+1) - 1);/*genera un numero aleatorio y lo guarda en la posicion i del vector*/	
	}
	
	int j;
	for(j = 0; j < 50; j++){
		printf("Dato %i: %i \n",j+1,vector[j]);/*imprime los numeros aleatorios guardados en el vector*/
	}
	
	getch();/*detiene el programa hasta que se apriete cualquier tecla*/
}

void frecuenciaDatos(int vector[]){
	
	system("cls");/*limpiamos lo que este en pantalla*/
	printf("Frecuencia de los datos \n\n");
	
	int lista[] = {1,2,3,4,5,6,7,8,9,10}; /*arreglo que contiene los rangos de los datos generados*/
	float fa[10] = {};/*arreglo que guarda la frecuencia absoluta de los datos*/
	float fr[10] = {};/*arreglo que guarda la frecuencia relativa de los datos*/
	float fac[10] = {};/*arreglo que guarda la frecuencia acumulada de los datos*/
	float fra[10] = {};/*arreglo que guarda la frecuencia relativa acumulada de los datos*/
	float division = 0.00;/*variable auxiliar para guardar el resultado de una division*/
	float array[10][5] = {{1,0,0,0,0},
						 {2,0,0,0,0},
						 {3,0,0,0,0},
						 {4,0,0,0,0},
						 {5,0,0,0,0},
						 {6,0,0,0,0},
						 {7,0,0,0,0},
						 {8,0,0,0,0},
						 {9,0,0,0,0},
						 {10,0,0,0,0}}/*matriz que guardara todas las frecuencias de los datos*/
						 ;
	int i,j,tam = 50; /*variables auxiliares*/
	
	
	for(i = 0; i < tam; i++){
		for(j = 0; j < 10; j++){
			if(vector[i] == lista[j]){
				fa[j]++;/*se calcula la frecuencia acumulada y se agrega al vector*/	
			}
		}
	}
	
	for(i = 0; i < 10; i++){
		array[i][1] = fa[i];/*se agrega los datos de la frecuencia acumulada a la matriz de las frecuencias*/
	}
	
	for(i = 0; i < 10; i++){
		division = (fa[i]/50);
		fr[i] = division; /*se calcula la frecuencia relativa y se guarda en un vector*/
		array[i][2] = fr[i];/*los datos de la frecuencia relativa contenidos en el vector se agregan a la matriz de frecuencias*/
	}
	
	float suma = 0;
	for(i = 0; i < 10; i++){
		suma = suma + fa[i]; 
		fac[i] = suma; /*se calcula la frecuencia acumulada y se agregan los datos al vector*/
		array[i][3] = fac[i];/*los datos de la frecuencia acumulada contenidos en el vector se agregan a la matriz de frecuencias*/
	}
		
	 suma = 0;
	for(i = 0; i < 10; i++){
		suma = suma + fr[i]; 
		fra[i] = suma;/*se calcula la frecuencia relativa acumulado y se agregan los datos al vector*/
	}
	
	for(i = 0; i < 10; i++){
		array[i][4] = fra[i];/*los datos de la frecuencia relativa acumulada contenidos en el vector se agregan a la matriz de frecuencias*/
	}

	printf("Rango de los datos  || Frecuencia absoluta || Frecuencia relativa || Frecuencia acumulada || Frecuencia relativa acumulada \n");
	for(i = 0; i < 10; i++){
		for(j = 0; j < 5; j++){
			
			printf("  %.1f -                    ",array[i][j]); /*se imprime la matriz con los datos de las frecuencias*/
		}
		
		printf("\n");/*salto de linea*/
	}
	
	getch();
	
}

void medidasEstadisticas(int vector[]){
	float varianza,desviacion,media;/*variables auxiliares*/
	
	varianza = obtenerVarianza(vector); /*se guarda en la variable el dato que devuelve el metodo*/
	desviacion = obtenerDesviacion(varianza,vector); /*se guarda en la variable el dato que devuelve el metodo*/
	media = obtenerPromedio(vector); /*se guarda en la variable el dato que devuelve el metodo*/
	int moda = obtenerModa(vector); /*se guarda en la variable el dato que devuelve el metodo*/
	
	system("cls");
	printf("\n Medidas Estadisticas \n");
/*se imprimen las variables con los datos contenidos*/
	printf("La media es: %.2f\n",media);
	printf("La varianza es: %.2f \n",varianza);
	printf("La desviación estandar es: %.2f \n",desviacion);
	printf("La moda es: %i\n",moda);
	
	getch();
}
int obtenerModa(int vector[]){
	int rango,i,tam = 50;/*variables auxiliares*/
	int mas_grande;/*variable auxiliar*/
	int valor_moda;
	
	int frecuencias[11] = {0}; /*arreglo que contiene  datos de las frecuencias*/
	
	for ( i = 0; i < tam; i++ ) {
	frecuencias[vector[i]]++;/*obtenemos las datos del vector y lo guardamos en el vector "frecuencias"*/
	}

	for ( rango = 1; rango <= tam; rango++ ) {
	if ( frecuencias[rango] > mas_grande ) {
			mas_grande = frecuencias[rango];
			valor_moda = rango;/*calculamos el dato que mas se repite del vector*/
		}
	}
	
	return valor_moda;/*devolvemos el valor*/
}
float obtenerPromedio(int vector[]){
	float suma = 0;
	int i, tam = 50;
	for(i = 0; i < tam; i++){
		suma+=vector[i];/*calculamos el promedio*/
	}
	
	return suma/tam;/*devolvemos el dato contenido en la variable*/
}	
float obtenerVarianza(int vector[]){
	
	int tam = 50, i;
	float promedio = obtenerPromedio(vector);
	float varianza = 0;
	for(i = 0; i < tam; i++){
		varianza+= pow((vector[i] - promedio),2.0); /*calculamos la varianza*/
	}	
	
	return varianza / (tam -1);/*devolvemos el dato contenido en la variable*/
}

float obtenerDesviacion(float varianza, int vector[]){
	
	if(varianza == 0){
		float varianza = obtenerVarianza(vector);/*calculamos la desviacion estandar*/
	}
	return sqrt(varianza);/*devolvemos el dato contenido en la variable*/
}
