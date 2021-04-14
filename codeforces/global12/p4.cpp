#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
const int nax = 3e5;
vector<int> segtree(2*nax);
int query(int l, int r, int n) {  // sum on interval [l, r)
  int res = INT_MAX;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = min(res,segtree[l++]);
    if (r&1) res = min(res,segtree[--r]);
  }
  return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec(n);
        rep(i,0,n)cin>>vec[i];
        // finding logn compression method to work?
        
        for(int i=n;i<2*n;i++){
            segtree[i] = vec[i-n];
        }
        for(int i=n-1;i>0;i--){
            segtree[i] = min(segtree[i*2], segtree[i*2+1]);
        }
       
        for(int l=n, step=0, r=2*n; l<r;l/=2, r/=2, step++){
            set<int> s;
            for(int i=l;i<r;i++){
                s.insert(segtree[i]);
            }
            if(s.size()!=n-step || *max_element(s.begin(), s.end())!=(n-step)){
                cout<<0;
            }else{
                cout<<1;
            }

        }
        cout<<endl;
        

    }
    return 0;
}