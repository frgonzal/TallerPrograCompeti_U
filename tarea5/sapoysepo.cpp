#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// gcd(a,b) = {
//              gcd(b,a)   si a>b   
//              b          si a==0
//              1          si b==0
//              gcd(b%a,a) else
//            }

// gcd(a,b) == gcd(b-a,a)

int main(){
ios_base::sync_with_stdio(0);cin.tie(0);
int T;cin>>T;
while(T--){

    ll n; cin>>n;
    ll x;
    //vector<ll> permutacion(n);
    cin>>x;
    ll max_ = x-1;

    for(int i=1;i<n;i++){
        cin>>x; 
        max_ = gcd(max_, x-1-i);
        //ll x;cin>>x;
        //permutacion.push_back(x);
    }

    cout<<max_<<"\n";
}
return 0;
}