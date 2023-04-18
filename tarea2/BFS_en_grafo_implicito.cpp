int main(){
	int n, m;
	cin >> n >> m;
	vector <vector <char>> grilla(n, vector<char>(m));
	// ... leemos la grilla desde la entrada estándar
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
			if(/* coordenada (nx, ny) está fuera de la grilla */) continue;
			if(/* hay una muralla, un obstáculo, un nodo que no queremos visitar, etc en (nx, ny) */) continue;
			if(dist[nx][ny] != -1) continue; // ya fue visitado
			dist[nx][ny] = dist[x][y]+1;
			q.push({nx,ny});
		}
	}
	// la respuesta queda guardada en dist
}
