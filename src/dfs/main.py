class Graph:
    def __init__(self):
        self.adj_list = {}

    def add_vertex(self, v):
        if v not in self.adj_list:
            self.adj_list[v] = []

    def add_edge(self, v1, v2):
        if v1 not in self.adj_list:
            self.add_vertex(v1)
        if v2 not in self.adj_list:
            self.add_vertex(v2)
        self.adj_list[v1].append(v2)
        self.adj_list[v2].append(v1)

    def dfs(self, start):
        visited = set()      
        stack = [start]      
        order = []          

        while stack:
            v = stack.pop()
            if v not in visited:
                visited.add(v)
                order.append(v)
                for neighbor in self.adj_list[v]:
                    if neighbor not in visited:
                        stack.append(neighbor)
        return order

    def __iter__(self):
        start = list(self.adj_list.keys())[0]
        return iter(self.dfs(start))
