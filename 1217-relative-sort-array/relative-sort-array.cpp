#pragma GCC optimize("OFast")
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        ios::sync_with_stdio(0);
        unordered_map<int,int> mp;
        unordered_map<int,int> mp2;
        vector<int> ans(arr1.size());
        for(int i = 0 ; i < arr2.size(); i++) {
            mp[arr2[i]]  = i + 1;           
        }
        int end = arr1.size() - 1;
        for(int i = 0; i < arr1.size(); i++) {
            if(mp[arr1[i]]) mp2[arr1[i]]++;  
            else ans[end--] = arr1[i];
                
        }
        int k = 0;
        for(int i = 0 ; i < arr2.size(); i++) {
            int t = mp2[arr2[i]];
            while(t--) {
                ans[k] = arr2[i];
                k++;
            }
        }

        sort(ans.begin() + end + 1, ans.end());


        return ans;


    }
};