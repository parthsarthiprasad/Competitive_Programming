//doctor chef
#include<bits/stdc++.h>
#define ll long long 
using namespace std;
// ll findcount(int temp, int &x){
//     while(temp/x)
// }
ll solve(){
    int n,x;
    cin>>n>>x;
    vector<int> vec(n), her(n+1);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    sort(vec.begin(), vec.end());
    int begsteps=0, begsteps2=0;
    int temp=x;
    while(temp<vec[0]){
        temp*=2;
        begsteps2++;
    }

    temp=x;
    while(temp<vec[n-1]){
        temp*=2;
        begsteps++;
    }
    
    temp=vec[0];
    int count=0;
    for(int j=0;j<n;j++){
        if(j>0){
            temp=vec[j-1];
        }
        while(vec[j]>temp){
            temp*=2;
            count++;
        }
        her[j]=count+begsteps2;
    }
    cout<<"Beginning steps rill 0:\t"<<begsteps2<<endl;
    cout<<"Begiining steps till n:\t"<<begsteps<<endl;
    for(int i=0;i<n;i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
     for(int i=0;i<n;i++){
        cout<<her[i]<<" ";
    }
    cout<<endl;
    
    
    int val= min(her[n-1]+begsteps2+1,begsteps+n-1);
    if(val<n)return n;
    else return val;
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