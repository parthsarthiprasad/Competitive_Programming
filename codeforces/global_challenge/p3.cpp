#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back

#define pii pair<int,int>
#define pll pair<long, long>
void printDiamond(int n) 
{ 
	int space=(n/2)-1;
    for(int i=0;i<n;i++){
        
          for(int j=space;j<n-space;j++)
            cout<<i<<" "<<j<<endl;
        
        if(i<n/2){
            space--;
        }
        else{
            space++;
        }

        if(i==(n-1)/2){
            space++;
        }
    }
} 



void solve(){
    int n;
    cin>>n;
    if (n==1){
        cout<<5<<endl;
        cout<<"0 1"<<endl;
        cout<<"1 0"<<endl;
        cout<<"1 1"<<endl;
        cout<<"1 2"<<endl;
        cout<<"2 1"<<endl;
    }
    cout<<(n-1)*4<<endl;
    printDiamond(n); 
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}





