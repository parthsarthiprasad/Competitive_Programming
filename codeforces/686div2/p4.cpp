#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
void build(vector<int> & segtree, int n){
    for(int i=n-1;i>0;i--){
        segtree[i]=segtree[i<<1]^ segtree[i<<1|1];
    }
}
int64_t query(vector<int> &segtree, int value, int l, int r ){
    int count = 1;
    for(;l<r;l>>=1,r>>=1, count++){
        // cout<<segtree[l]<<" values "<<value<<endl;
        if(segtree[l]<value) return count;
        if(l&1) l++;
        if(r&1) r--;
    }
    return 1e17;
    // if(segtree[l]>value) return 1e17;
    // return count;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t =1;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec(n);
        rep(i,0,n)cin>>vec[i];
        int64_t count = 0;
        // some operation
        vector<int> segtree(2*n);
        rep(i,n,2*n) segtree[i] = vec[i-n];
        build(segtree,n);
        // for(auto a:segtree){
        //     cout<<a<<" ";
        // }
        // cout<<endl;
        int64_t mincount = 1e17;
        rep(i,n,2*n-1){
            int64_t count = 1e17;
            int temp = i;
            int jumps = 0;
            while(temp>0){
                int values =  jumps+ query(segtree, segtree[temp],i+1,2*n);
                if(values<count){
                    count = values;
                    // cout<<"here"<<temp<<i<<endl;
                }
                // cout<<count<<endl;
                if((temp&1))temp--;
                temp>>=1;
                jumps++;
            }
            mincount = min(mincount, count);
        }
        if(mincount<n) cout<<mincount<<endl;
        else cout<<"-1\n";
 
    }
  return 0;  
}