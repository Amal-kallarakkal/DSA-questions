class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_set<int> set;
        int i = 0, j = 0, temp, ti;
        int n = fruits.size();
        int maxi = 0;
        while(i < n - maxi) {
            j = i;
            while(j < n) {
                set.insert(fruits[j]);
                if(set.size() >= 3) break;   
                j++;
            }
            maxi = max(maxi, j - i);
            // cout<<i<<" size: "<<set.size()<<" j: "<<j<<endl;
            set.clear();
            i++;
            cout<<i<<endl;
        }
        return maxi;
    }
};