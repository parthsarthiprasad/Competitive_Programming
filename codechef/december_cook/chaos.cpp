#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k)for(int i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
       int n,m;
       cin>>n>>m;
    //    vector<int> vec(m);
    //    rep(i,0,m){
    //        cin>>vec[i];
    //     //    vec[i]%=n;
    //    }
       set<int> s;
       bool tdiv = true;
       bool odiv = true;
       for(int i=0;i<m;i++){
           int temp;
           cin>>temp;
           if(temp&1)tdiv = false;
           else odiv = false;
           s.insert(temp);
       }

       if(tdiv==false && odiv == false){
           cout<<n-1<<endl;
       }else {

           set<int>::iterator it = s.begin();
           while(it!=s.end()){
               if(*it!=0)break;
               it++;
           }
           if(it==s.end())cout<<0<<endl;
           else cout<<n - *it<<endl;
       }
    //    for(auto a:vec){
    //        cout<<a<<" ";
    //    }
    //    cout<<endl;
    }
    return 0;
}