class Solution {
public:
    string largestGoodInteger(string num) {

        int n = num.size();
        
        string max_ans = "-1";

        int ans_num;     

        for(int i = 1 ; i < n-1 ; i++) {

            string ans ="";
            
            if(num[i-1] == num[i] &&(num[i] == num[i+1] && num[i-1] == num[i+1])) {
                ans = num.substr(i-1,3);
                ans_num  = max(stoi(ans),stoi(max_ans));
                max_ans = to_string(ans_num);
            }
           
        }

        if(max_ans == "-1") {
            max_ans = "";
        }

        if(max_ans == "0") {
            max_ans = "000";
        }

        return max_ans;
        
    }
};