class Solution {
public:
    string robotWithString(string s) {
        string p = "", t = "";
        int n = s.size();
        char minChar;
        vector<char> nums(n);
        nums[n-1] = s[n-1];

        for(int i = n - 2 ; i >= 0 ; i--) {
            nums[i] = min(nums[i+1], s[i]);
        }
        
        for(int i = 0 ; i < n; i++) cout<<nums[i];
        cout<<endl;
        int i = 0;
        while(i < n) {
            t.push_back(s[i]);
            minChar = i < n - 1 ? nums[i+1]: s[i];
            while(!t.empty() && t.back() <= minChar) {
                p += t.back();
                t.pop_back();
            } 
            i++;
        }
        while(!t.empty()) {
            p += t.back();
            t.pop_back();
        }

        return p;

    }
};