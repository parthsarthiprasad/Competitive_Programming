#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int R,C;

bool isValid(int i, int j) 
{ 
    if (i < 0 || i >= R || j >= C || j < 0) return false; 
    return true; 
} 
  
int diagonalOrder(int** arr) 
{ 
    /* through this for loop we choose each element of first column 
    as starting point and print diagonal starting at it. 
    arr[0][0], arr[1][0]....arr[R-1][0] are all starting points */
    vector<int> count;
    vector<int> sizecount;
    int count1=0;
    int sizecount1=0;
    for (int k = 0; k < R; k++) 
    { 
        //cout << arr[k][0] << " "; 
        count1+=arr[k][0];
        sizecount1++;
        int i = k-1;    // set row index for next point in diagonal 
        int j = 1;        //    set column index for next point in diagonal 
  
        /* Print Diagonally upward */
        while (isValid(i,j)) 
        { 
            //cout << arr[i][j] << " "; 
            count1+=arr[i][j];
            sizecount1++; 
            i--; 
            j++;    // move in upright direction 
        } 
          count.push_back(count1);
          sizecount.push_back(sizecount1);
          count1=0;
          sizecount1=0;
        //cout << endl; 
    } 
  
    /* through this for loop we choose each element of last row 
       as starting point (except the [0][c-1] it has already been 
       processed in previous for loop) and print diagonal starting at it. 
       arr[R-1][0], arr[R-1][1]....arr[R-1][c-1] are all starting points */
  
    //Note : we start from k = 1 to C-1; 
    for (int k = 1; k < C; k++) 
    { 
        //cout << arr[R-1][k] << " "; 
        count1+=arr[R-1][k];
        sizecount1++;
        int i = R-2; // set row index for next point in diagonal 
        int j = k+1; // set column index for next point in diagonal 
  
        /* Print Diagonally upward */
        while (isValid(i,j)) 
        { 
            count1+=arr[i][j];
            sizecount1++;
            //cout << arr[i][j] << " "; 
            i--; 
            j++; // move in upright direction 
        } 
        count.push_back(count1);
        sizecount.push_back(sizecount1);
        count1=0;
        sizecount1=0;
        //cout << endl;

        //Now processing the data
          
    } 
    vector<int>::iterator it;
        for(it=count.begin();it!=count.end();it++)
            cout<<*it<<" ";
        cout<<endl;

        for(it=sizecount.begin();it!=sizecount.end();it++)
            cout<<*it<<" ";
        cout<<endl;

    int cost=0;
    int lastindex = sizecount.size()-1;
    cout<<cost<<" "<<lastindex<<endl;
    int i=0;
    while(i<lastindex){
        int tot0=count[i] + count[lastindex];
        cost+= min(tot0,2*sizecount[i]-tot0);
        i++;
        lastindex--;
    }
    
   return cost;


} 
int solve(){
   
    cin>>R>>C;
    string s;
    int ** ptr = new int*[R];
    for(int i=0;i<R;i++){
        ptr[i] = new int[C];
        for(int j=0;j<C;j++)
        cin>>ptr[i][j];
    }
    diagonalOrder(ptr);
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
       cout<<solve()<<endl;
    }
    return 0;
}