#include "header.h"

void inserta(int i , int j , int costo, Grafo **lista){//vamos a usar una lista enlazada para almacenar los datos de la matriz de costos
    
    if(*lista == NULL){
        *lista = (Grafo*)malloc(sizeof(Grafo));
         assert(lista != NULL);
        (*lista)->a = creaArista(i, j, costo);
        (*lista)->sig = NULL;
    }else{ 
            Grafo *nuevo = (Grafo*)malloc(sizeof(Grafo));
            assert(nuevo != NULL);
            if((*lista)->a->costo >= costo){
                nuevo->a = creaArista(i, j, costo);
                nuevo->sig = *lista;
                *lista = nuevo;
            
            }else if(((*lista)->a->costo < costo )&& ((*lista)->sig != NULL )&&( (*lista)->sig->a->costo > costo) ){
                nuevo->a = creaArista(i, j, costo);
                nuevo->sig = (*lista)->sig;
                (*lista)->sig = nuevo;
            }else{
                inserta(i, j, costo, &(*lista)->sig);
            }
        }
    
  
   
}

Arista* creaArista(int i, int j, int costo){//se encarga de crear la arista a colocar en la lista enlazada
    Arista *nueva = (Arista*)malloc(sizeof(Arista));//reservo memoria
     assert(nueva != NULL);
    nueva->verticeU = i;
    nueva->verticeV = j;
    nueva->costo = costo;
    return nueva;
}

void mostrar(Grafo *lista){
    if(lista != NULL){
        printf("{ U: %d, V: %d, Costo: %d}\n", lista->a->verticeU, lista->a->verticeV, lista->a->costo );
        mostrar(lista->sig);
    }
}

void kruskal(Grafo **lista){//recibo una lista ordenada
    int j = 0;//j es el indice de resultado
    int i, v;//v se usa para asignar vertice raiz a los subconjuntos
    int sumaCosto = 0;//s suma el costo del arbol reducido
    Arista *resultado = (Arista*)malloc((VERTICES) * sizeof(Arista));//genero un array que almacenara las aristas del arbol reducido
     assert(resultado != NULL);
    Subconjunto *sub = (Subconjunto*)malloc(VERTICES * sizeof(Subconjunto));//genero un array de subconjuntos
     assert(sub != NULL);
  Grafo *p = (*lista);//uso p como auxiliar para recorrer el grafo dentro del bucle

    for(v = 0; v < VERTICES; ++v){//asigna raiz a los subconjuntos e inicializa la altura de todos en 0
        sub[v].raiz = v;
        sub[v].altura = 0;
    }

  

    while(j < VERTICES -1){//limito la cantidada de arista del arbol resultante y filtro el arbol original
        Arista *ari = p->a;
        int x = encuentra(sub, ari->verticeU);//envio el subconjunto y el vertice a encuentra
        int y = encuentra(sub, ari->verticeV);
        if(x != y){//si los vertices son distintos
            resultado[j] = *ari;//guardamos el resultado
            unir(sub, x, y);//los unimos 
            j++; 
        }
        p = p->sig;//recorro la lista
    }

    for(i = 0; i < j; i++){
        printf("{ U: %d, V: %d, Costo: %d}\n", resultado[i].verticeU, resultado[i].verticeV, resultado[i].costo);
        sumaCosto += resultado[i].costo;
    }

    printf("\nCosto total = %d\n", sumaCosto);

    free(sub);
    free(resultado);
}

int encuentra(Subconjunto *sub, int vertice){//recibe el subconjunto y el vertice que sera raiz de ese subconjunto
    if(sub[vertice].raiz != vertice){ //si la raiz del subconjunto no corresponde con el vertice recibido
        sub[vertice].raiz = encuentra(sub, sub[vertice].raiz);//evaluo con encuentra la raiz usando recursividad hasta que el vertice sea igual a la raiz

    }
    return sub[vertice].raiz;//entonces retornamos la raiz que es igual al vertice recibido
}

void unir(Subconjunto *sub, int raizx, int raizy){

    if(sub[raizx].altura < sub[raizy].altura){//si x tine menos altura que y
        sub[raizx].raiz = raizy;//entonces y se vuelve raiz de x;
    }else if(sub[raizx].altura > sub[raizy].altura){//si y tiene mayor altura que y
        sub[raizy].raiz = raizx;//x se vuelve raiz de y
    }else{//si son iguales
        sub[raizy].raiz = raizx;//damos prioridad a x y lo converitmos en raiz de y
        sub[raizx].altura++;//incremento la altura de x dado que es raiz de y
    }
}