class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ios::sync_with_stdio(0);
        long long sum = 0;
        long long diff = 0;
        int n = happiness.size();
        sort(happiness.begin(), happiness.end());

        for(int i = n-1 ; i >= 0; i--) {
            if(k && happiness[i] > diff) sum += happiness[i] - diff;
            else break;
            diff++;
            k--;
            cout<<diff<<endl;
        }

        return sum;
    }
};