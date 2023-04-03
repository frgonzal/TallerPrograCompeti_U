#include <bits/stdc++.h>
using namespace std;

// a+b = n
//n%n = 0
//n+1%n = 1
//...

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;

    int A[n];
    multiset<int> B;
    int N[n];
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        A[i]=a;
    }
    for(int i=0;i<n;i++){
        int b;
        cin>>b;
        B.insert(b);
    }
    for (int i=0;i<n;i++){
        auto itr = B.lower_bound(n-A[i]);

        if(itr == B.end()){
            itr = B.begin();
        }
        cout<<(A[i]+*itr)%n;
    }
    return 0;
}