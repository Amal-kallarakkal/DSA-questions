class Solution {
public:
    bool isValid(string word) {
        int vowel = 0, consonant = 0, other = 0;
        int n = word.size();
        unordered_set<int> vow = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
        if(n < 3) return false;

        for(int i = 0 ; i < n; i++) {
            if(isalpha(word[i])) {
                if(vow.count(word[i])) vowel++;
                else consonant++;
            }            
            else if(!isdigit(word[i])) other++;
        }
        return (vowel && consonant && !other);
    }
};