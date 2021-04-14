#include<bits/stdc++.h>
using namespace std;
#define int int64_t
const int nax = 5000;
int ptr[nax][nax];

int findvalu(vector<int> &vec, int a,int b){
    if(a>b) return 0;
    if(ptr[a][b]!=INT_MIN) return ptr[a][b];
    int op1 = vec[a] + min(findvalu(vec,a+2,b),findvalu(vec,a+1,b-1));
    int op2 = vec[b] + min(findvalu(vec,a+1,b-1), findvalu(vec,a,b-2));
    return ptr[a][b] = max(op1,op2);
    
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++)cin>>vec[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) ptr[i][j]= INT_MIN;
    }
    
    cout<<findvalu(vec,0,n-1)<<endl;
    // for(auto a:pos)cout<<a<<" ";
    cout<<endl;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++) cout<<ptr[i][j][0]<<" "<<ptr[i][j][1]<<"     ";
    //     cout<<endl;
    // }
}