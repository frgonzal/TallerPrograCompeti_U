#include <bits/stdc++.h>
typedef long long ll;
int n;
ll t, k, maxElem = 0, mid;
std::vector <ll> K;

int sumT(ll tiempo){
    ll paquetes = t;
    ll total = 0;
    for(int i=0; i<n && total < paquetes; i++){
        total += (tiempo / K[i]); // paquetes que puedo hacer en el tiempo con maquina K[i];
    }
    if (total < paquetes) return 0;      //no se pueden hacer todos los paquetes en el tiempo;
    return 1;
}

int main(){
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);
    std::cin>>n>>t;
    K.assign(n, 0);
    
    for(int i=0;i<n;i++){
        std::cin>>k;
        K[i] = k;
        maxElem = std::max(maxElem, k);
    }
    
    ll l = 0, r = maxElem*t;
    while(l < r){
        mid = l + (r-l)/2;
        if( sumT(mid) ) r = mid; // Si se puede hacer en ese tiempo (mid).
        else l = mid+1;
    }
    std::cout<<r<<"\n";
}