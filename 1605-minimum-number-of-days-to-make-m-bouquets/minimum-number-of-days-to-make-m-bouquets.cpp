class Solution {
public:
    bool IsPossible(vector<int> &bloomDay,int mid, int m, int k) {
        int n = bloomDay.size();
        
        int count = 0;
        int i = 0;
        // int j = 0;
        int result = 0;
        while(i<n) {
            
            if(bloomDay[i]<=mid && count<k) {
                count++;
                if(count == k) {
                    result++;
                    count = 0;
                }
            } else {
                count = 0;
            }
            i++;
        }
        //  cout<<"result: "<<result<<endl;
        if(result>= m ) {
            return true;
        }

        return false;

    }

    int binarySearch(vector<int> &bloomDay,int low,int high,int m, int k) {

        //base case
        if(low>=high) {
            return low;
        }
        int mid = low + (high - low)/2;
        if(IsPossible(bloomDay, mid, m, k)) {
            int ans = mid;
            high = mid ;
            //  cout<<"ans: "<<ans<<endl;
            ans = min(binarySearch(bloomDay, low, high, m, k),ans);
            return ans;
        }

        return binarySearch(bloomDay, mid +1, high, m, k);
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        //check if possible 
        // long long int total = ;
        int n = bloomDay.size();
        if(k>n||m>n||m*k>n) {
            return -1;
        } else {
            int low = 1;
            int max = INT_MIN;
            // int min = INT_MAX;
            for(int i = 0 ; i<n ; i++) {
                if(bloomDay[i]>max) max = bloomDay[i];
                // if(bloomDay[i]<min) min = bloomDay[i];
            }
            // cout<<max<<endl;
            int high = max ;
            // low = min;
            int ans = binarySearch(bloomDay, low, high, m, k);
            return ans;
        }
    }
};