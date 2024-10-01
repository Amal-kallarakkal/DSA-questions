class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int, int> mp;
        int rem;
        for(int x : arr) {
            mp[((x % k) + k) % k]++;
        }
       
        for(int x : arr) {
            rem = x%k;
            if(rem == 0) {
                if(mp[rem]%2 == 1) return false;
            } 
            else if(mp[rem] != mp[k - rem ]) return false;
        }
        
        return true;
    }
};