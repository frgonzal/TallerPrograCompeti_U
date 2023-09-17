#include <bits/stdc++.h>

int n, k;
long long x;
std::vector<long long> X;

int dividir(long long suma){
    long long subArr = 1;
    long long sumAct = 0;

    for(int i=0;i<n;i++){
        if(X[i] > suma) return 0;
        if(sumAct + X[i] > suma){
            sumAct = X[i];
            subArr++;
        }else
            sumAct += X[i];
    }
    if(subArr <= k) return 1; // si subArr es <= k, como para tod subArr sum(subArr)<= sum entonces se pueden dividir aun mas
    return 0;
}

int main(){
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);
    std::cin>> n >> k ;
    X.assign(n,0);
    for(int i=0;i<n;i++){
        std::cin>>x;
        X[i] = x;
    }

    long long l=0, r=1e18, mid;
    while(l < r){
        mid = l + (r-l)/2;
        if(dividir(mid)) r = mid;
        else l = mid+1;
    }
    std::cout<<r<<"\n";
}