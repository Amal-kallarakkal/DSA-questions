class Solution {
public:
    unordered_set<int> set;
    bool checkPowersOfThree(int n) {
        if(n == 0) return true;
        int i = 0, temp = 1;
        while(n >= temp) {
            temp *= 3;
            i++;  
        }
        if(set.count(i)) return false;
        else set.insert(i);
        n -= temp/3;
        return checkPowersOfThree(n) ;
    }
};