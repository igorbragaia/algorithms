import numpy as np


class K_Means:
    def __init__(self, data_set, k):
        """
        :param data_set: list of numpy arrays equally shaped
        :param k: desired amount of clusters
        """
        self.k = k
        self.data_set = [Matrix(matrix) for matrix in data_set]
        self.shape = self.__get_shape()

    def __get_shape(self):
        """
        Check if all data set is equally shaped
        :return: data set shape
        """
        shape = None
        for data in self.data_set:
            if shape is None:
                shape = data.matrix.shape
            elif shape != data.matrix.shape:
                raise Exception("data set with different matrices shapes!")
        return shape

    def run(self):
        """Clusterize data set through K-Means algorithm
        :param k: desired amount of clusters
        :return: {cluster: list of data}
        """
        # generate random initial centroids
        centroids = [Matrix(np.random.randn(self.shape[0], self.shape[1])) for _ in range(self.k)]

        # dictionary {data: corresponding cluster}
        data_set_clustered = {}

        # dictionary {cluster: list of data}
        clusters = {}

        # amount of data that have changed its cluster on each k-means training step
        clustering_movements = len(self.data_set)

        i = 0
        while clustering_movements > 0:
            i += 1
            clustering_movements = 0
            clusters = {centroid: [] for centroid in centroids}
            for data in self.data_set:
                max_distance = -2
                cluster = None
                for centroid in clusters:
                    centroid_data_cosine = data > centroid
                    if centroid_data_cosine > max_distance:
                        max_distance = centroid_data_cosine
                        cluster = centroid
                clusters[cluster].append(data)
                if data in data_set_clustered and cluster != data_set_clustered[data] or data not in data_set_clustered:
                    data_set_clustered[data] = cluster
                    clustering_movements += 1
            # create new centroids as cluster's data mean
            new_centroids = []
            for centroid in clusters:
                if len(clusters[centroid]) != 0:
                    new_centroid = Matrix(sum([obj.matrix for obj in clusters[centroid]]) / len(clusters[centroid]))
                    new_centroids.append(new_centroid)
                else:
                    new_centroids.append(centroid)
            centroids = new_centroids
            print('epoch: ', i, ', total clustering movements: ', clustering_movements)
        print('------------------')
        cluster_id = 0
        for key, value in clusters.items():
            cluster_id += 1
            print('cluster ', cluster_id, ': ', len(value), ' elements')
        print('------------------')
        return data_set_clustered


class Matrix(object):
    def __init__(self, matrix, normalized=True):
        self.matrix = matrix
        self.module = np.sqrt(self.innerProduct(matrix, matrix))
        if self.module == 0:
            raise Exception('Matrix module equal to zero.')
        if normalized:
            self.matrix = self.matrix / self.module

    def __eq__(self, other):
        return (isinstance(other, self.__class__) and self.__hash__() == other.__hash__())

    def __ne__(self, other):
        return not self.__eq__(other)

    def __hash__(self):
        return hash(str(self.matrix))

    def __lt__(self, other):
        return self.cosine_similarity(self.matrix, other.matrix)

    def __repr__(self):
        return "module {0:0.1f}".format(round(self.module, 2))

    def cosine_similarity(self, A, B):
        """
        :param A: numpy matrix
        :param B: numpy matrix
        :return: float64
        """
        return self.innerProduct(A, B) / np.sqrt(self.innerProduct(A, A) * self.innerProduct(B, B))

    def innerProduct(self, A, B):
        """
        :param A: numpy matrix
        :param B: numpy matrix
        :return: float64
        """
        return np.trace(np.dot(A, B.transpose()))


if __name__ == '__main__':
	shape = (10, 10)
	matrices = [np.random.randn(shape[0], shape[1]) for _ in range(500)]

	amount_of_clusters = 5
	K_Means(matrices, amount_of_clusters).run()