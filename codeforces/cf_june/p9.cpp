//this is guessing game
//the idea is that i divide and ans 3 queries to identify what's wrong or not.
//submitting the subtask
#include<bits/stdc++.h>
using namespace std;
char getans(int mid){
    if (mid==5)
        return 'E';
    else if(mid<5)
        return 'L';
    else    
        return 'G';
}
bool asklow(char ans){
    return (ans=='L');
}
bool askhigh(char ans){
    return (ans=='G');
}

char query(int mid){
    cout<<mid<<endl;
    char ans;
    ans=getans(mid);
    //cin>>ans;
    return ans;
}


int solve(int n){
    char ans='G';
    int low=0;
    int high=n;
    while(ans!='E' && low<=high){
        int mid=(low+high)/2;
        char ans=query(mid);
        if(ans=='E')   { 
            return mid;
            break;
        }
        bool ans1 = asklow(query(low));
        bool ans2 = asklow(query(high));
        if((ans1^ans2)){
            if(ans1){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        else{
            bool ans3=asklow(query(high));
            if(!(ans2^ans3)){
                if(!ans1){
                    high=mid;
                }else{
                    low=mid+1;
                }
            }
            else if(ans1^ans3){
                if(ans1){
                    high=mid;
                }else{
                    low=mid+1;
                }
            }
            else{
                cout<<"Stuck here somehow";
            }
        }
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    cout<<solve(n)<<endl;
    return 0;
}