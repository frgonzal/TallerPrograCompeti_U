#include <bits/stdc++.h>
using namespace std;

vector <vector <int> > grafo; //la lista de adyacencia
vector <int> dist; //para guardar la distancia
vector <int> parent; //para guardar el padre de cada nodo

void bfs(int s, int n){ //nodo inicial, cantidad de nodos
    dist.assign(n, -1);
    parent.assign(n, -1);

    queue <int> Cola;
    dist[s] = 0;
    Cola.push(s);
    while(!Cola.empty()){
        int u = Cola.front(); Cola.pop();

        for( int v : grafo[u]){         //por cada vecino de u
            if(dist[v] == -1){          //veo si ya lo visite
                dist[v] = dist[u] + 1;  //guardo la distancia hasta v
                parent[v] = u;          //guardo el padre de v
                Cola.push(v);           //lo agrego a la cola
            }
        }
    }

}



