adj_list = {
    'S': [('A', 1), ('G', 10)],
    'A': [('B', 2), ('C', 1)],
    'B': [('D', 5)],
    'C': [('D', 3), ('G', 4)],
    'D': [('G', 2)],
    'G': []

}

heuristic = {
    'S': 5,
    'A': 3,
    'B': 4,
    'C': 2,
    'D': 6,
    'G': 0
}


def a_star(adj_list, heuristic, start_node, goal_node):
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


print("---- A* search ----")
start_node = input("Enter the start node: ")
goal_node = input("Enter the goal node: ")

a_star(adj_list, heuristic, start_node, goal_node)
