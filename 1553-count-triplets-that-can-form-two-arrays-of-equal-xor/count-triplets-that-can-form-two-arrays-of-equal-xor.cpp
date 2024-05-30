class Solution {
public:

    // int solve(int i, int j, int k, vector<int> &arr, unordered_map<int,int> &mp) {
        
    //     if(mp[i + (j<<k)]) return 0;

    //     int ans = 0;
    //     int xorij = arr[i];
    //     int xorjk = arr[j];

    //     int ind = i;
    //     while(ind + 1 <j) {
    //         xorij = xorij^arr[ind+1];
    //         ind++;
    //     }

    //     ind = j;

    //     while(ind + 1 <= k) {
    //         xorjk = xorjk^arr[ind+1] ;
    //         ind++;
    //     }

    //     if(xorij == xorjk) {
    //         ans = 1;
    //         cout<<i<<", "<<j<<" ,"<<k<<endl;
    //         mp[i + (j<<k)]++;
    //     }

    //     int si = (i+1 < j)? solve(i+1, j, k, arr, mp):0;
    //     int sj = (j<k)? solve(i, j+1, k, arr, mp): 0;
    //     int sk = (k + 1 < arr.size())? solve(i, j, k+1, arr, mp): 0;

    //     return  ans + si + sj + sk;       

    // }

    int countTriplets(vector<int>& arr) {
        ios::sync_with_stdio(0);
        // unordered_map<int,int> mp;
// solve(0,1,1,arr, mp)
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