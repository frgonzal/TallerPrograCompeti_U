#include <bits/stdc++.h>
long long MOD = 1e9+7;
int n;
std::vector<std::vector<char>> grilla;
std::vector<std::vector<long long>> caminos;

int main(){
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);
    std::cin>>n;
    grilla.assign(n, std::vector<char>(n));
    caminos.assign(n, std::vector<long long>(n));
    char c;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            std::cin>>c;
            grilla[i][j]  = c; 
            caminos[i][j] = 0;
        }
    }

    if(grilla[0][0] != '*')
        caminos[0][0] = 1;

    int a[] = {-1, 0};
    int b[] = {0, -1};
    for(int i=0; i<n; i++){ 
        for(int j=0; j<n; j++){
            for(int k=0; k<2; k++){
                int x = i + a[k];
                int y = j + b[k];
                if( n <= x || x < 0 ) continue;
                if( n <= y || y < 0 ) continue;
                if( grilla[i][j] == '*' ) continue;
                caminos[i][j] = (caminos[i][j]%MOD + caminos[x][y]%MOD )%MOD;
            }
        }
    }
    /**
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            std::cout<< caminos[i][j] << " ";
        }
        std::cout<<std::endl;
    }
    */
    std::cout<<caminos[n-1][n-1]<<"\n";
    return 0;
}