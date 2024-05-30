class Solution {
public:

    int countTriplets(vector<int>& arr) {
        ios::sync_with_stdio(0);
       
        int ans = 0;
        for(int i = 0; i < arr.size() -1  ; i++) {
            int Xor = arr[i];
            for(int j = i+ 1; j < arr.size(); j++) {
                Xor ^= arr[j];
                if(Xor == 0) {
                    // cout<<i<<", "<<j<<endl;
                    ans += j-i ;
                }
            }
            
        }
        return ans;
    }
};