using ll = long long int;
class Solution {
    int m = pow(10, 9) + 7;
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        ll ans = 0;
        ll sum = 0;
        ll i = 0;
        int n = chalk.size();
        while(i < n && sum < m ) {
            sum += chalk[i];
            i++;
        }
        // cout<<sum<<endl;
        k = k%sum;
        // cout<<"k: "<<k;
        i = 0;
        while(k > 0) {
            k -= chalk[i];
            if(k < 0) return i;
            i++;
            if(i >= n) i = 0;
            // ans = i;
        }
        return i;
    }
};