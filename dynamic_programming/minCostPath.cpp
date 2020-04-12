//min cost path
#include<bits/stdc++.h>
using namespace std;

int minCost(int  ptr[3][3] , int a , int b){
    if(a<0 || b<0 )
    return INT_MAX;
    if(a==0 && b==0)
        return ptr[0][0];
    return ptr[a][b] + min(minCost(ptr,a-1,b),
                       min(minCost(ptr,a,b-1),
                           minCost(ptr,a-1,b-1)));
}
int main(){
    //ios_base::sync_wtih_stdio(false);
    cin.tie(NULL);
    int cost[3][3] = { {1, 2, 3}, 
                      {4, 8, 2}, 
                      {1, 5, 3} }; 
   cout<< minCost(cost, 2, 2)<<endl; 
    return 0;
}