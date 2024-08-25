class Solution {
public:

    int findlcm(int a, int b) {
        return a*b/__gcd(a,b);
    }
    string fractionAddition(string s) {
        vector<int> num;
        vector<int> den;
        int a ;
        int n = s.size();
        string ans;
        int lcm = 1;

        if(s[0] != '-' && s[0] != '+') {
            if(1 < n - 1 && (s[0] == '1' && s[1] == '0')) {
                num.push_back(10);
            }
            else num.push_back(s[0] - '0');
        } 

        for(int i = 1 ; i < n; i++) {
            if(s[i - 1] == '-' || s[i - 1] == '+') {
                if(i < n - 1 && (s[i] == '1' && s[i+1] == '0')) {
                    if(s[i - 1] == '-') num.push_back(-10);
                    else num.push_back(10);
                } else {
                    a = s[i] - '0';
                    if(s[i - 1] == '-') num.push_back(-a);
                    else num.push_back(a);
                }                
            } else if(s[i - 1] == '/'){
                if(i < n - 1 && (s[i] == '1' && s[i+1] == '0')) {                    
                    den.push_back(10);
                }
                else den.push_back(s[i] - '0');
            }
        }
        
        for(int i = 0 ; i < den.size() ; i++) {
            lcm = findlcm(lcm, den[i]);
        }

        for(int i = 0 ; i < num.size() ; i++) {
            num[i] *= lcm/den[i];
        }
        int nans = 0;
        for(int i = 0 ; i < num.size() ; i++) {
            nans += num[i];
        }
        int fnum = nans/abs(__gcd(nans, lcm));
        int fden = lcm/abs(__gcd(nans, lcm));
        
        ans += to_string(fnum);        
        ans += '/';
        ans += to_string(fden);
        
        return ans;

    }
};