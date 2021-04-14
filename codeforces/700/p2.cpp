#include<bits/stdc++.h>
using namespace std;
const int INF = 1e5;
#define int int64_t
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        set<int> im;
        set<int> fucked;
        // vector<int> tyyy, uttt;
        // for(int i=0;i<n;i++){
        //     int a,b;
        //     cin>>a>>b;
        //     tyyy.push_back(a);
        //     uttt.push_back(b);
        // }

        // set<int> xvl, yvl;
        vector<int> xval(n), yval(n);

        for(int i=0;i<n;i++){
           
            // xvl.insert(tyyy[i]);
            // yvl.insert(uttt[i]);
            cin>>xval[i]>>yval[i];
        }
        // for(auto a:xvl){
        //     xval.push_back(a);
        // }
        // for(auto a:yvl){
        //     yval.push_back(a);
        // }
            sort(xval.begin(), xval.end());
            sort(yval.begin(), yval.end());
         int sumx = 0, sumy = 0;
        // sort(tyyy.begin(), tyyy.end());
        // sort(uttt.begin(), uttt.end());
        for(int i=n-1;i>=0;i--){
            // tyyy[i]-=tyyy[0];
            // uttt[i]-=uttt[0];
            xval[i]-=xval[0];
            yval[i]-=yval[0];
            sumx+=xval[i];
            sumy+=yval[i];
        }
        for(auto a:xval){
            im.insert(a);
        }
        for(auto a:yval){
            fucked.insert(a);
        }
        if(im.size()==1 && fucked.size()==2){
            int val = *fucked.begin();
            auto it = fucked.begin();
            it++;
            cout<<*it - val+1<<endl;
            continue;
        }else if(fucked.size()==1 && im.size()==2){
            int val = *im.begin();
            auto it = im.begin();
            it++;
            cout<<*it - val + 1<<endl;
            continue;
        }

        sumx/=n;
        sumy/=n;

        int p = n;
        int q = n;

        vector<int> xdist(n), ydist(n);
       
        // for(int i=p-1;i>=0;i--){
        //     xval[i]-=xval[0];
        // }
        // for(int i=q-1;i>=0;i--){
        //     yval[i]-=yval[0];
        // }

        int accumx = 0, accumy = 0;
        for(int i=p-1;i>=0;i--){
            accumx+=xval[i];
        }
        for(int i=q-1;i>=0;i--){
            accumy+=yval[i];
        }
        
        
        xdist[0] = accumx;
        ydist[0] = accumy;
        set<pair<int,int>> pointmap;
        for(int i=1;i<p;i++){
            xdist[i] = xdist[i-1] + (i)*(xval[i] - xval[i-1]) - (p-i)*(xval[i]-xval[i-1]);
        }
        for(int i=1;i<q;i++){
            ydist[i] = ydist[i-1] + (i)*(yval[i] - yval[i-1]) - (q-i)*(yval[i]-yval[i-1]);
        }

        map<int,int> mp;
        for(int i=0;i<p;i++){
            for(int j=0;j<q;j++){
                if(pointmap.find({xval[i], yval[j]}) == pointmap.end()){

                // cout<<xdist[i]<<" "<<i<<" "<<xval[i]<<"          ";
                // cout<<ydist[j]<<" "<<j<<" "<<yval[j]<<endl;
                mp[xdist[i] + ydist[j]]++;
                }
                pointmap.insert({xval[i],yval[j]});

            }
        }
        
       
        for(auto i: {-1,0,1}){
            for(auto j:{-1,0,1}){
                 int distx = 0;
                int disty = 0;
                int pointx = sumx + i;
                int pointy = sumy + j;
                if(pointmap.find({pointx, pointy})==pointmap.end()){
                    for(int k=0;k<n;k++){
                        distx+= abs(xval[k] - pointx);
                        disty+=abs(yval[k] - pointy);
                    }
                    mp[distx + disty]++;

                }
                pointmap.insert({pointx, pointy});
            }
        }
       
        
        // distx = 0;
        //  disty = 0;
        // for(int i=0;i<n;i++){
        //     distx+= abs(tyyy[i] - sumx);
        //     disty+=abs(uttt[i] - sumy+1);
        // }
        // mp[distx+ disty]++;
        // distx = 0;
        //  disty = 0;
        // for(int i=0;i<n;i++){
        //     distx+= abs(tyyy[i] - sumx+1);
        //     disty+=abs(uttt[i] - sumy);
        // }
        // distx = 0;
        //  disty = 0;
        // for(int i=0;i<n;i++){
        //     distx+= abs(tyyy[i] - sumx+1);
        //     disty+=abs(uttt[i] - sumy+1);
        // }
        // mp[distx+ disty]++;
        // mp[distx+ disty]++;
        //   distx = 0;
        //  disty = 0;
        // for(int i=0;i<n;i++){
        //     distx+= abs(tyyy[i] - sumx-1);
        //     disty+=abs(uttt[i] - sumy-1);
        // }
        // mp[distx+ disty]++;
      
        
        
        // for(auto a:mp){
        //     cout<<a.first<<" "<<a.second<<endl;
        // }
        cout<<mp.begin()->second<<endl;
        
        
        
    }
    


}