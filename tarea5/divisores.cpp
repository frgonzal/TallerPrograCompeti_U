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

ll sum_s(ll n){
    ll ans = 0;
    for(int i=1; i<=sqrt(n); i++){
        int q = n/i;

        int limit = n/q;
        int cuantos = n/q + 1 + q;

        int suma = cuantos*i;
        ans += suma;
    }
    return ans;
}
ll sum_s1(int n){
    ll ans = 0;
    for(int i=1;i<=n;i++){
        ans += i*(n/i);
    }
    return ans;
}
ll sum_s2(int n){
    ll ans = n - 1 + n*(n+1)/2;
    ll sqrt_n = (ll) sqrt(n); 
    for(int i=2; i <=sqrt_n; i++){
        ans += i*( n/i - 1 ); //numero por apariciones 
        if( (n/i) > i ) ans += (n/i)*(n/(n/i) - 1);
    }
    return ans;
}

int main(){
    ll n; cin>>n;
    ll ans;
    ans = sum_s1(n);
    cout<<ans%((ll)1e19+7)<<"\n";
    ans = sum_s2(n);
    cout<<ans%((ll)1e19+7)<<"\n";
}