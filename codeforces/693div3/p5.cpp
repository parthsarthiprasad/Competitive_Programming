#include<bits/stdc++.h>
using namespace std;
struct rect{
    int x;
    int y;
    int index;
    bool possible;
};
int n;
const int nax = 2e5+1;
vector<rect> segtree(2*nax+1);
vector<int> ans(nax);
void build(){
    for(int i=n-1;i>0;i--){
        if(segtree[i*2].x > segtree[i*2+1].x &&
            segtree[i*2].y > segtree[i*2+1].y
        ){
            segtree[i] = segtree[i*2];
            segtree[i*2].possible = true;
        }else if( segtree[i*2].x < segtree[i*2+1].x &&
                  segtree[i*2].y < segtree[i*2+1].y){
            segtree[i] = segtree[i*2+1];
            segtree[i*2].possible = true;
        }else{
            segtree[i].x = max(segtree[i*2].x,segtree[i*2+1].x);
            segtree[i].y = max(segtree[i*2].y,segtree[i*2+1].y);
            segtree[i].possible = false;
            segtree.index = -1;
        }
    }
}
int query(int i){
    int ind = i+n;
    int ans = -1
    while(ind>0){
        if(segtree[ind]!=segtree[ind/2] && segtree[ind].possible == true){
            return segtree[ind/2].index;
        }
        ind/=2;
    }
    return ans;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        vector<rect> vec(n);
        int index = 0;
        for(auto &a:vec){
            int x, y;
            cin>>x>>y;
            if(x<y) swap(x,y);
            a.x = x;
            a.y = y;
            a.index  = index++;
            a.possible = false;
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<n;i++){
            segtree[i+n] = vec[i];
            ans.clear();
        }
        build();
        for(int i=0;i<n;i++){
            ans[i] = query(i);
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;


    }
    return 0;
}