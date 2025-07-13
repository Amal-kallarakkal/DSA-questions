class Solution:
    def matchPlayersAndTrainers(self, players: List[int], trainers: List[int]) -> int:
        cnt = 0
        i = 0 
        j = 0
        n = len(players) 
        m = len(trainers)
        players.sort()
        trainers.sort()
        while i < n and j < m: 
            if players[i] <= trainers[j] :
                cnt += 1
                i += 1
                j += 1
            else:
                j += 1
        return cnt
