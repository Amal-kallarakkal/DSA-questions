class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> nums;
        int n = digits.size(), curr = 0, j;
        bool check;
        unordered_map<int, int> mp1, mp2;
        for(int i = 0 ; i < n ; i++) {
            mp1[digits[i]]++;
        }

        for(int i = 100; i < 999; i++) {
           mp2.clear();
           if(i%2) continue;
           curr = i;
           check = true;

           while(curr) {
                mp2[curr%10]++;
                curr /= 10;
           }
           for(auto x : mp2) {
                if(x.second > mp1[x.first]) {
                    check = false;
                    break;
                }
           }
           if(check) nums.push_back(i);
        }

        return nums;

    }
};