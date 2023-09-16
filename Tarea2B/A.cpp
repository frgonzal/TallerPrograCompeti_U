#include <bits/stdc++.h>
typedef long long ll;
int n;
ll t, k, maxElem, mid;
std::vector <ll> K;

int sumT(ll tiempo){
    ll paquetes = t;
    for(int i=0; i<n; i++){
        paquetes -= tiempo / K[i]; // paquetes que puedo hacer en tiempo t con maquina K[i];
    }
    if (paquetes > 0) return 0;//no se puede hacer en el tiempo;
    else return 1;
}

int main(){
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);
    std::cin>>n>>t;

    for(int i=0;i<n;i++){
        std::cin>>k;
        K.push_back(k);
        maxElem = std::max(maxElem, k);
    }
    
    ll l = 0, r = maxElem*t;
    while(l < r){
        mid = (l+r)/2;
        if( sumT(mid) ) r = mid; // Si se puede hacer en ese tiempo (mid) entonces...
        else l = mid+1;
    }

    std::cout<<r<<"\n";
}