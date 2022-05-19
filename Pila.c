#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct estructura{
    int codigo;
    char nombre[10];
    struct estructura *siguiente;
} nodo;

typedef nodo *pNodo;
typedef nodo *Pila;

nodo* nuevo();
nodo* nuevo(){
    nodo *p;
    p = (nodo*) malloc(sizeof(nodo));
    p->siguiente = NULL;
    return(p);
}
bool esVacia(Pila*);
void push(Pila*, int, char*);
void pop(Pila*);
void empty(Pila*);
void mostrarPila(Pila*);
void tamanoPila(Pila*);
void encontrarElemento(Pila*, int);

int main()
{

    Pila miPila = NULL;
    /*push(&miPila, 20, "Luis");
    push(&miPila, 21, "Luis1");
    push(&miPila, 22, "Luis2");
    push(&miPila, 23, "Luis3");*/

    char nombre[10];
    int codigo = 0;

    int menu = 0;



    while(menu != 6){


        printf("0) Insertar\n");
        printf("1) Sacar\n");
        printf("2) Vaciar\n");
        printf("3) Mostrar\n");
        printf("4) Tamanyo Pila\n");
        printf("5) Buscar Elemento\n");
        printf("6) Salir\n");
        printf("Que quieres hacer: ");
        scanf("%i", &menu);
        fseek(stdin,0,SEEK_END);
        printf("\n");
        system("cls");

        switch(menu){
            case 0:
                // PEDIR DATOS
                printf("Dime codigo: ");
                scanf("%i", &codigo);
                printf("Dime nombre: ");
                scanf("%s", &nombre);
                fseek(stdin,0,SEEK_END);

                // AÑADIR a PILA
                push(&miPila, codigo, nombre);

                // MOSTRAR RESULTADO
                mostrarPila(&miPila);

                break;
            case 1:
                pop(&miPila);
                break;
            case 2:
                empty(&miPila);
                mostrarPila(&miPila);
                break;
            case 3:
                mostrarPila(&miPila);
                break;
            case 4:
                tamanoPila(&miPila);
                break;
            case 5:
                 // PEDIR DATOS
                printf("Dime codigo: ");
                scanf("%i", &codigo);

                // BUSCAR
                encontrarElemento(&miPila, codigo);

                break;
            case 6 :
                printf("Bye :)\n");
                break;
            default:
                printf("\nNo te he entendido.\n\n");

        }
    }

    return 0;
}

bool esVacia(Pila *pila){
    pNodo miNodo;
    miNodo = *pila;
    return miNodo == NULL;
}

void empty(Pila *pila){
    pNodo miNodo;
    int next = 0;
    do {
        miNodo = *pila;
        if(miNodo){
            *pila = miNodo->siguiente;

            free(miNodo);
        } else{
            next = 1;
        }
    } while(next == 0);
}

void push(Pila *pila, int v, char* n){

    pNodo miNodo;
    miNodo = nuevo();
    miNodo->codigo = v;
    strcpy(miNodo->nombre,n);

    miNodo->siguiente = *pila;

    *pila = miNodo;

}

void pop(Pila *pila){

    pNodo miNodo;
    miNodo = *pila;
    if( !esVacia(pila) ){
        *pila = miNodo->siguiente;

        free(miNodo);

        mostrarPila(pila);
    } else {
        printf("\nLista vacia...");
    }

}


void encontrarElemento(Pila* pila, int codigo){
    pNodo miNodo;
    miNodo = *pila;

    if(!esVacia(pila)){
        int indice = 0;
        int timesFound = 0;
        while(miNodo != NULL){
            if(codigo == miNodo->codigo){
                printf("Encontrado en el indice %i.\n",indice);
                timesFound++;
            }
            indice++;
            miNodo = miNodo->siguiente;

        }
        if(timesFound==0){
            printf("No se ha encontrado el elemento...");
        }
    } else {
        printf("La pila esta vacia.\n\n");
    }

    printf("\n\n");


}
void tamanoPila(Pila* pila){
    pNodo miNodo;
    miNodo = *pila;

    int size = 0;

    if(!esVacia(pila)){
        while(miNodo != NULL){
            size++;
            miNodo = miNodo->siguiente;
        }
        printf("La pila tiene %i elementos.\n\n", size);
    } else {
        printf("La pila esta vacia.\n\n");
    }




}

void mostrarPila(Pila* pila){
    pNodo miNodo;
    miNodo = *pila;
    printf("\nPILA: \n");
    while(miNodo != NULL){
        printf("Codigo: %d, Nombre: %s\n", miNodo->codigo, miNodo->nombre);
        miNodo = miNodo->siguiente;
    }
    printf("\n");
}
