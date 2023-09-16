#include <bits/stdc++.h>
using namespace std;

int n, m, k, puntos = 0, casillas_con_punto = 0;
vector <vector <char>> Grilla;
vector<vector<int>> visited;

void Recorrer_Grilla(int x, int y){
	queue<pair<int,int>> q;
	vector <int> dx = {1, 0, -1, 0};
	vector <int> dy = {0, 1, 0, -1};

	q.push({x,y});
	visited[x][y] = 1;
	casillas_con_punto++;
	if(casillas_con_punto == puntos){return;}

	while(!q.empty()){
		pair<int,int> coord = q.front();
		x = coord.first, y = coord.second;
		q.pop();

		for(int dir=0; dir<4; dir++){
			int nx = x+dx[dir];
			int ny = y+dy[dir];

			if( nx > n-1 || nx < 0 || ny < 0 || ny > m-1 ){continue;}//fuera de rango
			if( visited[nx][ny]== 1 ) {continue;} // ya fue visitado
			q.push({nx,ny});
			visited[nx][ny]=1;
			casillas_con_punto++;
			if(casillas_con_punto==puntos){return;}
		}
	}
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m >> k;
	Grilla.assign(n,vector<char>(m));
	visited.assign(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        char p;cin>>p;  
        Grilla[i][j]=p;
		if(p==35){visited[i][j]=1;}//si es # se visita
		else{puntos++;}//se suma la cantidad de puntos en la grilla
		}}
	
	puntos -= k;//A-k
	bool break_loop = false;
	for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(visited[i][j]==0){//se busca una casilla no visitada
			Recorrer_Grilla(i,j);
			break_loop = true;break;}
		}if(break_loop){break;}}

	for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
		if(visited[i][j]==1){//visitados
			cout<<Grilla[i][j];
		}else{
			cout<<"X";//los que no fueron visitados se marcan con X
		}
		}cout<<"\n";}
}