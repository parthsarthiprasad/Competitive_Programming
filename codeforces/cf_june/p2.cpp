#include<bits/stdc++.h>
#define ll long long int
using namespace std;




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    
    
    while(t--){
       int n;
       cin>>n;
       int temp=INT_MIN;;
       cin>>temp;
       bool issorted = true;
       for(int i=1;i<n;i++){
           int val;
           cin>>val;
           if(val<temp)
           issorted=false;
           temp=val;

       }
       temp=0;
       for(int i=0;i<n;i++){
           int val;
           cin>>val;
           temp+=val;
       }

       if(!issorted && (temp==0||temp==n))
       cout<<"No"<<endl;
       else
       cout<<"Yes"<<endl;

    }
    return 0;
}