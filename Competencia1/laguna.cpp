#include <bits/stdc++.h>
using namespace std;

int n, m;
vector <vector <int>> Grilla;
vector<vector<int>> visited;
int maximo;

int Recorrer_Grilla(int x, int y){
	queue<pair<int,int>> q;
	vector <int> dx = {1, 0, -1, 0};
	vector <int> dy = {0, 1, 0, -1};

	q.push({x,y});
	visited[x][y] = 1;
    int maxim = Grilla[x][y];

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
            maxim+=Grilla[nx][ny];
		}
	}
    return maxim;
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int casos;cin>>casos;
    while(casos--){
    maximo = 0;
	cin >> n >> m;
	Grilla.assign(n,vector<int>(m));
	visited.assign(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        int p;cin>>p;  
        Grilla[i][j]=p;
		if(p==0){visited[i][j]=1;}//si es 0 se visita
		}}
	
	for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(visited[i][j]==0){//se busca una casilla no visitada
			maximo = max(Recorrer_Grilla(i,j), maximo);}}}

cout<<maximo<<endl;}
}