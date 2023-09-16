#include <bits/stdc++.h>


int main(){
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);

    int n;
    long long x;
    std::cin>>n>>x;

    std::set<long long>    S;
    std::vector<long long> V(n);

    for(int i=0;i<n;i++){
        long long a;
        std::cin>>a;
        S.insert(a);
        V[i] = a;
    }
    for(int i=0;i<n;i++){
        auto b = S.find(x-V[i]);
        if(b != S.end()){
            for(int j=i+1; j<n; j++){

                if(V[j] == x-V[i]){
                    std::cout<<i+1<<" "<<j+1<<"\n";
                    return 0;
                }
            }
        }
    }
    std::cout<<"IMPOSSIBLE"<<"\n";
    return 0;
}