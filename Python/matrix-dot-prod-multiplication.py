"""
Write a function array_mult that takes two two-dimensional arrays and performs a matrix multiplication,
return a new two-dimensional array. Each array should be represented as a list of lists, i.e., as a list of rows,
as discussed earlier. For example,

>>> M1 = [[1, 2, 3], [-2, 3, 7]]
>>> M2 = [[1,0,0],[0,1,0],[0,0,1]]
>>> array_mult(M1, M2)
[[1, 2, 3], [-2, 3, 7]]

>>> M3 = [[1], [0], [-1]]
>>> array_mult(M1, M3)
[[-2], [-9]]
"""

def array_mult(A, B):
    A_n = len(A) 
    A_m = len(A[0])
    B_n = len(B)
    B_m = len(B[0])
    assert A_m == B_n

    R_n = A_n
    R_m = B_m
    R = [[0 for j in range(R_m)] for i in range(R_n)]

    def row(M, r): return M[r]
    def col(M, c): return [v[c] for v in M]
    def dot(v1, v2): return sum([x*y for x, y in zip(v1, v2)])

    for i in range(R_n):
        for j in range(R_m):
            R[i][j] = dot(row(A,i), col(B,j))
    return R
