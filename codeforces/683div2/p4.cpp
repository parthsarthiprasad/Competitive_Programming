#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ll int64_t
struct holder{
    int astart;
    int bstart;
    int weight;
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string a,b;
        cin>>a;
        cin>>b;
        vector<vector<holder>> lcs(n+1, vector<holder>(m+1));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                lcs[i][j] = {i,j,0};
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i-1] == b[j-1]){
                    
                    lcs[i][j].weight = lcs[i-1][j-1].weight +1 ;
                    lcs[i][j].astart = lcs[i-1][j-1].astart;
                    lcs[i][j].bstart = lcs[i-1][j-1].bstart;
                    if(lcs[i-1][j-1].weight==0){
                        lcs[i][j].astart = i;
                         lcs[i][j].bstart = j;
                    }
     
                }else{
                    if(lcs[i][j].weight < lcs[i-1][j].weight){
                        lcs[i][j].weight = lcs[i-1][j].weight ;
                        lcs[i][j].astart = lcs[i-1][j].astart;
                        lcs[i][j].bstart = lcs[i-1][j].bstart;
                    }
                    if(lcs[i][j].weight < lcs[i][j-1].weight){
                        lcs[i][j].weight = lcs[i][j-1].weight ;
                        lcs[i][j].astart = lcs[i][j-1].astart;
                        lcs[i][j].bstart = lcs[i][j-1].bstart;
                    }
                
                }
            }
        }

        long long int tempscore = 0;
        long long int maxscore = 0;
        for(int i=0;i<=n;i++){
            int stridex = 0;
            int stridey = 0;
            for(int j=0;j<=m;j++){
            
                long long tkval = 4*(lcs[i][j].weight) - (i-lcs[i][j].astart+1) - (j-lcs[i][j].bstart+1);
                if(tkval>maxscore){
                    maxscore = tkval;
                }
            }
        }
        cout<<maxscore<<endl;

        // pair<int,int> start = {n,m};
        // pair<int,int> end = {-1,-1};
        // int i=n-1, j =m-1;
        // for(;i>=0;i--){
        //     for()
        // }
        // while(i>0 && j>0){
        //     while(i>0 && lcs[i][j] == lcs[i-1][j]){

        //     } 
        //     if(a[i-1] == b[j-1]){
        //         pointsoflcs.push_back({i,j});
        //         i--;
        //         j--;
        //     }
        //     else if(lcs[i-1][j].weight>=lcs[i][j-1].weight){
        //         i--;
        //     }
        //     else{
        //         j--;
        //     }
        // }
        // for(auto a:pointsoflcs){
        //     cout<<a.first<<" "<<a.second<<endl;
        // }

        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=m;j++){
        //         cout<<"{"<<lcs[i][j].weight<<", "<<lcs[i][j].astart<<", "<<lcs[i][j].bstart<<"} ";
        //     }
        //     cout<<endl;

        // }
        
    }
    return 0;

}