#include <stdio.h>
#include <stdlib.h>

typedef struct nodo nodo;

struct nodo{
	struct nodo *anterior;
	int dato;
	struct nodo *siguiente;
};

nodo *inicio=NULL;
nodo *ultimo=NULL;

nodo *crearnodo(int dato){
	nodo *nuevo=NULL;
	nuevo=(nodo *)malloc(sizeof(nodo));
	if(nuevo!=NULL){
		nuevo->dato=dato;
		nuevo->siguiente=NULL;
		nuevo->anterior=NULL;
	}
	return nuevo;
}

void insertarFinal(int dato){
	nodo *nuevo = crearnodo(dato);
	if(inicio==NULL){
		inicio = nuevo;
		ultimo = nuevo;
	}else{
		nuevo->anterior = ultimo;
		ultimo->siguiente = nuevo;
		ultimo=nuevo;
	}
}

void insertarInicio(int dato){
	nodo *nuevo = crearnodo(dato);
	if(inicio==NULL){
		inicio = nuevo;
		ultimo = nuevo;
	}else{
		nuevo->siguiente = inicio;
		inicio->anterior = nuevo;
		inicio = nuevo;
	}
}



void recorrerVuelta(){
	nodo *tracker = ultimo;
	if(ultimo!=NULL){
		while(tracker!=NULL){
			printf("%d ", tracker->dato);
			tracker = tracker->anterior;
		}
		printf("\n");
	}else{
		printf("La lista se encuentra vacia");
	}
}

void recorrer(){
	nodo *tracker = inicio;
	if(inicio!=NULL){
		while(tracker!=NULL){
			printf("%d ", tracker->dato);
			tracker = tracker->siguiente;
		}
		printf("\n");
	}else{
		printf("La lista se encuentra vacia");
	}
}

void recorrerOrdenado(){
	nodo *externo = inicio;
	while(externo != NULL){
		nodo *interno = externo->siguiente;
		while(interno != NULL){
			if(externo->dato < interno->dato){
				int aux = externo->dato;
				externo->dato = interno->dato;
				interno->dato = aux;
			}
			interno = interno->siguiente;
		}
		externo = externo->siguiente;
	}
	recorrer();
}

int *array;
int n,men;

int main(){
	scanf("%d", &n);
	array = (int*)malloc(n);
	for(int i=0;i<n;i++){
		scanf("%d", &array[i]);
		insertarFinal(array[i]);
	}
	scanf("%d", &men);
	printf("\n");
	switch(men){
	case 1: 
		recorrerVuelta();
		break;
	case 2:
		recorrer();
		break;
	case 3:
		recorrerOrdenado();
		break;
	}
	return 0;
}
