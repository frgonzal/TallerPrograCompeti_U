#include <bits/stdc++.h>
using namespace std;

int n, m;
pair<int> a, b;
vector <vector <char>> Grilla;
vector<vector<int>> visited;

vector<vector<int>> prev; //para saber de cual viene

void BFS(int x, int y){
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
    prev.assign(n, vector<int>(m),-1);

    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        char p;cin>>p;  
        Grilla[i][j] = p;
		if(p==35){
            visited[i][j] = 1;
        }else if(p==65){
            a = {i,j};
        }else if(p==66){
            b = {i,j};
        }
		}}

    BFS(); 
    
}