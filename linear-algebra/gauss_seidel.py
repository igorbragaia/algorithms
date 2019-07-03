import numpy as np

A = np.array([[5, 2, 1, 1], [2, 6, 2, 1], [1, 2, 7, 2], [1, 1, 2, 8]], dtype=np.float32)
b = np.array([[29], [31], [26], [19]], dtype=np.float32)

x = np.array([[0], [0], [0], [0]], dtype=np.float32)

rnorm = 1
k = 0
while rnorm > 1e-5:
    k += 1
    for i in range(A.shape[0]):
        x[i][0] = (1/A[i][i]) * (b[i][0] - sum([A[i][j] * x[j][0] for j in range(A.shape[1]) if j != i]))

    r = b - A.dot(x)
    rnorm = np.linalg.norm(r)
    print("ITERAÇÃO ", k)
    print(x)
    print("norma do erro r")
    print(rnorm)
    print("")
