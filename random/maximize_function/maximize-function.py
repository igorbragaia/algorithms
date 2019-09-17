import numpy as np
import random
import time
import matplotlib.pyplot as plt


class Function(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.last_x = x
        self.last_y = y

    def cost(self):
        x = self.x
        y = self.y
        return 4 * np.exp(-(x ** 2 + y ** 2)) + np.exp(-((x - 5) ** 2 + (y - 5) ** 2)) + np.exp(-((x + 5) ** 2 + (y - 5) ** 2)) + np.exp(-((x - 5) ** 2 + (y + 5) ** 2)) + np.exp(-((x + 5) ** 2 + (y + 5) ** 2))

    def move(self):
        self.last_x = float(self.x)
        self.last_y = float(self.y)
        normal_values = np.random.normal(0, 10, 2)
        self.x += normal_values[0]
        self.y += normal_values[1]

    def revert_move(self):
        self.x, self.last_x = float(self.last_x), float(self.x)
        self.y, self.last_y = float(self.last_y), float(self.y)

    def __str__(self):
        return 'f({0}, {1}) = {2}'.format(round(self.x, 2), round(self.y, 2), round(self.cost(), 2))


class MaximizeFuntionSolver:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def SimulatedAnnealing(self, maxsteps):
        function = Function(self.x, self.y)

        steps = []
        costs = []
        for step in range(maxsteps):
            cost = function.cost()

            if step % 10 == 0:
                steps.append(step)
                costs.append(cost)

            fraction = step / maxsteps  # increases over time
            T = max(0.1, min(1, 1 - fraction))  # decreases over time

            function.move()
            new_cost = function.cost()
            deltaCost = new_cost - cost
            if not (deltaCost > 0 and np.exp(deltaCost/T) > random.random()):
                function.revert_move()
        return function, steps, costs

    def HillClimbing(self, maxsteps):
        function = Function(self.x, self.y)
        steps = []
        costs = []
        for step in range(maxsteps):
            cost = function.cost()

            if step % 10 == 0:
                steps.append(step)
                costs.append(cost)

            function.move()
            new_cost = function.cost()
            deltaCost = new_cost - cost
            if not deltaCost > 0:
                function.revert_move()

        return function, steps, costs


if __name__ == '__main__':
    while True:
        # seeds = [[2, 2], [7, -30]]
        seeds = [[100, 100]]
        for [x, y] in seeds:
            solver = MaximizeFuntionSolver(x, y)

            start_time = time.time()
            function, steps, costs = solver.HillClimbing(10000)
            print(function)
            with open('results/HillClimbing/log.txt', 'w') as f:
                f.write("RESULT\n{0}\nCOST: {1}\n{2} seconds\n".format(function, function.cost(), round((time.time() - start_time), 2)))
            plt.cla()
            plt.plot(steps, costs)
            plt.ylabel('cost')
            plt.xlabel('iteration')
            plt.savefig('results/HillClimbing/log.jpg')

            start_time = time.time()
            function, steps, costs = solver.SimulatedAnnealing(10000)
            print(function)
            with open('results/SimulatedAnnealing/log.txt', 'w') as f:
                f.write("RESULT\n{0}\nCOST: {1}\n{2} seconds\n".format(function, function.cost(), round((time.time() - start_time), 2)))
            plt.cla()
            plt.plot(steps, costs)
            plt.ylabel('cost')
            plt.xlabel('iteration')
            plt.savefig('results/SimulatedAnnealing/log.jpg')

        print('***')