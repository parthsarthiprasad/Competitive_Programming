#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
vector<string> ptr(100);
vector<vector<int>> answer(3*100*100);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        rep(i,0,n){
            cin>>ptr[i];
        }
        int count = 0;
        vector<vector<int>>answer(3*n*m);

        for(int i=0;i<n-1;i++){
            for(int j=0;j<m-1;j++){
                if(ptr[i][j]=='0')continue;
                else{
                    answer[count].push_back(i+1);
                    answer[count].push_back(j+1);
                    answer[count].push_back(i+2);
                    answer[count].push_back(j+1);
                    if(ptr[i][j]=='0') ptr[i][j] = '1';
                    else ptr[i][j] = '0';
                    if(ptr[i+1][j]=='0') ptr[i+1][j] = '1';
                    else ptr[i+1][j] = '0';
                    if(ptr[i][j+1]=='0'){
                        answer[count].push_back(i+2);
                        answer[count].push_back(j+2);
                        if(ptr[i+1][j+1]=='0') ptr[i+1][j+1] = '1';
                        else ptr[i+1][j+1] = '0';
                    }else{
                         answer[count].push_back(i+1);
                        answer[count].push_back(j+2);
                          if(ptr[i][j+1]=='0') ptr[i][j+1] = '1';
                        else ptr[i][j+1] = '0';
                    }
                    count++;
                }
            }
        }
        //now fixing the edges

        if((ptr[n-1][m-1]=='0' && ptr[n-2][m-1]=='0' && ptr[n-1][m-2]=='1') ||
        (ptr[n-1][m-1]=='0' && ptr[n-2][m-1]=='1' && ptr[n-1][m-2]=='0') ||
        (ptr[n-1][m-1]=='1' && ptr[n-2][m-1]=='0' && ptr[n-1][m-2]=='0')){
                int i = n-1;
                int j = m-1;
                j++;
                answer[count].push_back(i+1);
                answer[count].push_back(j+1);
                answer[count].push_back(i+1);
                answer[count].push_back(j);
                answer[count].push_back(i);
                answer[count].push_back(j+1);
                count++; 
                if(ptr[n-1][m-1]=='0') ptr[n-1][m-1] = '1';
                else ptr[n-1][m-1] = '0';
                if(ptr[n-1][m-2]=='0') ptr[n-1][m-2] = '1';
                else ptr[n-1][m-2] = '0';
                if(ptr[n-2][m-1]=='0') ptr[n-2][m-1] = '1';
                else ptr[n-2][m-1] = '0';   
                j--;      
        }
        if(ptr[n-1][m-2]=='1'){
                 int i = n-1;
                int j = m-1;
                j++;
                answer[count].push_back(i);
                answer[count].push_back(j);
                answer[count].push_back(i+1);
                answer[count].push_back(j+1);
                answer[count].push_back(i);
                answer[count].push_back(j+1);
                count++; 
                if(ptr[n-1][m-1]=='0') ptr[n-1][m-1] = '1';
                else ptr[n-1][m-1] = '0';
                if(ptr[n-1][m-2]=='0') ptr[n-1][m-2] = '1';
                else ptr[n-1][m-2] = '0';
                if(ptr[n-2][m-2]=='0') ptr[n-2][m-2] = '1';
                else ptr[n-2][m-2] = '0';
                if(ptr[n-1][m-1]=='0'){
                answer[count].push_back(i);
                answer[count].push_back(j);
                answer[count].push_back(i);
                answer[count].push_back(j+1);
                answer[count].push_back(i+1);
                answer[count].push_back(j);
                count++; 
                j--;
                }else{
                    j++;
                answer[count].push_back(i);
                answer[count].push_back(j);
                answer[count].push_back(i+1);
                answer[count].push_back(j);
                answer[count].push_back(i+1);
                answer[count].push_back(j+1);
                count++; 
                j--;
                }
        }else if(ptr[n-1][m-1]=='1'){
                int i = n-1;
                int j = m-1;
                j++;
                answer[count].push_back(i);
                answer[count].push_back(j+1);
                answer[count].push_back(i);
                answer[count].push_back(j);
                answer[count].push_back(i+1);
                answer[count].push_back(j);
                count++; 
                answer[count].push_back(i+1);
                answer[count].push_back(j);
                answer[count].push_back(i);
                answer[count].push_back(j);
                answer[count].push_back(i+1);
                answer[count].push_back(j+1);
                count++;
                j--;
        }

        ptr[n-1][m-1] = '0';
        ptr[n-2][m-2] = '0';
        ptr[n-1][m-2] = '0';
        ptr[n-2][m-1] = '0';
        for(int j=0;j<m;j++){
            if(ptr[n-1][j]=='0') continue;
            if(j==m-1){
              
                int i =n-1;
                answer[count].push_back(i+1);
                answer[count].push_back(j+1);
                answer[count].push_back(i);
                answer[count].push_back(j);
                answer[count].push_back(i);
                answer[count].push_back(j+1);
                count++;
                answer[count].push_back(i+1);
                answer[count].push_back(j);
                answer[count].push_back(i+1);
                answer[count].push_back(j+1);
                answer[count].push_back(i);
                answer[count].push_back(j+1);
                count++;
                answer[count].push_back(i);
                answer[count].push_back(j);
                answer[count].push_back(i+1);
                answer[count].push_back(j);
                answer[count].push_back(i+1);
                answer[count].push_back(j+1);
                count++;
        
                ptr[i][j] = '0';
            }else if(ptr[n-1][j+1]=='0'){
                if(j>0){
                 int i =n-1;
                 j++;
                answer[count].push_back(i+1);
                answer[count].push_back(j+1);
                answer[count].push_back(i);
                answer[count].push_back(j);
                answer[count].push_back(i);
                answer[count].push_back(j+1);
                count++;
                answer[count].push_back(i+1);
                answer[count].push_back(j);
                answer[count].push_back(i+1);
                answer[count].push_back(j+1);
                answer[count].push_back(i);
                answer[count].push_back(j+1);
                count++;
                answer[count].push_back(i);
                answer[count].push_back(j);
                answer[count].push_back(i+1);
                answer[count].push_back(j);
                answer[count].push_back(i+1);
                answer[count].push_back(j+1);
                count++;
                j--;
                }else{
                     int i = n-1;
                j++;
                 answer[count].push_back(i);
                answer[count].push_back(j+1);
                answer[count].push_back(i);
                answer[count].push_back(j+2);
                answer[count].push_back(i+1);
                answer[count].push_back(j+1);
                count++;
                answer[count].push_back(i);
                answer[count].push_back(j+1);
                answer[count].push_back(i+1);
                answer[count].push_back(j);
                answer[count].push_back(i+1);
                answer[count].push_back(j+2);
                count++;
                answer[count].push_back(i);
                answer[count].push_back(j+2);
                answer[count].push_back(i+1);
                answer[count].push_back(j+1);
                answer[count].push_back(i+1);
                answer[count].push_back(j+2);
                count++;
                j--;
                }
                ptr[n-1][j] = '0';
            }else{
                 int i = n-1;
                j++;
                answer[count].push_back(i);
                answer[count].push_back(j+1);
                answer[count].push_back(i);
                answer[count].push_back(j+2);
                answer[count].push_back(i+1);
                answer[count].push_back(j+1);
                count++;
                answer[count].push_back(i);
                answer[count].push_back(j+1);
                answer[count].push_back(i);
                answer[count].push_back(j+2);
                answer[count].push_back(i+1);
                answer[count].push_back(j+2);
                count++;
                ptr[i][j] ='0';
                ptr[i][j+1] = '0';
                j--;
            }
        }
        for(int i=0;i<n-2;i++){
            int j = m-1;
            if(ptr[i][j]=='0') continue;
            if(ptr[i+1][j]=='0'){
                 answer[count].push_back(i+1);
                answer[count].push_back(j);
                answer[count].push_back(i+2);
                answer[count].push_back(j);
                answer[count].push_back(i+1);
                answer[count].push_back(j+1);
                count++;
                answer[count].push_back(i+1);
                answer[count].push_back(j);
                answer[count].push_back(i+1);
                answer[count].push_back(j+1);
                answer[count].push_back(i+2);
                answer[count].push_back(j+1);
                count++;
                answer[count].push_back(i+2);
                answer[count].push_back(j);
                answer[count].push_back(i+2);
                answer[count].push_back(j+1);
                answer[count].push_back(i+1);
                answer[count].push_back(j+1);
                count++;
                ptr[i][j] = '0';
            }else{
                answer[count].push_back(i+1);
                answer[count].push_back(j+1);
                answer[count].push_back(i+1);
                answer[count].push_back(j);
                answer[count].push_back(i+2);
                answer[count].push_back(j);
                count++;
                answer[count].push_back(i+1);
                answer[count].push_back(j);
                answer[count].push_back(i+2);
                answer[count].push_back(j);
                answer[count].push_back(i+2);
                answer[count].push_back(j+1);
                count++;
                ptr[i][j]='0';
                ptr[i+1][j]='0';
            }
        }
        cout<<count<<endl;
        for(int i=0;i<count;i++){
            for(auto a:answer[i]){cout<<a<<" ";}
            cout<<endl;
        }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++)cout<<ptr[i][j]<<" ";
        //     cout<<endl;
        // }

    }
}