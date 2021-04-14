#include<bits/stdc++.h>
using namespace std;

#include <iostream>
#include <vector>
#include <climits>
#include<cstring>
using namespace std;
// brute force
/*
int minCostPath(int **input, int m, int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     
 if(m==1&&n==1)
     return **input;
 if(m<1||n<1)
     return INT_MAX;
    int c1= minCostPath(input,m-1,n);
    int c2= minCostPath(input,m,n-1);
    int c3=minCostPath(input,m-1,n-1);
    return input[m-1][n-1]+ min(c1,min(c2,c3));
}

// memoisation
*/

/*
int mcp( int ** input, int m , int n , int **output)
{    if(m==0&&n==0)
     return **output;
 if(m<0||n<0)
     return INT_MAX;
 
 if(output[m][n]!=-1)
     return output[m][n];
 
    int c1= mcp(input,m-1,n,output);
    int c2= mcp(input,m,n-1,output);
    int c3=mcp(input,m-1,n-1,output);
    output[m][n]= input[m][n]+ min(c1,min(c2,c3));
    
    
}
int minCostPath( int **input, int m , int n){

int **output= new int* [m];
    
    for(int i = 0;i<m;i++){
        output[i]= new int[n];
        for(int j= 0;j<n;j++)
            output[i][j]=-1;
    }
    output[m-1][n-1]= input[m-1][n-1];
     return mcp(input, m-1 , n -1, output) ;
    }
*/

int minCostPath( int **input, int m, int n){
    // now solving using dp
   int opdp[m][n];
   for(int i=0;i<m;i++){
       for(int j=0;j<n;j++) opdp[i][j] = 0;
   }
   opdp[0][0]
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            //opdp[i][j] = min(input[i-1][j-1] min(input[i-1][j],input[i][j-1]));
            opdp[i][j] = min(opdp[i-1][j-1], min(opdp[i-1][j] , opdp[i][j-1])) + input[i-1][j-1];
        }
    }
    
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            cout<<opdp[i][j]<<" ";
        }cout<<endl;
    }
    return opdp[m][n];
}
int main() {
    int **arr,n,m;
    cin >> n >> m;
    arr = new int*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    cout << minCostPath(arr, n, m) << endl;
}
