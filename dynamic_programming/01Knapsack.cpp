//This is 0-1 knapsack problem
#include<iostream>
#include<map>
#include<iterator>
using namespace std;
int findoptimumsol(map<int,int> table,int len,int n){
    //initializing the dp
    // int ** dp = new int*[len+1];
    // for(int i=0;i<=len;i++){
    //     dp[i] = new int[n+1];
    //     dp[i][0]=0;
    // }
    // for(int i=0;i<=n;i++)
    // dp[0][i]=0;
    int dp[len+1][n+1];
    map<int,int>::iterator it = table.begin();
    //now calculating the value
    for(int i=0;i<=len;i++){
       if(i>1) it++;
        for(int j=0;j<=n;j++){
            if(i==0||j==0)
                dp[i][j]=0;
            else if(j<(it->first))
            dp[i][j]=dp[i-1][j];
            else{
                dp[i][j]=max(dp[i-1][j],
                             dp[i-1][j-(it->first)] + it->second
                             );
            }
        }
    }
    
    for(int i=0;i<=len;i++){
        for(int j=0;j<=n;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }

    return dp[len][n];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //int weights[] = {2,3,5,6,4,2,6,3};
    //int cost[] = {1,5,2,6,3,4,7,8};
    int cost[] = {60, 100, 120}; 
    int weights[] = {10, 20, 30}; 
    int num;
    cin>>num;
    int len = sizeof(weights)/sizeof(weights[0]);
    map<int,int> table;
    for(int i=0;i<len;i++){
        if(table.find(weights[i])==table.end())
            table[weights[i]]=0;
        table[weights[i]]=max(cost[i],table[weights[i]]);
    }

    map<int,int>::iterator it;
    for(it=table.begin();it!=table.end();it++)
        cout<<it->first<<" "<<it->second<<endl;
    cout<<endl;
    len = table.size();
    cout<<findoptimumsol(table,len,num)<<endl;
    return 0;
}