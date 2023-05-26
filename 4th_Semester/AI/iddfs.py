'''
Program to implement iterative deepening depth first search
'''

graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F', 'G'],
    'D': [],
    'E': [],
    'F': [],
    'G': []
}

nodes_visited_level = {}
current_level = -1


def dfs(node, goal, d_limit, start, visited, path):
    global current_level

    if start == d_limit:
        current_level += 1

        nodes_visited_level[current_level] = []
    nodes_visited_level[current_level].append(node)

    if node == goal:
        return "FOUND", path + [node]
    elif d_limit == 0:
        return "NOT_FOUND", None
    else:
        visited.add(node)
        for child in graph[node]:
            if child not in visited:
                result, tv_path = dfs(
                    child, goal, d_limit - 1, start, visited, path + [node])
                if result == 'FOUND':
                    return "FOUND", tv_path
        return "NOT_FOUND", None


def iddfs(root, goal):
    d_limit = 0
    while True:
        visited = set()
        start = d_limit
        result, tv_path = dfs(root, goal, d_limit, start, visited, [])

        if result == "FOUND":
            return "Goal node found! Traversed path:" + '->'.join(tv_path)
        elif result == "NOT_FOUND":
            d_limit += 1


root = input("Enter the start node: ")
goal = input("Enter the goal node: ")
result = iddfs(root, goal)

for level, nodes in nodes_visited_level.items():
    print("Depth limit: "+str(level) + " Traversed path: ", end="")
    for node in nodes:
        print(node, end="")
        if node != nodes[-1]:
            print("->", end="")
    print()

print(result)
