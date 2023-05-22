#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll INF = 1e18; // debe ser mayor a n*w_maximo = 10^11 (que es el peso del camino más largo posible)
using state = pair<ll,int>; // esto es para escribir state en vez de pair<ll,int>

vector <vector <pair<int,ll>>> adj;
vector <vector <pair<int,ll>>> adj_;

vector<ll> dist;
vector<ll> dist_;

void Dijkstra(int i, vector<ll> &dist, vector<vector<pair<int,ll>>> &adj){
	// cola de prioridad que entrega el menor
	priority_queue <state, vector<state>, greater<state>> pq;
	// vector de distancias, inicializamos en INF

	pq.push({0,i});
	dist[i] = 0;

	while(!pq.empty()){
		auto [peso_camino, u] = pq.top(); // C++17 (structured binding)
		pq.pop();

		if(peso_camino != dist[u]) continue; // ya revisamos un camino mejor hacia u, ignoramos este

		for(auto [v, w] : adj[u]){ // [v,w] de C++17
			// para cada vecino v de u con peso w
			if(peso_camino + w < dist[v]){
				// encontramos un mejor camino hacia v! actualizamos
				// su distancia y lo agregamos a la cola
				dist[v] = peso_camino+w;
				pq.push({dist[v], v});
			}
		}
	}
	// las distancias finales están en "dist"
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
    int ciudades, rutas, autopistas;
    cin >> ciudades, rutas, autopistas;


    dist.assign(ciudades, INF);
    adj.assign(ciudades, vector<pair<int,ll>>());
    for(int j=0;j<rutas; j++){
        ll w;int u, v;cin>>u>>v>>w;u--;v--;

        adj[u].push_back({v,w});
        adj_[u].push_back({v,w});
        adj[v].push_back({u,w});
        adj_[v].push_back({u,w});
    }
    vector<pair<int,ll>> autop;
    for(int j=0;j<autopistas;j++){
        ll w; int ciudad;cin>>ciudad>>w; ciudad--;
        adj[0].push_back({ciudad,w});
        adj[ciudad].push_back({0,w});
        autop.push_back({ciudad,w});
    }


    Dijkstra(0,  dist,  adj);
    for(auto [ciudad, w]: autop){
        dist_.assign(ciudades,INF);
        Dijkstra(ciudad, dist_, adj);         
        for(int i=0;i<ciudades;i++){
            
        }
        if(dist_[ciudad])
        
    }

	priority_queue <state, vector<state>, greater<state>> pq;
	pq.push({0,inicio});
	dist_final[inicio] = 0;

	while(!pq.empty()){
		auto [peso_camino, u] = pq.top();pq.pop();

		if(peso_camino != dist_final[u]) continue;
		for(auto [v, w] : adj_ida[u]){
			if(peso_camino + w < dist_final[v] and dist_ida[u] + w + dist_vuelta[v] != dist_ida[destino]){
				dist_final[v] = peso_camino+w;
				pq.push({dist_final[v], v});
			}
		}
	}

	if(dist_final[destino]!=INF){cout << dist_final[destino] << "\n";}
	else{cout<<-1<<"\n";}
	}

	return 0;
}