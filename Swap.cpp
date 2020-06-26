//g++ orden.cpp -std=c++11 -lpthread -o orden.out
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

void imprimir(int arreglo[],int longitud){
	for(int i=0;i<longitud;i++){
		cout<<arreglo[i]<<" ";
	}
	cout<<endl;
}

int Particion(int arreglo[], int inicio, int fin,int & contador)  
{  
	 int pivote=arreglo[fin];
	 int i=inicio-1;

	 int auxiliar;	 

	 for(int j=inicio;j<fin;j++){
			if(arreglo[j]<=pivote){
				i=i+1;
				auxiliar=arreglo[i];
				arreglo[i]=arreglo[j];
				arreglo[j]=auxiliar;
			   contador++;
			}
	 }
	 auxiliar=arreglo[i+1];
	 arreglo[i+1]=arreglo[fin];
	 arreglo[fin]=auxiliar;
	 contador++;

	return i+1;
	
}  

void QuickSort(int arreglo[], int inicio, int fin,int& contador) 
{  
	if(inicio<fin){
		int medio=Particion(arreglo,inicio,fin, contador);
		QuickSort(arreglo,inicio,medio-1,contador);
		
		QuickSort(arreglo,medio+1,fin,contador);
	}
}


int main(){

	 int nro_casos;
    int longitud;

    cin>>nro_casos;
	 
    int contador=0;

    for(int i=0;i<nro_casos;i++){
        cin>>longitud;

		  int * valores;
		  valores = new int [longitud];

        for(int j=0;j<longitud;j++){
            cin>>valores[j];
        }
		  
		  QuickSort(valores,0,longitud-1,contador);

        cout<<"La mejor cantidad de swaps de trenes es "<<contador<<" swaps."<<endl;

		  contador=0;
		  delete [] valores;
    }

   return 0;

}
