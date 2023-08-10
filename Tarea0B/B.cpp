#include <bits/stdc++.h>

int main(){
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);
    int N;
    std::cin>>N;
    std::string s;
    char c;

    while(N--){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){

                std::cin>>c;       
                if((int)c != 46){
                    s += c;
                }

            }
        }
        std::cout<<s<<"\n";
        s = "";
    }    

    return 0;
}