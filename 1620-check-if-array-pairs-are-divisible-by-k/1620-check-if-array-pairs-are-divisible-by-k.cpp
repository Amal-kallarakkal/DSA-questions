class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int, int> mp;
        
        for(int x : arr) {
            mp[((x % k) + k) % k]++;
        }
        int a =  arr.size();
        int rem ;

        // for(auto x : mp) {
        //     cout<<x.first<<" : "<<x.second<<endl;
        // }
        for(int x : arr) {
            // cout<<x.first<<" : "<<x.second<<endl;
            rem = x%k;
            // cout<<rem<<" and "<<k - rem<<endl;
            if(rem == 0) {
                if(mp[rem]%2 == 1) return false;
            } 
            else if(mp[rem] != mp[k - rem ]) return false;
            // else if(mp[2*rem]%2 != k) return false;
        }
        
        return true;
    }
};