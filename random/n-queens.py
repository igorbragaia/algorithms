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


class NQueensIterativeSolver(ABC):
    def __init__(self):
        pass

    @abstractmethod
    def cost(self, queens: list) -> int:
        pass

    @abstractmethod
    def next(self, queens: list) -> list:
        pass

    @staticmethod
    def hash(queens: list):
        str_hash = ''
        n = len(queens)
        for i in range(n):
            str_hash += " ".join(['x' if Queen(i, j) in queens else 'o' for j in range(n)]) + "\n"
        return str_hash

    @staticmethod
    def all_possible_next_queens(queens, i):
        response = []
        n = len(queens)
        moves = [(0, 1), (0, -1), (1, 0), (-1, 0), (1, -1), (1, 1), (-1, 1), (-1, -1)]
        for move in moves:
            if 0 <= queens[i].x + move[0] < n and 0 <= queens[i].y + move[1] < n:
                new_queen = Queen(queens[i].x + move[0], queens[i].y + move[1])
                if new_queen not in queens:
                    response.append([queens[j] if j != i else new_queen for j in range(n)])
        return response

    def solve(self, n):
        if n < 1:
            raise Exception('let n be higher than zero')
        possible_positions = []
        for i in range(n):
            for j in range(n):
                possible_positions.append((i, j))

        done = set()
        path = []
        while not len(path):
            path = []
            queens = [Queen(pos[0], pos[1]) for pos in random.sample(possible_positions, n)]
            queens_hash = self.hash(queens)
            if queens_hash not in done:
                done.add(queens_hash)
                cost = 100*100
                while cost:
                    new_cost = self.cost(queens)
                    next_queens = self.next(queens)
                    if new_cost != cost:
                        cost = new_cost
                        path.append(next_queens)
                        queens = next_queens
                    else:
                        queens = []
                        path = []
                        break
                print(cost)
        return path


class HillClimbing(NQueensIterativeSolver):
    def __init__(self):
        super().__init__()

    def cost(self, queens: list):
        cost = 0
        for i in range(len(queens)):
            queen_cost = 0
            for j in range(len(queens)):
                queen_cost += queens[i].attacking(queens[j])
            cost += queen_cost
        return cost

    def next(self, queens):
        next_cost = self.cost(queens)
        next_queens = queens
        for i in range(len(queens)):
            for possible_next_queens in self.all_possible_next_queens(queens, i):
                possible_next_cost = self.cost(possible_next_queens)
                if possible_next_cost < next_cost:
                    next_cost = possible_next_cost
                    next_queens = possible_next_queens
        return next_queens


if __name__ == '__main__':
    hillclimbing = HillClimbing()
    path = hillclimbing.solve(5)
    i = 1
    for queens in path:
        print("iteracao {0}".format(i))
        print(hillclimbing.hash(queens))
        print()
        i += 1
