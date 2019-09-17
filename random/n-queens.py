from abc import ABC, abstractmethod
import numpy as np
import random


class Queen(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def attacking(self, queen):
        if self.x == queen.x and self.y == queen.y:
            return False
        return self.x == queen.x or self.y == queen.y or np.abs(self.x - queen.x) == np.abs(self.y - queen.y)

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y

    def __ne__(self, other):
        return self.x != other.x or self.y != other.y


class Queens(object):
    def __init__(self, n):
        if n < 1:
            raise Exception('let n be higher or equal to 1')
        possible_positions = []
        for i in range(n):
            for j in range(n):
                possible_positions.append((i, j))

        self.n = n
        self._queens = []
        self.possible_positions = possible_positions

    def shuffle(self):
        self._queens = [Queen(pos[0], pos[1]) for pos in random.sample(self.possible_positions, self.n)]

    @property
    def positions(self):
        if not len(self._queens):
            self.shuffle()
        return self._queens

    @positions.setter
    def positions(self, positions):
        self._queens = positions

    def __str__(self):
        str_hash = ''
        n = len(self._queens)
        for i in range(n):
            str_hash += " ".join(['x' if Queen(i, j) in self._queens else 'o' for j in range(n)]) + "\n"
        return str_hash


class NQueensIterativeSolver(ABC):
    def __init__(self):
        pass

    @abstractmethod
    def cost(self, queens: Queens) -> int:
        pass

    @abstractmethod
    def next(self, queens: Queens) -> Queens:
        pass

    @staticmethod
    def moves_list(queens: Queens, i: int) -> list:
        positions = queens.positions
        response = []
        n = len(positions)
        moves = [(1, -1), (1, 1), (-1, 1), (-1, -1)]
        for move in moves:
            if 0 <= positions[i].x + move[0] < n and 0 <= positions[i].y + move[1] < n:
                new_queen = Queen(positions[i].x + move[0], positions[i].y + move[1])
                if new_queen not in positions:
                    new_queens = Queens(n)
                    new_queens.positions = [positions[j] if j != i else new_queen for j in range(n)]
                    response.append(new_queens)
        return response

    def solve(self, n) -> Queens:
        while True:
            queens = Queens(n)
            cost = 100 * 100
            while cost:
                new_cost = self.cost(queens)
                next_queens = self.next(queens)
                if new_cost != cost:
                    cost = new_cost
                    queens = next_queens
                else:
                    break
            print(cost)
            if not cost:
                return queens


class HillClimbing(NQueensIterativeSolver):
    def __init__(self):
        super().__init__()

    def cost(self, queens: Queens):
        positions = queens.positions
        cost = 0
        for i in range(len(positions)):
            positions_cost = 0
            for j in range(len(positions)):
                positions_cost += positions[i].attacking(positions[j])
            cost += positions_cost
        return cost

    def next(self, queens: Queens):
        next_cost = self.cost(queens)
        next_queens = queens
        for i in range(len(queens.positions)):
            for possible_next_queens in self.moves_list(queens, i):
                possible_next_cost = self.cost(possible_next_queens)
                if possible_next_cost < next_cost:
                    next_cost = possible_next_cost
                    next_queens = possible_next_queens
        return next_queens


if __name__ == '__main__':
    hillclimbing = HillClimbing()
    queens = hillclimbing.solve(5)
    print(queens)
