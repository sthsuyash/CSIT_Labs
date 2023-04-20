from queue import PriorityQueue

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


def greedy_best_first_search(graph, heuristic, start, goal):
    explored = []
    queue = PriorityQueue()
    queue.put((heuristic[start], start))

    while queue:
        node = queue.get()[1]
        explored.append(node)

        if node == goal:
            return explored

        for neighbour in graph[node]:
            if neighbour not in explored:
                queue.put((heuristic[neighbour], neighbour))

    return "Goal not found"


start = input("Enter the start node: ")
goal = input("Enter the goal node: ")

print(greedy_best_first_search(graph, heuristic, start, goal))
