class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        row = set()
        col = set()
        r = len(matrix)
        c = len(matrix[0])

        for i in range(0, r):
            for j in range(0, c):
                if matrix[i][j] == 0:
                    row.add(i)
                    col.add(j)

        for i in row: 
            for j in range(0, c):
                matrix[i][j] = 0

        for j in col:
            for i in range(0, r):
                matrix[i][j] = 0


        