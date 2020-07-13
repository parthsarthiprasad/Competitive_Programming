//covid sampling problem
/* 
    this is recursive DAC solution to query 
    each half and work accordingly 
    this I feel is appropriate option 
    to minimize the cost of querying continoursly
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int ptr[60][60];
int n,p;
vector<int> answer_list;
void printarray(int ptr[60][60]){
    cout<<"*********************************************************"<<endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            cout<<ptr[i][j]<<" ";
    cout<<endl;
    }
    cout<<"*********************************************************";

}
int jfind(int r1,int r2, int c1, int c2, int temparray[4][4]){
    
    int count = 0;
    for(int i=r1;i<=r2;i++){
        for(int j=c1;j<=c2;j++)
            count+=temparray[i][j];
    }
    cout<<count<<endl;
    return count;
}

bool verify_matrix(int temparray[4][4]){
    bool ans=true;
    for(int i=0;i<4 && ans;i++){
        for(int j=0; j<4 && ans;j++)
         ans = ans&(temparray[i][j]==ptr[i][j]);
    }
    return ans;
}

void fillarray(int r1, int r2, int c1, int c2, int value){
    for(int i=r1;i<=r2;i++){
        for(int j = c1; j<=c2; j++)
            ptr[i][j] = value;
    }
    cout<<"array filled for row values"<<r1<<","<<r2<<","<<c1<<","<<c2<<"with value: "<<value<<endl;
    printarray(ptr);
    return ;
}

int query(int p,int temparray[4][4], int r1=0,int r2=n-1, int c1=0, int c2=n-1){
    
    int arraysize = (r2-r1+1)*(c2-c1+1);
    if(arraysize<=0)
        return 0;
    int tempcount = 0;
    cout<<1<<" "<<r1<<" "<<c1<<" "<<r2<<" "<<c2<<endl;
    
    fflush(stdout);
    int answer;
   
    answer = jfind(r1,r2,c1, c2, temparray);
     if(arraysize==1 ){
        if(answer==1) ptr[r1][c1]=1;
        else ptr[r1][c1]=0;
        return answer;
    }
    answer_list.push_back(answer);
    if(answer==-1){
        cout<<"queries exceeded";
        exit(0);
    }
    else if(answer==arraysize){
        fillarray(r1,r2,c1,c2,1);
    }
    else{
        if(tempcount==answer){
            fillarray(r1,r2,c1,c2,0);
        }
        //initialising the middle parameters to divide the matrix accordingly
        int midr = (r1+r2)/2;
        int midc = (c1+c2)/2;
        if(tempcount!=answer) { 
             //query returns found infected patients
            tempcount+=query(p, temparray, r1,midr, c1,midc);
         }
        else{
            fillarray(r1,midr, c1,midc,0);
         }
        
        if(tempcount!=answer) { 
            tempcount+=query(p, temparray, midr+1, r2, c1, midc);
         }
        else{
            fillarray(midr+1, r2, c1, midc,0);
         }

        if(tempcount!=answer) { 
            tempcount+=query(p, temparray, r1,midr,midc+1, c2);
        }
        else{
            fillarray(r1,midr,midc+1, c2,0);
        }

        if(tempcount!=answer) { 
            tempcount+=query(p, temparray, midr+1, r2, midc+1,c2);
        }
        else{
            fillarray(midr+1, r2, midc+1,c2,0);
        }
        if(tempcount!=answer){
            cout<<"Error detected, couldn't fill complete array"<<endl;
            vector<int>::iterator it;
            for(it= answer_list.begin(); it!=answer_list.end(); ++it)
                cout<<(*it)<<" ";
            cout<<endl;
            exit(0);
        }
    }
    
    return answer;
    
}


void verify(int temparray[4][4]){
    cout<<2<<endl;
    fflush(stdout);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ptr[i][j]<<" ";
        }
        cout<<endl;
    }
    fflush(stdout);
    bool answer = verify_matrix(temparray);
    if (!answer){
        cout<<"solved matrix didn't match error";
        exit(0);
    }
    else {cout<<"solution verfied it works"<<endl;}
    return ;
        
}

void queryarray( int p, int temparray[4][4], int r1=0, int r2=n-1, int c1=0, int c2=n-1){
   query(p,temparray);
   verify(temparray);
   
}
int main(){
    int temparray[4][4] = {{0,0,1,0},
              {1,0,0,1},
              {0,0,0,1},
              {1,0,1,0}
             };
    int t;
    cin>>t;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            ptr[i][j]= INT_MAX;
    }
    while(t--){
      cin>>n>>p;
      // if probability is 10 or 15 start searching for 0 rather that 1
      queryarray(p,temparray);
    }
    return 0;
}