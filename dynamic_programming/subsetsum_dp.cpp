#include<bits/stdc++.h>
using namespace std;
bool finsubsetsum( int ptr[] , int sum , int a)
{
    // first create a 2-d array for preprocessing 
    bool subset[a+1][sum+1];
    for ( int i =0 ; i<=a ; i++)
     subset[i][0] = true;

    //non 0 sum with no input are all false
    for (int i =1 ; i<=sum ; i++)
    subset[0][i]= false;
    for (int i = 1;i<=a ; i++){
        for(int j=1;j<sum+1;j++){
            if(j<ptr[i-1])
             subset[i][j]=subset[i-1][j];
            else
             subset[i][j]=subset[i-1][j]||subset[i-1][j-ptr[i-1]];
            
        }
    }
    // to print the matrix
    for( int i =0; i<a+1;i++){
        for(int j=0 ; j<=sum ; j++){
            cout<<subset[i][j]<<" ";
        }
        cout<<endl;
    }

    // backtracking to return resut;
    int i= a , j = sum;
    bool val = subset[i][j];
    while((i>0&&j>0) && subset[i][j]==true){
    while(val){
        i--;
        val=subset[i][j];
    }
    cout<<ptr[i]<<" ";
    j=j-ptr[i];
    i++;
    }
    cout <<endl;
    return subset[a][sum];
    
}

// we can still improve the solution since every time only the one previous of the matrix is used and rest is unecesary 
// so continue to only use 2 contingous rows and save time and space
bool finsubsetsum_impr( int ptr[] , int sum , int a)
{
    // first create a 2-d array for preprocessing 
    bool subset[2][sum+1];
    // for ( int i =0 ; i<=a ; i++)
    //  subset[i][0] = true;

    //non 0 sum with no input are all false
   
    for (int i = 0;i<=a ; i++){
        for(int j=0;j<sum+1;j++){
          if(j==0)
            subset[i%2][j] = true;
          else if( i==0)
            subset[i%2][j] = false;
          else if(ptr[i]<=j)
            subset[i%2][j] = subset[(i+1)%2][j-ptr[i-1]]
                           ||subset[(i+1)%2][j]; 
          else
           subset[i%2][j] = subset[(i+1)%2][j];
        }
    }
   

    
    return subset[a%2][sum];
    
}


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int set[] = {3,34,4,12,5,2};
    int n = sizeof(set)/sizeof(set[0]);
    int sum = 9;
    cout<<finsubsetsum_impr(set,sum,n);
    return 0;
}