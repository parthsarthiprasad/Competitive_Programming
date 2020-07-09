#include<bits/stdc++.h>
#define ll long long int
using namespace std;




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int row[50];
    int column[50];
    
    while(t--){
       int n,m;
       cin>>n>>m;
       memset(row,0,sizeof(row));
       memset(column,0,sizeof(column));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int temp;
                cin>>temp;
                if(temp=='1'|| temp==1){
                    row[i]=1;
                    column[j]=1;
                }
            }
        }
        
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            if(row[i]==0 && column[j]==0){
                count++;
                row[i] = 1;
                column[j] = 1;
            }
            }
        }
        if (count%2)
        cout<<"Ashish"<<endl;
        else
        cout<<"Vivek"<<endl;

        
    }
    return 0;
}