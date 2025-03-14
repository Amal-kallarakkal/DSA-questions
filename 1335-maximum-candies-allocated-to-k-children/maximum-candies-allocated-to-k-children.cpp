class Solution {
public:

    bool isPossible(vector<int>& candies, int mid, long long k) {
        long long sum1 = 0;
        int n = candies.size();
        for(int j = 0 ; j < n ; j ++) {
            int x = candies[j]/mid;
            sum1 += x;
            if(sum1>=k) {
            return true;
            }
        }
        
        
        return false;
    }

    int binarySearch(vector<int>& candies, int low, int high, long long k, int ans) {
        
        while(low<=high) {
            
            int mid = (low + high)/2;

            if(isPossible(candies, mid, k)) {
                ans = mid;
                // cout<<"ans: "<<ans<<endl;
                low = mid + 1 ;
                
            } else {
                high = mid - 1;
            
            }

        }
        
        
            return ans;
    }

        
    

    int maximumCandies(vector<int>& candies, long long k) {
        
        int n = candies.size();
        sort(candies.begin(), candies.end());
        long long sum = accumulate(begin(candies),end(candies),0ll);

        
        if(sum<k) {
            return 0;
        }
        
        if(sum == k ) return 1;

        // return 1;
        int low = 1;
        int high = sum/k;
        int ans = 0;
        return binarySearch(candies, low, high, k, ans);
    }
};