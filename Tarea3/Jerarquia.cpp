#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<int,int>> jerarquia;

// Necesitamos UnionFind para Kruskal
struct DSU{ //Disjoint Set Union (o Union Find)
    // Casi O(1) amortizado
    vector <int> parent, sz; // sz = size
    DSU(int n){
        parent.resize(n);
        sz.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
            sz[i] = 1;
        }
    }
    int find_set(int v){
        if(v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }
    void union_set(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a != b){
            if(sz[a] < sz[b])
                swap(a,b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
};

ll kruskal(int n, vector<tuple<ll,int,int>> &edges){
	// Algoritmo de Kruskal
	// 
	// Args:
	// 	n: cantidad de nodos
	// 	edges: vector de tuplas donde cada una es una arista {peso, nodo1, nodo2}
	//
	// Retorna:
	// 	El peso de un minimum spanning tree
	// 	Se puede modificar para que entregue las aristas del árbol si es necesario
	//
	// Complejidad: O(m log m) por el sort (m = |edges|)
	
	// Creamos nuestro UnionFind de n nodos (asumimos que están indexados desde 0)
	DSU dsu(n);
	// Ordenamos las aristas por peso de menor a mayor
	sort(edges.begin(), edges.end());

	ll ans = 0; // Acá guardamos la respuesta
	for(auto [w, u, v] : edges){ // (C++17 only)
		// Iteramos por las aristas de menor a mayor peso
		if(jerarquia[v].second != -1) continue;
		if(dsu.find_set(u) != dsu.find_set(v)){
			// Si pertenecen a componentes distintas, entonces
			// al unirlas no nos crean un ciclo. Agregamos la arista
			// y unimos las componentes
			ans += w;
			dsu.union_set(u, v);
			jerarquia[v] = {jerarquia[v].first,0};
		}
	}
	int suma = 0;
	for (auto [p,s]: jerarquia){suma+=s;}
	if(suma<-1){return -1;}
	return ans;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	/* Asumimos input de la forma:
	 * n m // cantidad de nodos y aristas
	 * u1 v1 w1 // nodo1 nodo2 peso_arista
	 * u2 v2 w2
	 * ...
	 * um vm wm
	 */
	int n, m;
	cin >> n;
	jerarquia.assign(n,pair<int,int>());

    for (int i=0;i<n;i++){
        int p; cin>>p;
        jerarquia[i] = {p, -1};}

    cin >> m;

	vector <tuple<ll,int,int>> edges(m); // guardamos aristas como {peso, nodo1, nodo2}
	// ojo que edges lo inicializamos con tamaño m y usamos long long para el peso
	// es buena idea guardar los pesos en long long porque suelen ser grandes
	for(int i=0; i<m; i++){
		int u, v;
		ll w;
		cin >> u >> v >> w;
		// aquí le restaríamos 1 a u y v si fuera necesario
		u--;
		v--;
		if(jerarquia[u].first < jerarquia[v].first){swap(u,v);}//{w, supervisor, supervisado}
		edges[i] = {w, u, v}; // para kruskal no importa el orden entre u y v
	}
	cout << kruskal(n, edges) << '\n';
	return 0;
}
