#include <bits/stdc++.h>

long long k, n, a, b;

long long optimo(){
    long long l=0, r=n, mid;
    while(l < r){
        mid = (l+r+1)/2;
        if (k <= mid*a + (n-mid)*b) r = mid-1; 
        else l = mid;
    }
    return r;
}

int main(){
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);
    int q;
    std::cin>>q;
    while(q--){
        std::cin>>k>>n>>a>>b;
        if(k <= b*n )
            std::cout<<-1<<"\n";
        else if(k > n*a)
            std::cout<<n<<"\n";
        else
            std::cout<< optimo() <<"\n";
    }
    return 0;
}