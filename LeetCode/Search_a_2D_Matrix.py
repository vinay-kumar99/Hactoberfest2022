class Solution(object):
    def searchMatrix(self, matrix, target):
        i=0
        j= len(matrix[0])-1
        while i< len(matrix) and j >=0:
            if matrix[i][j]==target:
                return True
            if matrix[i][j]<target:
                i=i+1
                continue
            if matrix[i][j]> target:
                j=j-1
        return False
