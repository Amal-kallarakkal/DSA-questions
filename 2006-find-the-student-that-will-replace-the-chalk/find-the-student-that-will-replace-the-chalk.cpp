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

        k = k%sum;
        i = 0;
        
        while(k > 0) {
            k -= chalk[i];
            if(k < 0) return i;
            i++;            
        }
        return i;
    }
};

static const int kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();