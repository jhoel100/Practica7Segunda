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
  
void heapificar(unsigned int arr[], int n, int i) 
{ 
    unsigned int mayor = i; 
    int l = 2*i + 1;
    int r = 2*i + 2;
  
    if (l < n && arr[l] > arr[mayor]) 
        mayor = l; 
  
    if (r < n && arr[r] > arr[mayor]) 
        mayor = r; 
  
    if (mayor != i) 
    { 
        swap(arr[i], arr[mayor]); 
  
        heapificar(arr, n, mayor); 
    } 
} 
  
void heapSort(unsigned int arr[], int n) 
{ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapificar(arr, n, i); 
  
    for (int i=n-1; i>0; i--) 
    { 
        swap(arr[0], arr[i]); 

        heapificar(arr, i, 0); 
    } 
} 
  

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

int main(){

	 int n=8000;
	 int medio;
	 float promedio=0;
	 float desviacion=0;

	 unsigned int * valores;
	 valores = new unsigned int [n];

	 int j;
	 
	 for(int i=0;i<n;i++){
			//genera el arreglo de randoms
			for(j=0;j<n;j++){
				valores[j]=rand()%MX;
			}

			//Por ordenamiento
			heapSort(valores, n);

			if(n%2==0){
				medio=(int)floor(n/2)-1;
			}else{
				medio=(int)floor(n/2);
			}
			//cout<<"Ordenamiento: "<<valores[medio]<<endl;

	 }



	 delete [] valores;

   return 0;

}
