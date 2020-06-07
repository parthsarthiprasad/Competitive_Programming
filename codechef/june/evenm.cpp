//printing a form
/* 
1  2  3  4
8  7  6  5
9 10 11 12
16 15 14 13
*/

#include<bits/stdc++.h>
using namespace std;
int ptr[1000][1000];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int num = 1;
        for(int i=0;i <n ; i++){
            for(int j=0;j<n; j++ ){
                ptr[i][(j+i)%n]=n*i+j+1;
            }
        }
        for(int i=0;i <n ; i++){
            for(int j=0;j<n; j++ ){
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
        
    }
    return 0;
}