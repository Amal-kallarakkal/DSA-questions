using ll = long long ;
class Solution {
public:
    
    int numSteps(string s) {
        ios::sync_with_stdio(0);
        ll cnt = 0;
        int i = s.size();
        
        while(s.size() > 1) {
            i = s.size() - 1;
            // if s is even pop the rightmost element(right shift or simply divide by 2)
            if(s[i] == '0') {                
                s.pop_back();         
            } 
            
            else {
                int j = i;
                while(j >= 1 && s[j] != '0') {
                    if(s[j] == '1'){
                        s[j] = '0';                        
                    }                     
                    j--;
                }
                // if odd we flip the rightmost "0" to "1" 
                if(j>=1 && s[j] == '0') {
                    s[j] = '1';                    
                } 
                // if no "0"s are present then we add '0' to string s
                else {
                    s += '0';                   
                }                     
            }

            cnt++;  
            
        }        

        return cnt;
    }
};