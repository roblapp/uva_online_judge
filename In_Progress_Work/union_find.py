class SetUnion:
    def __init__(self, n):
        self.__n = n
        self.__parent, self.__size = [], []
        for j in range(n):
            self.__parent.append(j)
            self.__size.append(0)

    def find(self, x):
        return x if self.__parent[x] == x else self.find(self.__parent[x])

    def union_sets(self, x, y):
        root1, root2 = self.find(x), self.find(y)
        if root1 == root2:
            return
        if self.__size[root1] >= self.__size[root2]:
            self.__size[root1] += self.__size[root2]
            self.__parent[root2] = root1
        else:
            self.__size[root2] += self.__size[root1]
            self.__parent[root1] = root2

    def is_same_component(self, x, y):
        return self.find(x) == self.find(y)