#pragma GCC optimize("OFast")
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        ios::sync_with_stdio(0);
        int sum = 0 ; 
        int avg = 0;
        int cnt = 0;

        for(int i = 0 ; i < k; i++) sum += arr[i];
        avg = sum/k;
        int j = 0;
        for(int i = 0; i < arr.size() - k; i++) {
            if(avg >= threshold) cnt++;
            j = i + k;
            sum -= arr[i];
            sum += arr[j];            
            avg = sum/k;            
        }
        if(avg >= threshold) cnt++;

        return cnt;
        
    }
};