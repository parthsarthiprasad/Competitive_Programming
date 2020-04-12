//min cost path
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int minCost(int ptr[3][3] , int a, int b){
    int temp[3][3];
    temp[0][0] = ptr[0][0];
    // initializing the first column of the temp dp array
    for(int i =1 ; i <3; i++)
    {
        temp[0][i]=ptr[0][i] + temp[0][i-1];
    }
    //initializing the first row of the temp dp array
    for(int j=1; j<3;j++){
        temp[j][0] = ptr[j][0] + temp[j-1][0];
    }
    // now running dp to reach upto a,b
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            temp[i][j] = ptr[i][j] + min(temp[i-1][j],
                                      min(temp[i-1][j-1],
                                          temp[i][j-1]));
        }
    }
    return temp[a][b];
}
int main(){
    //ios_base::sync_wtih_stdio(false);
    cin.tie(NULL);
    auto start = high_resolution_clock::now();
    int cost[3][3] = { {1, 2, 3}, 
                      {4, 8, 2}, 
                      {1, 5, 3} }; 
    cout<< minCost(cost, 2, 2)<<endl; 
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 
    return 0;
}