class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        ans = [words[0]]

        for i in range(1, len(words)):
            curr = ''.join(sorted(words[i]))
            prev = ''.join(sorted(words[i-1]))
            if curr != prev:
                ans.append(words[i])

        return ans


        