//min cost path
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int mat[10][10];

int minCost(int  ptr[3][3] , int a , int b){
    if(a<0 || b<0 )
    return INT_MAX;
    if(a==0 && b==0)
        return ptr[0][0];
    if (mat[a][b] != INT_MAX)
        return mat[a][b];
    int val = ptr[a][b] + min(minCost(ptr,a-1,b),
                       min(minCost(ptr,a,b-1),
                           minCost(ptr,a-1,b-1)));
    mat[a][b] = val;
    return val;
}
int main(){
    //ios_base::sync_wtih_stdio(false);
    cin.tie(NULL);
     auto start = high_resolution_clock::now(); 
    int cost[3][3] = { {1, 2, 3}, 
                      {4, 8, 2}, 
                      {1, 5, 3} }; 
    
    for (int i = 0 ; i< 10;i++){
        for(int j=0;j<10;j++){
            mat[i][j]= INT_MAX;
        }
    }
   cout<< minCost(cost, 2, 2)<<endl; 
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 
    return 0;
}