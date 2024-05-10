class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        ios::sync_with_stdio(0);
        vector<int> ans(2);
        map<double,pair<int, int>> mp;

        for(int i = 0; i < arr.size() - 1; i++) {
            for(int j = i + 1; j < arr.size(); j++) {
                pair<int, int> x = make_pair(arr[i], arr[j]);
                mp[double(arr[i])/arr[j]] = x;
            }
        }
        int indx = 1;
        for(auto x : mp) {
            if(indx == k) {
                    return {x.second.first, x.second.second};
            }
            indx++;             
        }

       return ans;
    }
};