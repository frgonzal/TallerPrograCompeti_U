#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll max_ = 1e9+7;
ll div2 = 5e8+4;

ll sum_s(ll n){
    ll ans = 0;
    for(ll i=1; i<=n; i++){
        ll q = n/i;
        if(i != n/q){   // (( ((a%c)-(b%c))%c )+c)%c

            ll a = (((n/q)%max_)*((n/q+1)%max_))%max_;
            ll b = ((i%max_)*((i-1)%max_))%max_;
            ll suma = (( (((a%max_) - (b%max_))%max_ )+max_ )%max_ );
            suma = ((suma%max_)*(div2%max_))%max_;
            suma = ((q%max_)*(suma%max_))%max_;

            ans = ((ans)%max_ + (suma)%max_)%max_; 
            //cout<<i<<" : "<<q<<" : "<< suma <<endl;
            i = n/q;
        }
        else{
            ans = ((ans)%max_+((q%max_)*(i%max_))%max_)%max_;
        }
    }
    return ans;
}
int main(){
    ll n; cin>>n;
    ll ans = sum_s(n);
    cout<<ans<<"\n";
}