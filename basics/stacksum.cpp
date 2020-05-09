#include<bits/stdc++.h>
#define MOD 1000000000
using namespace std;
enum cordinate {N , S, W , E};
void display(int arr[]){
    for( int i = N ; i <=E;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
       
        int * a = new int[4];
        memset(a,0,sizeof(a));
       
        display(a);

        int len = s.length();
        int temp =1;
        stack<int> num ;
        num.push(temp);
        for(int i=0;i<len;i++){
            int val = s[i]-'0';
            if(0<val && val<10){
                i++;
                num.push(val);
                temp=temp*num.top();
            }
            else if(s[i]==')'){
                temp=temp/num.top();
                num.pop();
            }
            else{
                cout<<"printing temp "<<temp<<endl;
                if(s[i]=='N')
                a[0]+=temp;
                else if(s[i]=='S')
                a[1]+=temp;
                else if(s[i]=='W')
                a[2]+=temp;
                else
                a[3]+=temp;
                
                //a[cordinate[s[i]]]+=temp;
            }
            
            display(a);
        }
        while(num.size()!=0){
            temp*=num.top();
            num.pop();
        }
        for ( int i=0;i<4;i++)
            a[i]+=temp;
        display(a);
        cout<<"X-cordinate is "<<(a[3]-a[2]+1)%MOD<<endl;
        cout<<"Y-cordinate is "<<(a[1]-a[0]+1)%MOD<<endl;
        delete[] a;
    }
    return 0;
}