import numpy as np
import random
import time


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

        self._metadata = {}
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

    @property
    def metadata(self):
        return self._metadata

    @metadata.setter
    def metadata(self, metadata):
        self._metadata = metadata

    def cost(self):
        positions = self._queens
        cost = 0
        for i in range(len(positions)):
            positions_cost = 0
            for j in range(len(positions)):
                positions_cost += positions[i].attacking(positions[j])
            cost += positions_cost
        return cost

    def moves_list(self, i: int) -> list:
        positions = self._queens
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

    def __str__(self):
        str_hash = ''
        n = len(self._queens)
        for i in range(n):
            str_hash += " ".join(['x' if Queen(i, j) in self._queens else 'o' for j in range(n)]) + "\n"
        return str_hash


class HillClimbing:
    def __init__(self):
        pass

    def next(self, queens: Queens):
        # greedy choose
        next_cost = queens.cost()
        next_queens = queens
        for i in range(len(queens.positions)):
            for possible_next_queens in queens.moves_list(i):
                possible_next_cost = possible_next_queens.cost()
                if possible_next_cost < next_cost:
                    next_cost = possible_next_cost
                    next_queens = possible_next_queens
        return next_queens

    def solve(self, n) -> Queens:
        while True:
            queens = Queens(n)
            cost = 100 * 100
            while cost:
                next_queens = self.next(queens)
                new_cost = next_queens.cost()
                print(new_cost)
                if new_cost != cost:
                    cost = new_cost
                    queens = next_queens
                else:
                    break
            if cost == 0:
                return queens


if __name__ == '__main__':
    start_time = time.time()
    hillclimbing = HillClimbing()
    queens = hillclimbing.solve(5)
    print(queens)
    print("%.2f seconds" % (time.time() - start_time))
