#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll INF = 1e18; // debe ser mayor a n*w_maximo = 10^11 (que es el peso del camino más largo posible)
using state = pair<ll,int>; // esto es para escribir state en vez de pair<ll,int>

vector<ll> dist_ida;
vector<ll> dist_vuelta;
vector<ll> dist_final;
vector <vector <pair<int,ll>>> adj_ida;
vector <vector <pair<int,ll>>> adj_vuelta;
vector <vector <pair<int,ll>>> adj_final;

int Dijkstra(int p, int f, vector<ll> &dist, vector<vector<pair<int,ll>>> &adj){
	// cola de prioridad que entrega el menor
	priority_queue <state, vector<state>, greater<state>> pq;
	// vector de distancias, inicializamos en INF

	pq.push({p,p});
	dist[0] = 0;

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
    return dist[f];
}

int main(){
	int N, M, primero, final;
    while(cin>>N){ cin >> M, primero, final;

	dist_ida.assign(N, INF);
    dist_vuelta.assign(N,INF);
    dist_final.assign(N,INF);

    adj_ida.assign(N,vector<pair<int,ll>>());
    adj_vuelta.assign(N,vector<pair<int,ll>>());
    adj_final.assign(N,vector<pair<int,ll>>());
//--------------------------------------------------------
	// adj[i] = {{u1, w1}, {u2,w2}, ...} ahora se guarda el peso de la arista también (w)
	for(int i=0; i<M; i++){
		int u, v;
		ll w;
		cin >> u >> v >> w;
		u--; // quizá haya que restarle uno si están indexados de uno
		v--;
		adj[u].push_back({v, w}); // arista {u,v} con peso w
		adj[v].push_back({u, w}); // arista {v,u} con peso w
	}
    Dijkstra();}
    return 0;
}