import numpy as np
import random
import time


class Queen(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def attacking(self, other):
        if self.x == other.x and self.y == other.y:
            return False
        return self.x == other.x or self.y == other.y or np.abs(self.x - other.x) == np.abs(self.y - other.y)

    def swap(self, other):
        self.x, other.x = other.x, self.x

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y

    def __ne__(self, other):
        return self.x != other.x or self.y != other.y

    def __str__(self):
        return 'x={0}, y={1}'.format(self.x, self.y)


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
        self.shuffle()

    def shuffle(self):
        h = list(range(self.n))
        random.shuffle(h)
        v = list(range(self.n))
        random.shuffle(v)

        self._queens = [Queen(h[i], v[i]) for i in range(self.n)]

    @property
    def positions(self):
        if not len(self._queens):
            self.shuffle()
        return self._queens

    @positions.setter
    def positions(self, positions):
        self._queens = positions

    def cost(self):
        positions = self._queens
        cost = 0
        for i in range(len(positions)):
            positions_cost = 0
            for j in range(len(positions)):
                positions_cost += positions[i].attacking(positions[j])
            cost += positions_cost
        return cost

    def move(self, choices=None):
        if not choices:
            [first, second] = random.choices(list(range(self.n)), k=2)
        self._queens[first].swap(self._queens[second])
        return choices

    def __str__(self):
        str_hash = ''
        n = len(self._queens)
        for i in range(n):
            str_hash += " ".join(['x' if Queen(i, j) in self._queens else 'o' for j in range(n)]) + "\n"
        return str_hash


class SimulatedAnnealing:
    def __init__(self):
        pass

    def solve(self, n, maxsteps):
        queens = Queens(n)

        for step in range(maxsteps):
            cost = queens.cost()

            if step % 1000 == 0:
                print(cost)

            if cost == 0:
                return queens
            fraction = step / maxsteps  # increases over time
            T = 1 - fraction  # decreases over time

            move = queens.move()
            new_cost = queens.cost()
            if not (new_cost < cost or np.exp(-(new_cost - cost)/T) > random.random()):
                # revert movement
                queens.move(choices=move)

        return queens


if __name__ == '__main__':
    start_time = time.time()
    simulatedannealing = SimulatedAnnealing()
    queens = simulatedannealing.solve(15, 20000)
    # hillclimbing = HillClimbing()
    # queens = hillclimbing.solve(5)
    print(queens)
    print("COST: {0}".format(queens.cost()))
    print("%.2f seconds" % (time.time() - start_time))
