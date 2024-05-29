using ll = long long ;
class Solution {
public:
    
    int numSteps(string s) {
        ios::sync_with_stdio(0);
        ll cnt = 0;
        int i = s.size();
        
        while(s.size() > 1) {
            i = s.size() - 1;

            if(s[i] == '0') {                
                s.pop_back();         
            } else {
                int j = i;
                while(j >= 1 && s[j] != '0') {
                    if(s[j] == '1'){
                        s[j] = '0';                        
                    }                     
                    j--;
                }
                if(j>=1 && s[j] == '0') {
                    s[j] = '1';
                    
                } else {
                    s += '0';                   
                }                     
            }

            cnt++;  
            
        }        

        return cnt;
    }
};