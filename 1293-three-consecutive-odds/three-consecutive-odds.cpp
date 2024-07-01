#pragma GCC optimize("OFast")
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        ios::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
        int k,j;
        if(arr.size() <= 2) return false;
        for(int i = 0 ; i < arr.size() - 2; i++) {
            j = i + 1;
            k = j + 1;
            if(arr[i]%2 && arr[j]%2 && arr[k]%2)return true;
        }
        return false;
    }
};