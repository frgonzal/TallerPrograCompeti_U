#include <bits/stdc++.h>
using namespace std;

void bfs(int n, int s, vector<vector<int>> grafo, vector<int> &dist, vector<int> &parent){

    dist.assign(n,-1);
    parent.assign(n,-1);

    queue<int> cola;
    dist[s]=0;
    cola.push(s);

    while(!cola.empty()){
        int u = cola.front();cola.pop();
        for(int v: grafo[u]){
            if(dist[v]==-1){
                dist[v] = dist[u]+1;
                parent[v] = u;
                cola.push(v);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grafo(n);
    int x,y;

    while(m--){
        cin>>x>>y;
        grafo[x-1].push_back(y-1);
        grafo[y-1].push_back(x-1);
    }
    
    vector<int> dist;
    vector<int> parent;
    int s = 0;

    bfs(n,s,grafo,dist,parent);

    if (dist[n-1]==-1){cout<<"IMPOSSIBLE";}
    else{
        int distancia = dist[n-1]+1;
        cout<<distancia<<"\n";

        stack<int> recorrido;
        int nodo = n-1;
        for(int i=0;i<distancia;i++){
            recorrido.push(nodo+1);
            nodo = parent[nodo];
        }
        for(int i=0;i<distancia;i++){
            cout<<recorrido.top()<<" ";recorrido.pop();
        }
    } 

    return 0;
}