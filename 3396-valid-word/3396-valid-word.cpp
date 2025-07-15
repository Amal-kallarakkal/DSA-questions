class Solution {
public:
    bool isValid(string word) {
        int vowel = 0, consonant = 0, nums = 0, ascii = 0, other = 0;
        int n = word.size();
        unordered_set<int> vow = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
        unordered_set<int> num = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        if(n < 3) return false;

        for(int i = 0 ; i < n; i++) {
            ascii = int(word[i]);
            if((ascii >= 65 && ascii <= 90) ||  (ascii >= 97 && ascii <= 122)) {
                if(vow.count(word[i])) vowel++;
                else consonant++;
            }            
            else if(num.count(word[i])) nums++;
            else other++;
        }
        // cout<<nums<<", "<<vowel<<", "<<consonant<<", "<<other;
        return (vowel && consonant && !other);
    }
};