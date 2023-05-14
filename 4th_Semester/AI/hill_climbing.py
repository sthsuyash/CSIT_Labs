'''
Program to find local maxima using hill climbing search
'''

# This dictionary holds all the nodes with their successors and their corresponding heuristic value
adjList = {
    'A': [('B', 10), ('J', 8), ('F', 7)],
    'B': [('D', 4), ('C', 2)],
    'C': [('H', 0)],
    'E': [('I', 6)],
    'F': [('E', 5), ('G', 3)],
    'I': [('K', 0)],
    'J': [('K', 0)],
}

# root node
initial_node = str(input("Input initial node: ")).capitalize()
# holds heuristic value of root node
initial_value = eval(input(f"Input {initial_node}'s heuristic value: "))

# Function to sort the selected list in ascending order based on heuristic value


def sortList(new_list):
    new_list.sort(key=lambda x: x[1])
    return new_list


# Function to find shortest path using heuristic value
def hillClimbing_search(node, value):
    new_list = list()
    if node in adjList.keys():
        new_list = adjList[node]
        new_list = sortList(new_list)
        if (value > new_list[0][1]):
            value = new_list[0][1]
            node = new_list[0][0]
            hillClimbing_search(node, value)
        if (value < new_list[0][1]):
            print(
                f"\nLocal maxima at node: '{node}'\nHeuristic value: {value}")
    else:
        print(f"\nLocal maxima at node: '{node}'\nHeuristic value: {value}")


if __name__ == "__main__":
    hillClimbing_search(initial_node, initial_value)
