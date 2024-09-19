class Solution {
public:
    vector<int> solve(string exp) {
        if(exp.size() <= 2 &&(exp[0] != '+' ||exp[0] != '*' ||exp[0] != '-')) {
            return {stoi(exp)};
        }
        vector<int> ans;
        string exp1, exp2;
        vector<int> ex1, ex2;
        int n = exp.size();
        for(int i = 0 ; i < n; i++) {
            if(exp[i] == '+' ||exp[i] == '*' ||exp[i] == '-') {
                ex1 = solve(exp.substr(0, i));
                ex2 = solve(exp.substr(i+1, n - i - 1));
                if(exp[i] == '+')  {
                    for(int i = 0 ; i < ex1.size(); i++) {
                        for(int j = 0 ; j < ex2.size(); j++) {
                            ans.push_back(ex1[i] + ex2[j]);
                        }
                    }
                } else if(exp[i] == '-')  {
                    for(int i = 0 ; i < ex1.size(); i++) {
                        for(int j = 0 ; j < ex2.size(); j++) {
                            ans.push_back(ex1[i] - ex2[j]);
                        }
                    }
                } else if(exp[i] == '*')  {
                    for(int i = 0 ; i < ex1.size(); i++) {
                        for(int j = 0 ; j < ex2.size(); j++) {
                            ans.push_back(ex1[i] * ex2[j]);
                        }
                    }
                }
            }
        }

        return ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        ans = solve(expression);
        return ans;
    }
};

const int speedup = []() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();