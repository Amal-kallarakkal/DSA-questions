class Solution {
public:
    string compressedString(string word) {
        int i = 0, n = word.size();
        string res = "";
        int count = 0;
        while(i < n){
            count++;
            if(count == 9){
                res += count + '0';
                res += word[i-1];
                count = 0;
            }else if(word[i] != word[i + 1] || i == n-1){
                res += count + '0';
                res += word[i];
                count = 0;
            }
            i++;
        }

        return res;
    }
};