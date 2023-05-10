#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll INF = 1e18; // debe ser mayor a n*w_maximo = 10^11 (que es el peso del camino más largo posible)

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
	int n, m; cin >> n >> m;

	// adj[i] = {{u1, w1}, {u2,w2}, ...} ahora se guarda el peso de la arista también (w)
	vector <vector <pair<int,ll>>> adj(n); 
	for(int i=0; i<m; i++){
		int u, v;
		ll w;
		cin >> u >> v >> w;
		u--; // quizá haya que restarle uno si están indexados de uno
		v--;
		adj[u].push_back({v, w}); // arista {u,v} con peso w
		//adj[v].push_back({u, w}); // arista {v,u} con peso w
	}

	using state = pair<ll,pair<int,int>>; // esto es para escribir state en vez de pair<ll,int>
	// cola de prioridad que entrega el menor
	priority_queue <state, vector<state>, greater<state>> pq;
	// vector de distancias, inicializamos en INF
	vector <ll> dist(n, INF);
	vector <ll> dist_(n,INF); //distancias del segundo grafo

    vector <pair<int,int>> camino(n,{-1,-1});
    vector <pair<int,int>> camino_(n,{-1,-1});

	pq.push({0,{0,0}});
	dist[0] = 0;

	while(!pq.empty()){

		auto pair_ = pq.top();
        ll peso_camino = pair_.first;
    	int u = pair_.second.first;
		pq.pop();

		if(pair_.second.second == 0){

			if(peso_camino > dist[u]) continue; // ya revisamos un camino mejor hacia u, ignoramos este
			for(auto pair_ : adj[u]){
				int v = pair_.first;
				ll w  = pair_.second;
				// para cada vecino v de u con peso w

				//caso nos quedamos en el primer grafo
				if(peso_camino + w < dist[v]){
					// encontramos un mejor camino hacia v! actualizamos
					// su distancia y lo agregamos a la cola
					dist[v]   = peso_camino+w;
					camino[v] = {w,u};
					pq.push({dist[v], {v,0}});

				//caso pasamos al segundo grafo
				if(peso_camino + w/2 < dist_[v]){
					dist_[v]   = peso_camino+w/2;
					camino_[v] = {w/2,u};
					pq.push({dist_[v], {v,1}});
				}
			}
		}
	}else{
			if(peso_camino > dist_[u]) continue;

			for(auto pair_: adj[u]){
				int v = pair_.first;
				ll w  = pair_.second;

				if(peso_camino+w< dist_[v]){
					dist_[v]   = peso_camino+w;
					camino_[v] = {w,u};
					pq.push({dist_[v], {v,1}});
				}
			}
		}
	}


	cout<<dist_[n-1]<<endl;
	// las distancias finales están en "dist"

	return 0;
}
//2 grafos
//(u,v,w)--> ((u,1),(v,1),w  )
//       --> ((u,0),(v,0),w  )
//       --> ((u,0),(v,1),w/2)




