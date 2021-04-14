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
       int sum=0;
       int count5 = 0;
       bool flag = true;
       for(int i=0; i<n && flag; i++){
           cout<<count5<<" "<<sum<<" "<<flag<<endl;
           int temp;
           cin>>temp;
           int return_change = temp-5;
           if ( (sum < return_change) || ( !count5  && return_change==5) ) {flag = false;}
           else{
            if (return_change==0){ 
                count5++;
            }
            if (return_change == 5){
                count5--;
            }
            if (return_change == 10){
                if (sum == count5*5){
                    count5-=2;
                }
            }
            sum+=5;
            
               
           }
       }
       flag? cout<<"YES": cout<<"NO";
       cout<<endl;

    }
    return 0;
}