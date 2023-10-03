#include <bits/stdc++.h>

int n, a, b, c;
std::vector<int> cortes;

int main(){
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);
    std::cin>>n>>a>>b>>c;
    cortes.assign(n+1, 0); 
    if(n>=a)
        cortes[a] = 1;
    if(n>=b)
        cortes[b] = 1;
    if(n>=c)
        cortes[c] = 1;

    for(int i=1; i<n+1; i++){
        if( i-a >= 0 && cortes[i-a] > 0)
            cortes[i] = 1+cortes[i-a];
        if( i-b >= 0 && cortes[i-b] > 0)
            cortes[i] = std::max(cortes[i], 1+cortes[i-b]);
        if( i-c >= 0 && cortes[i-c] > 0)
            cortes[i] = std::max(cortes[i], 1+cortes[i-c]);
    }
    std::cout<< cortes[n] << '\n';
    return 0;
}