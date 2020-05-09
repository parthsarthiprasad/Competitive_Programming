//Longest commong subsequence
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int lcs_recursive(string a,string b){
    if(a.length()==0||b.length()==0)
        return 0;
    if(a[0]==b[0])
    return 1+lcs_recursive(a.substr(1),b.substr(1));
    else
    return max(lcs_recursive(a.substr(1),b), lcs_recursive(a,b.substr(1)));
}

int lcs_dp(string a, string b){
    int size1 = a.length();
    int size2 = b.length();
    int dp[size1+1][size2+1];
   
    
    for(int i=0;i<=size1;i++){

        for(int j=0;j<=size2;j++){
            if(i==0||j==0)
                dp[i][j] = 0;
            else if(a[i-1]==b[j-1])
                dp[i][j] = dp[i-1][j-1] +1;
            else
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            
        }
     }
    
    //printing the lcs
    int i=size1,j=size2;
    while(i>0&&j>0){
         while(dp[i][j]==dp[i][j-1]){
            j--;
        }
        // if(dp[i][j]==dp[i-1][j-1]+1){
        //     cout<<a[i]<<" ";
        //     i--;
        //     j--;
        // }
        cout<<a[i]<<" ";
        i--; j--;
        // while(dp[i][j]==dp[i-1][j]){
        //     i--;
        // }
       
        
    }
    cout<<endl;
    return dp[size1][size2];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b;
    //cin>>a;
    //cin>>b;
    a = "aggtabi";
    b = "gxtxayb";
    auto start= high_resolution_clock::now();
    cout<<lcs_recursive(a,b)<<endl;
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end-start);
    cout<<"Total time taken : "
        <<duration.count()<<"microseconds\n";

    start= high_resolution_clock::now();
    cout<<lcs_dp(a,b)<<endl;
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end-start);
    cout<<"Total time taken : "
        <<duration.count()<<"microseconds\n";
    return 0;
}

// RESULT

/*
aggtab
gxtxayb
4
Total time taken : 239microseconds
Recursive calls take too much time and hence give time complexity of 2^n*n
2^n total cases , n for linear seraching and pattern matching 

aggtab
gxtxayb
4
Total time taken : 266microseconds
4
Total time taken : 20microseconds

SOlution from DP approach


*/