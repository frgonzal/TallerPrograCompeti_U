#include <bits/stdc++.h>

int main(){
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);
    int T, n, s, ans;

    std::cin>>T;
    while(T--){
        std::stack<int> S;
        ans = 0;

        std::cin>>n;
        while(n--){
            std::cin>>s;

            if (S.empty()){
                if(s) S.push(s);  // s!=0
            }else{
                if(!s){
                    ans += S.top();
                    S.pop();
                }else if(s >= S.top())
                    S.push(s);
            }
        }
        std::cout<<ans<<"\n";
    }
    return 0;
}