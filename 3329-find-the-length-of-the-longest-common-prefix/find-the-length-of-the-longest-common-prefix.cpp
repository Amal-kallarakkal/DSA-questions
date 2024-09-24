class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int maxi = 0, k, ans;
        string s1 , s2;
        unordered_set<string> st1;
        unordered_set<string> st2;
        for(int i : arr1) {
            s1 = to_string(i);
            k = 1;
            while(k <= s1.size()) {
                st1.insert(s1.substr(0, k));
                k++;
            }
        } 

        for(int i : arr2) {
            s1 = to_string(i);
            k = 1;
            while(k <= s1.size()) {
                st2.insert(s1.substr(0, k));
                k++;
            }
        } 
        

        for(string i : st2) {
            // s2 = to_string(i);
            ans = 0;
            if(st1.count(i)) {
                ans = i.size();
            }
            maxi = max(maxi, ans);
           
        }
        
        return maxi;
    }
};

static const int speedup = [](){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();