class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());

        int i = 0, j = skill.size() - 1;
        int sum = skill[i] + skill[j];
        long long prod = skill[i++]*skill[j--];
        
        while(i < j) {
            if(skill[i] + skill[j] == sum) prod += skill[i]*skill[j];
            else return -1;
            i++; j--;
        }

        return prod;
    }
};

static const int speedup = []() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();