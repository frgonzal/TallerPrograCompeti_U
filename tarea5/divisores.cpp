//S(n) = 1 + 2 + 3 + 6...

//n = 12
//1 --> 1 
//2     1 2
//3     1 3
//4     1 2 4
//5     1 5
//6     1 2 3 6
//7     1 7
//8     1 2 4 8
//9     1 3 9
//10    1 2 5 10
//11    1 11
//12    1 2 3 4 6 12
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n; cin>>n;
    ll ans = 0;
    for(int i=1;i<=sqrt(n);i++){
        int q = n/i;
        int limit = n/q;
        int cuantos = n/q+1-q;

        int suma = cuantos*i;

        ans += suma;

    }
    cout<<ans<<"\n";

}