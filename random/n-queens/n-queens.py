import numpy as np
import random
import time
import matplotlib.pyplot as plt


class Queen(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def attacking(self, other):
        if self.x == other.x and self.y == other.y:
            return False
        return np.abs(self.x - other.x) == np.abs(self.y - other.y)

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
        self.n = n
        self._queens = []
        self.shuffle()

    def shuffle(self):
        h = list(range(self.n))
        random.Random(7).shuffle(h)
        v = list(range(self.n))
        random.Random(5).shuffle(v)

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
            for j in range(len(positions)):
                cost += positions[i].attacking(positions[j])
        return cost

    def move(self):
        [first, second] = random.choices(list(range(self.n)), k=2)
        self._queens[first].swap(self._queens[second])
        return [first, second]

    def revert_move(self, last_move):
        [first, second] = last_move
        self._queens[first].swap(self._queens[second])

    def __str__(self):
        str_hash = ''
        n = len(self._queens)
        for i in range(n):
            str_hash += " ".join(['x' if Queen(i, j) in self._queens else 'o' for j in range(n)]) + "\n"
        return str_hash


class NQueensSolver:
    def __init__(self, maxsteps):
        self.maxsteps = maxsteps

    def SimulatedAnnealing(self, n):
        queens = Queens(n)

        steps = []
        costs = []
        for step in range(self.maxsteps):
            cost = queens.cost()

            if step % 10 == 0:
                steps.append(step)
                costs.append(cost)

            fraction = step / self.maxsteps  # increases over time
            T = max(0.1, min(1, 1 - fraction))  # decreases over time

            move = queens.move()
            new_cost = queens.cost()
            if new_cost > cost or np.exp((new_cost - cost)/T) < random.random():
                queens.revert_move(move)

        return queens, steps, costs

    def HillClimbing(self, n):
        queens = Queens(n)
        steps = []
        costs = []
        for step in range(self.maxsteps):
            cost = queens.cost()

            if step % 10 == 0:
                steps.append(step)
                costs.append(cost)

            move = queens.move()
            new_cost = queens.cost()
            if new_cost > cost:
                queens.revert_move(move)

        return queens, steps, costs


if __name__ == '__main__':
    solver = NQueensSolver(20000)
    for qty in [25]:
        with open('results/{0}-log.txt'.format(qty), 'w') as f:
            print('n={0}\n\n'.format(qty))
            start_time = time.time()
            queens, steps, costs = solver.HillClimbing(qty)
            print(len(costs))
            f.write("Hill Climbing\nRESULT\n{0}\nCOST: {1}\n{2} seconds\n\n".format(queens, queens.cost(), round((time.time() - start_time), 2)))
            plt.cla()
            plt.plot(steps, costs)
            plt.ylabel('cost')
            plt.xlabel('iteration')
            print('HillClimbing')

            start_time = time.time()
            queens, steps, costs = solver.SimulatedAnnealing(qty)
            print(len(costs))
            f.write("Simulated Annealing\nRESULT\n{0}\nCOST: {1}\n{2} seconds\n".format(queens, queens.cost(), round((time.time() - start_time), 2)))
            plt.plot(steps, costs)
            plt.ylabel('cost')
            plt.xlabel('iteration')

            plt.legend(['Hill Climbing', 'Simulated Annealing'])
            plt.savefig('results/{0}-log.jpg'.format(qty))
            print('SimulatedAnnealing')
