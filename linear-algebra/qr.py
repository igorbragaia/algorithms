import numpy as np

A = np.array([[2, -2, 18], [2, 1, 0], [1, 2, 0]])


class QR:

    def __solve_householder(self, A):
        shape = A.shape[0]
        can = np.zeros((shape, 1))
        can[0][0] = 1

        col = np.transpose([A[:, 0]])
        v = np.add(col, np.sign(A[0][0]) * np.linalg.norm(col) * can)

        H = np.identity(shape) - 2 * v.dot(np.transpose(v)) / np.transpose(v).dot(v)

        return H

    def factorize(self, A):
        innerA = A
        shape = A.shape[0]
        Q = np.identity(shape)
        idx = 0
        Aprevious = A
        while idx < shape:
            innerA = innerA[idx:, idx:]
            h = self.__solve_householder(innerA)

            H = np.identity(shape)
            for i in range(h.shape[0]):
                for j in range(h.shape[1]):
                    H[i+idx][j+idx] = h[i][j]

            Q = Q.dot(H)
            innerA = H.dot(Aprevious)
            Aprevious = innerA

            idx += 1

        return [Q, innerA]


[Q, R] = QR().factorize(A)
print(Q)
print(R)