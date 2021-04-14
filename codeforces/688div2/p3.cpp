#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
struct points{
    int x;
    int y;
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> vec(n);
        rep(i,0,n)cin>>vec[i];
        vector<vector<points>> precompx(n, vector<points>(10));
        vector<vector<points>> precompy(n, vector<points>(10));
        // vector<vector<bool>> ispresentx(n, vector<bool>(10));
        // vector<vector<bool>> ispresenty(n, vector<bool>(10));
        vector<int> maxx(10,-1);
        vector<int> maxy(10,-1);
        vector<int> minx(10,n);
        vector<int> miny(10,n);

        rep(i,0,n){
            vector<points> tempscal(10,{n,-1});
            rep(j,0,n){
                maxx[vec[i][j]-'0'] = max(maxx[vec[i][j]-'0'], j);      
                minx[vec[i][j]-'0'] = min(minx[vec[i][j]-'0'], j);
                maxy[vec[i][j]-'0'] = max(maxy[vec[i][j]-'0'], i);
                miny[vec[i][j]-'0'] = min(miny[vec[i][j]-'0'], i);

                // ispresentx[i][vec[i][j]-'0'] = true;
                tempscal[vec[i][j]-'0'].x = min( tempscal[vec[i][j]-'0'].x,j);
                tempscal[vec[i][j]-'0'].y = max( tempscal[vec[i][j]-'0'].y,j);
            }
            rep(j,0,10){
                precompx[i][j].x = tempscal[j].x;
                precompx[i][j].y = tempscal[j].y;
            }
        }

        rep(j,0,n){
            vector<points> tempscal(10,{n,-1});
            rep(i,0,n){

                // ispresenty[j][vec[i][j]-'0'] = true;
                tempscal[vec[i][j]-'0'].x = min( tempscal[vec[i][j]-'0'].x,i);
                tempscal[vec[i][j]-'0'].y = max( tempscal[vec[i][j]-'0'].y,i);
            }
              rep(i,0,10){
                precompy[j][i].x = tempscal[i].x;
                precompy[j][i].y = tempscal[i].y;
            }
        }
        // cout<<"maxx\n";
        // for(auto a:maxx){
        //     cout<<a<<" ";
        // }
        // cout<<endl;
        // cout<<"minx\n";
        // for(auto a:minx){
        //     cout<<a<<" ";
        // }
        // cout<<endl;
        // cout<<"maxy\n";
        // for(auto a:maxy){
        //     cout<<a<<" ";
        // }
        // cout<<endl;
        // cout<<"miny\n";
        // for(auto a:miny){
        //     cout<<a<<" ";
        // }
        // cout<<endl;

        rep(i,0,10){
            int64_t ans = 0;
            rep(j,0,n){
                int64_t tempans = 0;
                if(precompx[j][i].y - precompx[j][i].x>0){

                int64_t base = (precompx[j][i].y - precompx[j][i].x);
                
                tempans = max((base*(n-j-1)), tempans);
                tempans = max((base*(j+1)), tempans);
                ans = max(ans, tempans);
                }
                
            else if(precompx[j][i].y==-1){
                continue;
                }
            else{
                int64_t base = max(precompx[j][i].y, n - precompx[j][i].y-1);
                 if(maxy[i]!=-1){
                    tempans = max((base*(maxy[i]-j)), tempans);
                }
                if(miny[i]!=n){
                    tempans = max((base*(j-miny[i])), tempans);
                }
            }
            }
            rep(j,0,n){
                int64_t tempans = 0;
                if(precompy[j][i].y - precompy[j][i].x>0){

                int64_t base = (precompy[j][i].y - precompy[j][i].x);
                
                tempans = max((base*(n-j-1)), tempans);
                tempans = max((base*(j+1)), tempans);
                ans = max(ans, tempans);
                }
                
            else if(precompy[j][i].y==-1){
                continue;
                }
            else{
                int64_t base = max(precompy[j][i].y, n - precompy[j][i].y-1);
                 if(maxx[i]!=-1){
                    tempans = max((base*(maxx[i]-j)), tempans);
                }
                if(minx[i]!=n){
                    tempans = max((base*(j-minx[i])), tempans);
                }
            }
            }

            // rep(j,0,n){
            //     if(precompy[j][i].y - precompy[j][i].x>0){

            //     int64_t base = (precompy[j][i].y - precompy[j][i].x+1);
            //     int64_t tempans = 0;
            //     if(maxx[i]!=-1){
            //         tempans = max(base*(maxx[i]-j+1)/2, tempans);
            //     }
            //     if(minx[i]!=n){
            //         tempans = max(base*(j-minx[i]+1)/2, tempans);
            //     }
            //     ans = max(ans, tempans);
            //     }
                
            // }
            cout<<ans<<" ";
        }
        cout<<endl;
        


    }
    return 0;
}