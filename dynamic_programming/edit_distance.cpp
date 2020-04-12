//edit distance
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int64_t  editdistance(string a, string b){
    int size1 = a.length();
    int size2 = b.length();
    int table[size1+1][size2+1];
    //initialiation of table with base case
    for(int i=0; i<=size2;i++)
    table[0][i]=i;
    for(int j=0;j<=size1;j++)
    table[j][0]=j;
    //now precalculation of the answer

    for(int i=1;i<=size1;i++){
        for(int j=1 ; j<=size2; j++){
            int val = min(table[i-1][j-1],
                      min(table[i-1][j],table[i][j-1]));
            table[i][j]= a[i-1]==b[j-1]? val:val+1;
        }
    }
    
    return table[size1][size2];

}
// this feature can be improved since we are always using only 2 of the rows,
// the row and one above hence can reduce space complexity

int64_t editdistance_space_optimized(string a, string b){
    int size1 = a.length();
    int size2 = b.length();
    int table[2][size2+1];
    //initialization of table
    for(int i = 0 ; i<=size2;i++)
        table[0][i]=i;
    

    //preprocessing in updated space
    for(int i= 1 ; i<=size1;i++){
        for(int j=0;j<=size2;j++){

            if(j==0)
             table[i%2][j] = i;
            int val = min(table[(i-1)%2][j-1],
                      min(table[(i-1)%2][j], table[i%2][j-1]));
            table[i%2][j] = a[i-1] == b[j-1]? val:val+1;
        }
    }
    return table[size1%2][size2];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b;
    cin>>a>>b;
    auto start = high_resolution_clock::now();
    cout<<editdistance(a,b)<<endl;
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end-start);
    cout<<"time taken by the function: \t"
        <<duration.count() <<"microseconds"<<endl;
    
     start = high_resolution_clock::now();
    cout<<editdistance_space_optimized(a,b)<<endl;
     end = high_resolution_clock::now();
     duration = duration_cast<microseconds>(end-start);
    cout<<"time taken by the function: \t"
        <<duration.count() <<"microseconds"<<endl;

    return 0;
}

// RESULTS
/*
catacomb food
editdistance()
7
time taken by the function:     80microseconds
editdistance_space_optimized()
7
time taken by the function:     9microseconds
*/