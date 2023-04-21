#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
	int n, m; cin >> n >> m;
	vector <vector <char>> grilla(n, vector<char>(m));
	// ... leemos la grilla desde la entrada estándar
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        int p;cin>>p;  
        grilla[i][j]=p;}}



	vector <int> dx = {1, 0, -1, 0};
	vector <int> dy = {0, 1, 0, -1};
	// dx y dy indican los cuatro movimientos posibles. Un vector de movimiento sería (dx[i], dy[i])

	queue <pair<int,int>> q; // Nuestros nodos ahora son pares (x, y)
	vector <vector <int>> dist(n, vector <int>(m,-1)); // ahora nuestro vector dist es una matriz de nxm
	q.push({0,0}); // empezaremos desde el (0,0)

	while(!q.empty()){
		auto [x,y] = q.front();
		q.pop();
		for(int dir=0; dir<4; dir++){
			int nx = x+dx[dir];
			int ny = y+dy[dir];
			if( nx>=m || ny>=n ) continue;
			if( grilla[nx][ny] != "." ) continue;
			if(dist[nx][ny] != -1) continue; // ya fue visitado
			dist[nx][ny] = dist[x][y]+1;
			q.push({nx,ny});
		}
	}
	// la respuesta queda guardada en dist
}

