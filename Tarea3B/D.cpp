#include <bits/stdc++.h>

int P, H, S;
std::vector<long long> factorial;

long long elevate_2_to_l(int l){
    long long res = 1;
    long long x   = 2;
    while(l > 0){
        if( l%2 == 1 )
            res *= x;
        x *= x;
        l /= 2;
    }
    return res;
}

long long multinomio(){

    return 0;
}

long long fHS(int k){
    int max = (k - (H-S))/2;
    long long result = 0;
    for(int i=0; i<=max; i++){
        result += multinomio()*multinomio()*elevate_2_to_l();
    }
    return result;
}

int main(){
    std::cin>>P>>H>>S;
    if(S>H)
        std::swap(S,H);
    if(H>P)
        std::swap(H,P);
    if(S>H)
        std::swap(S,H);

    //std::cout << fHS(P-1) + 2*fHS(P) + fHS(P+1) << '\n';

    std::cout<< elevate_2_to_l(P) <<'\n';
    return 0;
}