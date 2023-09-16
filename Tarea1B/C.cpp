#include <bits/stdc++.h>


int main(){
    std::ios_base::sync_with_stdio(0);std::cin.tie(0); 
    int n, k;
    long long a, ans=0;
    std::priority_queue<long long> P;
    std::cin>>n>>k;
    k -= n;

    while(n--){
        std::cin>>a;
        P.push(a);
    }
    while(k--){
        a = P.top();
        P.pop();

        P.push(a/2);
        if ( a%2 == 1 )
            P.push(a/2+1);
        else
            P.push(a/2);
    }

    while(!P.empty()){
        ans += P.top()*P.top();
        P.pop();
    }

    std::cout<<ans<<"\n";
    return 0;
}