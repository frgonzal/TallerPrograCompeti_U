#include <bits/stdc++.h>

int n, x, a, maximo = 1;
std::vector<int> miradores;
std::vector<int> res;

int main(){
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);
    std::cin>>n>>x;
    miradores.assign(n, 0);
    res.assign(n, 1);
    for(int i=0;i<n;i++){
        std::cin>>a;
        miradores[i] = a;
    }

    for(int i=0; i<n; i++){
        int resto = x;
        for(int j=i+1;j<n;j++){
            if(resto - (miradores[j] - miradores[j-1]) >= 0){
                resto -= miradores[j];
                res[j] = std::max(res[j], res[j-1] + 1); 
                maximo = std::max(maximo, res[j]);
            }
            else 
                break;
        }
    }
    std::cout<< maximo << '\n';
    return 0;
}