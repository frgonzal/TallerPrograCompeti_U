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

	using state = pair<ll,int>; // esto es para escribir state en vez de pair<ll,int>
	// cola de prioridad que entrega el menor
	priority_queue <state, vector<state>, greater<state>> pq;
	// vector de distancias, inicializamos en INF
	vector <ll> dist(n, INF);
    vector <pair<int,int>> camino(n,{-1,-1});

	pq.push({0,0});
	dist[0] = 0;

	while(!pq.empty()){
		auto pair_ = pq.top(); // C++17 (structured binding)
        ll peso_camino = pair_.first;
        int u = pair_.second;
		pq.pop();

		if(peso_camino != dist[u]) continue; // ya revisamos un camino mejor hacia u, ignoramos este

		for(auto pair_ : adj[u]){ // [v,w] de C++17
            int v = pair_.first;
            ll w  = pair_.second;
			// para cada vecino v de u con peso w
			if(peso_camino + w < dist[v]){
				// encontramos un mejor camino hacia v! actualizamos
				// su distancia y lo agregamos a la cola
				dist[v] = peso_camino+w;
                camino[v] = {w,u};
				pq.push({dist[v], v});
			}
		}
	}

    priority_queue<int> caminoT;

    int p = n-1;
    while(camino[p].first != -1){
        caminoT.push(camino[p].first);
        p = camino[p].second;
    }

    p = caminoT.top();caminoT.pop();
    ll suma = p/2;
    while(!caminoT.empty()){
        p = caminoT.top();caminoT.pop();
        suma+=p;
    }
    cout<<suma<<endl;




	// las distancias finales están en "dist"

	return 0;
}