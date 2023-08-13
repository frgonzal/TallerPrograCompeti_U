#include <bits/stdc++.h>


int es_bellisima(int n, std::string s){
	if (n == 1) return 0;

	int suma = 0;
	for(int i=0; i<n-1; i++){
		if(s[i] == s[i+1])
			suma++;
	}
    return suma;
}

int main(){
    std::ios_base::sync_with_stdio(0);std::cin.tie(0);
    int t, n, m, es_belli_s1, es_belli_s2;
    std::string s1, s2;
    std::cin>>t;
    while(t--){
		std::cin>> n >> m >> s1 >> s2;
		es_belli_s1 = es_bellisima(n, s1);
		es_belli_s2 = es_bellisima(m, s2);

		if( (!es_belli_s1 && !es_belli_s2)||
			(!es_belli_s1 && es_belli_s2 < 2 && s1[n-1]!=s2[m-1])||
			(!es_belli_s2 && es_belli_s1 < 2 && s1[n-1]!=s2[m-1]))
			std::cout<< "YES\n";
		else
			std::cout<< "NO\n";

    }
    return 0;
}