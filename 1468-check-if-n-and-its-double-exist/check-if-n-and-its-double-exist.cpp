class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> set;
        for(int i : arr) set[i]++;
        if(set[0] >= 2) return true;
        for(int i : arr) if(i != 0 && set.count(2*i)) return true;
        return false;
    }
};