# Defining the graph nodes in dict with given costs to traverse
adj_list = {
    's': [('a', 1), ('g', 10)],
    'a': [('b', 2), ('c', 1)],
    'b': [('d', 5)],
    'c': [('d', 3), ('g', 4)],
    'd': [('g', 2)],
    'g': []
}

# Defining heuristic values for each nodes
heuristic = {
    's': 5,
    'a': 3,
    'b': 4,
    'c': 2,
    'd': 6,
    'g': 0
}

# A Star Search Algorithm
def astar_search(adj_list, heuristic, start_node, goal_node):
    open_list = set([start_node])
    closed_list = set([])
    g = {}
    g[start_node] = 0
    parents = {}
    parents[start_node] = start_node

    def get_neighbors(node):
        return adj_list[node]

    def h(node):
        return heuristic[node]

    while len(open_list) > 0:
        n = None
        for v in open_list:
            if n == None or g[v] + h(v) < g[n] + h(n):
                n = v

        if n == None:
            print('Path does not exist!')
            return None
        if n == goal_node:
            reconst_path = []
            while parents[n] != n:
                reconst_path.append(n)
                n = parents[n]
            reconst_path.append(start_node)
            reconst_path.reverse()

            print('Path found: {}'.format(reconst_path))
            return reconst_path

        for (m, weight) in get_neighbors(n):
            if m not in open_list and m not in closed_list:
                open_list.add(m)
                parents[m] = n
                g[m] = g[n] + weight
            else:
                if g[m] > g[n] + weight:
                    g[m] = g[n] + weight
                    parents[m] = n
                    if m in closed_list:
                        closed_list.remove(m)
                        open_list.add(m)
        open_list.remove(n)
        closed_list.add(n)

    print('Path does not exist!')
    return None


start_node = input("Enter the start node: ")
goal_node = input("Enter the goal node: ")

astar_search(adj_list, heuristic, start_node, goal_node)
