#include <bits/stdc++.h>
using namespace std;

vector <vector <int> > grafo;
vector <int> visited;

void dfs_recursivo(int s, vector <vector <int> > &grafo, vector <int> &visited){
    visited[s] = 1;                             //marcamos que pasamos por s
    for(int v : grafo[s]){                      //por cada vecino de s 
        if(visited[v] == 0){                    //si es que no lo hemos visitado
            dfs_recursivo(v, grafo, visited);   //lo visitamos
        }
    }
}


void dfs_iterativo(int s, vector < vector <int> > &grafo, vector <int> &visited){
    stack <int> Pila;                  
    Pila.push(s);                       //metemos a la pila el nodo inicial

    while(!Pila.empty()){               
        int u = Pila.top(); Pila.pop(); //tomamos un nodo
        visited[u] = 1;                 //lo marcamos como visitado

        for(int v: grafo[u]){           //para cada vecino del nodo
            if(visited[v] == 0){        //vemos si lo visitamos
                visited[v] = 1;         //si es que no, lo marcamos como visitado y
                Pila.push(v);           //lo metemos a la pila
            }
        }
    }
}




