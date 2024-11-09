using ll = long long;
class Solution {
public:
    string Bin(int n) {
        string ans ;
        while(n) {
            if(n%2) ans += '1';
            else ans += '0';
            n = n>>1;
        }
        return ans;
    }
    ll Dec(string n) {
        ll ans = 0;
        for(int i = 0 ; i < n.size(); i++) {
            if(n[i] == '1') {
                ans += pow(2, i);
                // cout<<ans<<endl;
            }
        }
        return ans;
    }

    long long minEnd(int n, int x) {
        ll ans;
        string x1 = Bin(x);
        string n1 = Bin(n-1);
        // cout<<x1<<endl<<n1;
        int i = 0, j = 0;
        for(int i = 0 ; i < n1.size(); i++) x1 += '0';
        
        while(i < x1.size() && j < n1.size()) {
            if(x1[i] == '0') x1[i] = n1[j++];
            i++;
        }
        // cout<<endl<<x1;
        ans = Dec(x1);
        return ans;
    }
};