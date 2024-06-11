#pragma GCC optimize("OFast")
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        ios::sync_with_stdio(0);
        map<int,int> mp2;
        vector<int> ans;
        int a, b, t;

        for(int i = 0; i < arr1.size(); i++) {
            mp2[arr1[i]]++;              
        }

        for(int i = 0 ; i < arr2.size(); i++) {
            t = mp2[arr2[i]];
            while(t--) {
                ans.push_back(arr2[i]);
                mp2[arr2[i]]--;
                if(!mp2[arr2[i]]) mp2.erase(arr2[i]);
            }
        }
        
        for(auto x: mp2) {
            a = x.first;
            b = x.second;
            while(b--) ans.push_back(a);
        }

        return ans;

    }
};