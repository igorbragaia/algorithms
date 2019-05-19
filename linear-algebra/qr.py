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
        print(H)

        return H

    def factorize(self, A):
        innerA = A
        shape = A.shape[0]
        Q = np.identity(shape)
        idx = 0
        while idx < shape:
            print(idx)
            innerA = innerA[idx:, idx:]
            print(innerA)
            h = self.__solve_householder(innerA)
            print(h)
            if idx == 0:
                innerA = h.dot(innerA)
            print(innerA)

            H = np.identity(shape)
            for i in range(innerA.shape[0]):
                for j in range(innerA.shape[1]):
                    H[i+idx][j+idx] = innerA[i][j]

            print(H)

            idx += 1


QR().factorize(A)
