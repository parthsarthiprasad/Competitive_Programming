#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<2<<endl;
        if(n==2){
            cout<<"1 2"<<endl;
        }else{
            cout<<n<<" "<<n-2<<endl;
            cout<<n-1<<" "<<n-1<<endl;
            n--;
            while(n>2){
                cout<<n-2<<" "<<n<<endl;
                n--;
            }
            // cout<<"2 2"<<endl;
           
        }
        
    }
    return 0;
}