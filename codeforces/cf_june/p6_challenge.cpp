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

void fillarray(int r1, int r2, int c1, int c2, int value){
    for(int i=r1;i<=r2;i++){
        for(int j = c1; j<=c2; j++)
            ptr[i][j] = value;
    }
    return ;
}

int query(int r1=0,int r2=n-1, int c1=0, int c2=n-1,int p=0){
    
    int arraysize = (r2-r1+1)*(c2-c1+1);
    if(arraysize<0)
        return 0;

    int tempcount = 0;
    cout<<1<<" "<<r1<<" "<<c1<<" "<<r2<<" "<<c2<<endl;
    int answer;
    cin>>answer;
    if(answer==-1){
        cout<<"queries exceeded";
        exit(0);
    }
    else if(answer==arraysize){
        fillarray(r1,r2,c1,c2,1);
    }
    else{
        if(tempcount == answer){
         fillarray(r1,r2,c1,c2,0);   
        }
        //initialising the middle parameters to divide the matrix accordingly
        int midr = (r1+r2)/2;
        int midc = (c1+c2)/2;
        if(tempcount!=answer) { 
             //query returns found infected patients
            tempcount+=query(r1,midr, c1,midc);
         }
        else{
            fillarray(r1,midr, c1,midc,0);
         }
        
        if(tempcount!=answer) { 
            tempcount+=query(midr+1, r2, c1, midc);
         }
        else{
            fillarray(midr+1, r2, c1, midc,0);
         }

        if(tempcount!=answer) { 
            tempcount+=query(r1,midr,midc+1, c2);
        }
        else{
            fillarray(r1,midr,midc+1, c2,0);
        }

        if(tempcount!=answer) { 
            tempcount+=query(midr+1, r2, midc+1,c2);
        }
        else{
            fillarray(midr+1, r2, midc+1,c2,0);
        }
        if(tempcount!=answer){
            cout<<"Error detected, couldn't fill complete array"<<endl;
            exit(0);
        }

    }
    return answer;
    
}


void verify(){
    cout<<2<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ptr[i][j]<<" ";
        }
        cout<<endl;
    }
    int answer;
    cin>>answer;
    if (answer!=1){
        cout<<"solved matrix didn't match error";
        exit(0);
    }
    else {cout<<"solution verfied it works"<<endl;}
    return ;
        
}

void queryarray(int p, int r1=0, int r2=n-1, int c1=0, int c2=n-1){
   query();
   verify();
   
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
      cin>>n>>p;
      // if probability is 10 or 15 start searching for 0 rather that 1
      queryarray(p);
    }
    return 0;
}