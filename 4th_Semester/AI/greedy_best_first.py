'''
Program: Greedy Best First Search
'''

graph = {
    'S': {'A': 3, 'B': 2},
    'A': {'C': 4, 'D': 1},
    'B': {'E': 3, 'F': 1},
    'C': {},
    'D': {},
    'E': {'H': 5},
    'F': {'I': 2, 'G': 3},
    'G': {},
    'H': {},
    'I': {},
}

heuristic = {
    'S': 13,
    'A': 12,
    'B': 4,
    'C': 7,
    'D': 3,
    'E': 8,
    'F': 2,
    'G': 0,
    'H': 4,
    'I': 9,

}


def gbfs(graph, heuristic, start, goal):
    visited = set()
    queue = [(heuristic[start], [start])]
    while queue:
        (h, path) = queue.pop(0)
        current_node = path[-1]
        if current_node == goal:
            return path
        visited.add(current_node)
        for neighbor, distance in graph[current_node].items():
            if neighbor not in visited:
                new_path = path + [neighbor]
                queue.append((heuristic[neighbor], new_path))
        queue.sort()
    return None


print("Greedy best first search")
start = input("Enter the start node: ")
goal = input("Enter the goal node: ")

traversed_path = gbfs(graph, heuristic, start, goal)

if traversed_path:
    print(f"Goal node found: \n{traversed_path}\n")

else:
    print("Goal node not found\n")
