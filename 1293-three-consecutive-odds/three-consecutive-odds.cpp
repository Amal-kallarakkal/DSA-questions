class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
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