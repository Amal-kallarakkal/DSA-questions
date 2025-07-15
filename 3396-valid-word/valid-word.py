class Solution:
    def isValid(self, word: str) -> bool:
        vow = 0
        cons = 0
        other = 0
        num = 0
        n = len(word)
        if n < 3: return False
        vowels = ('a', 'A', 'e', 'E', 'i', 'I','o', 'O','u', 'U')

        for i in range(n):
            if word[i].isalpha():
                if word[i] in vowels: vow += 1
                else: cons += 1
            elif word[i].isdigit():
                num += 1
            else: 
                other += 1

        # dic = {"num" : num, "vow": vow, "cons": cons, "other": other}
        # print(dic)
        if vow and cons and not(other): return True
        return False
