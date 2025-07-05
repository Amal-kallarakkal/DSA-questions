class Solution {
public:
    int findLucky(vector<int>& arr) {
        int ans = 0;
        map<int, int> mp;

        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i]]++;
        }

        for(auto x: mp) {
            if(x.first == x.second) ans = x.first;
        }
        return ans == 0 ? -1 : ans;
    }
};