class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>> mp;
        for(int i=0;i<strs.size();i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(i);
        }
        vector<vector<string>> ans(mp.size());
        int i=0;
        for(auto a: mp){
            for(auto m:a.second){
                ans[i].push_back(strs[m]);
            }
            i++;
        }
        return ans;
    }
};