//g++ orden.cpp -std=c++11 -lpthread -o orden.out
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <chrono>
#include <time.h>
#include <bits/stdc++.h>
#include <fstream>
#include <thread>

#define MX 2000000000

using namespace std;

int relOrden(const void * numero1, const void * numero2) 
{ 
    return ( *(int*)numero1 - *(int*)numero2 ); 
} 

void imprimir(unsigned int arreglo[],int longitud){
	for(int i=0;i<longitud;i++){
		cout<<arreglo[i]<<" ";
	}
	cout<<endl;
}

void medioEstadistica(unsigned int valores[], int n){
		 float promedio=0;
		 float desviacion=0;
		 unsigned int medio;

			//halla el promedio
			for(int j=0;j<n;j++){
				promedio=promedio+valores[j];
			}
			promedio=promedio/n;

			//hallamos la desviacion estandar
			/*for(int j=0;j<n;j++){
				desviacion=desviacion+pow(valores[j]-promedio,2);
			}
			desviacion=pow(desviacion/n,0.5);*/

			//comienza a buscar el valor medio
			int j=0;
			int jj;

			//recorre valores en caso de haber caido en un maximo inicial
			medio=valores[j];
			while(valores[j]>promedio){
				j++;
				medio=valores[j];
			}

			//ubica el valor medio
			for(jj=j;jj<n;jj++){
				if(valores[jj]<promedio && medio<valores[jj]){
					medio=valores[jj];
				}
			}
		
			cout<<"medio="<<endl;
}

void medioPorOrdenamiento(unsigned int valores[], int n){
	unsigned int medio;
	qsort(valores, n, sizeof(unsigned int), relOrden);
	if(n%2==0){
		medio=(int)floor(n/2)-1;
	}else{
		medio=(int)floor(n/2);
	}
	cout<<"Ordenamiento: "<<valores[medio]<<endl;
}

int main(){

	 int n=8000;
	 int medio;
	 string texto;
	 string tempStr;

	 unsigned int * valores;
	 valores = new unsigned int [n];
	 int j=0;

	
	 for(int i=0;i<n;i++){
			j=0;
			getline(cin,texto);
	 	  istringstream isstream(texto);
		  isstream >> tempStr;
			while(!isstream.eof()){
      	 isstream >> tempStr;
      	 valores[j]=atoi(tempStr.c_str());
      	 j++;
   		}
			//imprimir(valores,n);
			medioEstadistica(valores,n);
	 }



	 delete [] valores;

   return 0;

}
