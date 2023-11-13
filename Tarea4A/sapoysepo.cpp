#include <bits/stdc++.h>
using namespace std;

struct pt {
    double x, y;

    bool operator==(pt p){
        return x==p.x and y==p.y;}
    double dist(pt p){
        return sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y));}
    
};

int orientation(pt a, pt b, pt c) {
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}
bool cw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool collinear(pt a, pt b, pt c) { return orientation(a, b, c) == 0; }
void convex_hull(vector<pt>& a, bool include_collinear = false) {
    pt p0 = *min_element(a.begin(), a.end(), [](pt a, pt b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });
    sort(a.begin(), a.end(), [&p0](const pt& a, const pt& b) {
        int o = orientation(p0, a, b);
        if (o == 0)
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
        return o < 0;
    });
    //que hace esto??
    if (include_collinear) {
        int i = (int)a.size()-1;
        while (i >= 0 && collinear(p0, a[i], a.back())) i--;
        reverse(a.begin()+i+1, a.end());
    }

    vector<pt> st;
    for (int i = 0; i < (int)a.size(); i++) {
        while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear))
            st.pop_back();
        st.push_back(a[i]);
    }

    a = st;
}

vector<pt> puntos;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin>>n;
    double x,y;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        puntos.push_back({x,y});}

    cin>>x>>y;
    pt sapo = {x,y};
    puntos.push_back({x,y});
    cin>>x>>y;
    pt sepo = {x,y};
    puntos.push_back({x,y});
    
    convex_hull(puntos, true);

    //necesariamente uno debe estar en el convex hull? si no fuera asi
    //tendrian que estar los 2 contenidos en la figura
    int sapoysepo=0;
    for(pt punto: puntos){
        if(punto==sapo){sapoysepo++;}
        if(punto==sepo){sapoysepo++;}}
    if(sapoysepo==1){//uno no esta en el convex hull
    cout<<fixed<<setprecision(15)<<sapo.dist(sepo)<<"\n";return 0;
    }

    double camino1 = 0;
    double camino2 = 0;
    //double total=0;
    //for(int i=0;i<puntos.size();i++){
    //    total+=puntos[i].dist(puntos[(i+1)%puntos.size()]);
    //}

    bool camino = true;//si estamos en el camino de ida o vuelta
    for(int i=0;i<puntos.size();i++){
        if(puntos[i]==sapo || puntos[i]==sepo){
            camino=!camino;}//cambiamos de camino
        
        if(camino){
            camino1+=puntos[i].dist(puntos[(i+1)%puntos.size()]);
        }else{
            camino2+=puntos[i].dist(puntos[(i+1)%puntos.size()]);}
    }

    cout<<fixed<< setprecision(15) <<min(camino1,camino2)<< "\n";
    return 0;
}