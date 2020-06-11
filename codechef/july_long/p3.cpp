#include<bits/stdc++.h>
#define ll long long 
using namespace std;
//char ptr[8][8];
void solve(){
    int k;
    cin>>k;
    k--;
    // memset(ptr,'X',sizeof(ptr));
    // ptr[0][0]='O';
    // bool flag = true;
    // int i=0,j=0;
    // for(int sum=0;sum<=16;++sum){
    //     i=sum;
    //     for(int j=0;j<sum && flag;j++, i--){
    //         if(k==0){
    //             flag=false;
    //             break;
    //         }
    //         ptr[j][i]='.';
    //         k--;
    //     }
    // }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(i==0&&j==0){
                cout<<"0 ";
            }
            else if(k>0){
                cout<<". ";
                k--;
            }
            else{
                cout<<"X ";
            }
        }
        cout<<endl;
    }

    
}
int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}