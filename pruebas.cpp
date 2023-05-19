#include <bits/stdc++.h>
using namespace std;

main(){
    int n=10;
    bool break_ = false;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==3){break_=true;break;}
            cout<<i<<j<<endl;
        }
        if (break_){break;}
    }


    return 0;
}