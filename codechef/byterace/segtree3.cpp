#include<bits/stdc++.h>
using namespace std;
#define int int64_t

int tree[1e6], Base = 1 << 19;
int lazy[136];
void propagation(int v){ //standard propagation
  tree[v * 2] += lazy[v];
  tree[v * 2 + 1] += lazy[v];
  lazy[v * 2] += lazy[v];
  lazy[v * 2 + 1] += lazy[v];
  lazy[v] == 0;
}
void update(int a, int b, int c, int v = 1, int p = 1, int k = Base){
  if(p > b || k < a) return; //if outside range [a, b]
  propagation(v);
  if(p >= a && k <= b){ // if fully inside range [a, b]
    tree[v] += c;
    lazy[v] += c;
    return;
  }
  update(a, b, c, v * 2, p, (p + k) / 2); //left child
  update(a, b, c, v * 2 + 1, (p + k) / 2 + 1, k); //right child
  tree[v] = tree[v * 2] + tree[v * 2 + 1]; //update current node
}
int query(int a, int b, int v = 1, int p = 1, int k = Base){
  if(p > b || k < a) //if outside range [a, b]
    return 0;
  propagation(v);
  if(p >= a && k <= b) // if fully inside range [a, b]
    return tree[v];
  int res = 0;
  res += query(a, b, v * 2, p, (p + k) / 2); //left child
  res += query(a, b, v * 2 + 1, (p + k) / 2 + 1, k); //right child
  tree[v] = tree[v * 2] + tree[v * 2 + 1]; //update current node
  return res;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        Base = n;
        for(int i=0;i<n;i++){
            tree[i] = 0;
            lazy[i] = 0;
        }
       

        while(q--){
            int l,r;
            cin>>l>>r;
            l--;r--;
            update(l,r,1);
        }

        for(int i=0;i<n;i++){
            query(i,i);
            cout<<endl;
        }
       
        cout<<endl;
        

    }
}