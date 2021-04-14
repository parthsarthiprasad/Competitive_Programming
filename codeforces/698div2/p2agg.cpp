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
        string s;
        cin>>s;
        int prev0 = 0;
        int prev1 = 0;
        int res = n;

        vector<int> prefix1(n,0);
       vector<int> suffix1(n,0);
       int count1 = 0;
       for(int i=0;i<n;i++){
           if(s[i]=='1')count1++;
           prefix1[i] = count1;
       }
       count1 = 0;
       for(int i=n-1;i>=0;i--){
           if(s[i]=='1')count1++;
           suffix1[i] = count1;
       }
       
        vector<vector<int>> vec(n,vector<int>(2,0));
        if(s[0]=='0'){
            vec[0][0] = 0;
            vec[0][1] = 1;
        }else{
            vec[0][0] = 1;
            vec[0][1] = 0;
        }
        for(int i=1;i<n;i++){
            if(s[i]=='0'){
                vec[i][0] = vec[i-1][0];
                vec[i][1] = vec[i-1][1]+1;
            // vec[i][0] = vec[prev0][0] + (i-prev0-1);
            // // vec[i][1] = vec[prev0][0] + (i-prev0);
            // vec[i][1] = vec[prev1][1] + (i-prev1-1);
            }else{
                vec[i][0] = vec[i-1][0] +1;
                vec[i][1] = min(vec[i-1][0], vec[i-1][1]);
            //     vec[i][0] = vec[prev0][0] + (i-prev0-1);
            // // vec[i][1] = vec[prev0][0] + (i-prev0);
            //   vec[i][1] = vec[prev1][1] + (i-prev1-1);
            //   vec[i][1] = min(vec[i][1], vec[i][0]);

            }
            if(s[i]=='1'){
                prev1 = i;
            }else{
                prev0 = i;
            }
        }
        // for(int i=0;i<n;i++){
        //     int temp = n;
        //     if(i+1<n){
        //         temp = min(suffix1[i+1], n-i-1-suffix1[i+1]);
        //     }else{
        //         temp = 0;
        //     }
        //     int val1 = vec[i][0] + temp;
        //     int val2 = vec[i][1] + (n-i-1) - (i+1<n?suffix1[i+1]:0);
        //     temp = min(val1, val2);
        //     res = min(res, temp);
        // }
        for(int i=0;i<n;i++){
            res = min(res, vec[i][0] + (n-i-1));
            res = min(res, vec[i][1] + (n-i-1));
        }
        cout<<res<<endl;
    }
    return 0;
}