//doctor chef
//solving for subtask first
#include<bits/stdc++.h>
#define ll long long 
using namespace std;
// ll findcount(int temp, int &x){
//     while(temp/x)
// }
ll solve(){
   int n,x;
   cin>>n>>x;
   int count=0;
    vector<int> vec(n);
   for(int i=0;i<n;i++){
       cin>>vec[i];
   }
   sort(vec.begin(),vec.end());
   if(x>=vec[n-1]){
       return n;
   }
   int temp=x;
   int index=0;
   for(;vec[index]<temp;index++);
   int leftval = index;
   //cout<<"index is :"<<index<<endl;
   for(int i=index;i<n;++i){
       while(temp<vec[i]){
           temp*=2;
           count++;
       }
       if(i!=n-1&& (vec[i]*2>=vec[i+1])){
           temp=vec[i];
       }
       count++;
       temp*=2;
   }
   return count+leftval;
   


//    vector<int>vec(n);
//    for(int i=0;i<n;i++)
//     cin>>vec[i];
   // sort(vec.begin(), vec.end());
    // int temp=x,ans=0;
    // while(temp<population){
    //     temp*=2;
    //     ans++;
    // }
    // int val= ans+n;
    // if(val<n) return n;
    // else return val;
}
int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
    return 0;
}