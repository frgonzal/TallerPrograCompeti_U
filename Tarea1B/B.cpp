#include <bits/stdc++.h>

int main(){
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);
    int T, n;
    long long s, ans;
    std::cin>>T;
    while(T--){
        std::priority_queue<long long> Q;
        ans = 0;
        std::cin>>n;
        while(n--){
            std::cin>>s;
            if (Q.empty() && !s)
                continue;
            if (!s){
                ans += Q.top();
                Q.pop();
            }else
                Q.push(s);
        }
        std::cout<<ans<<"\n";
    }
    return 0;
}