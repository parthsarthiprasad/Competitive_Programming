#include <bits/stdc++.h>
#define int long long 
#define ll long long 
using namespace std;

ll subor(vector<ll>& A) {
      unordered_set <int> ty;
      unordered_set <int> nm;
      for(int i = 0; i < A.size(); i++){
         unordered_set <int> curr1;
         curr1.insert(A[i]);
         unordered_set<int>::iterator it = nm.begin();
         while(it != nm.end()){
            curr1.insert(*it | A[i]);
            it++;
         }
         it = curr1.begin();
         while(it != curr1.end()){
            ty.insert(*it);
            it++;
         }
         nm = curr1;
      }
      return ty.size();
}
string solve(){
    int n;
    cin>>n;
    vector<ll> vec(n);
    for(int i=0;i<n;i++) cin>>vec[i];
    int ans = subor(vec);
    if(ans< n*(n+1)/2){
        return "NO";
    }
    return "YES";
}
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}