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




'''
    Next method:
    If you want to enter all the nodes and successor nodes manually, use this code:
'''
#
# sussList = {}  # This dictionary holds all the nodes with their successors and their corresponding heuristic value
# temp_key_list = []  # Holds key node whose successor is to be inputted
# initial_node = str(input("Input initial node: "))  # root node
# # holds heuristic value of root node
# initial_value = eval(input(f"Input {initial_node}'s heuristic value: "))
# # number of successor of root node
# numberNode = eval(
#     input(f"How many successor nodes in node '{initial_node}': "))
# temp_key_list.append(initial_node)


# # Function used to input all nodes with their successor and corresponding heuristic value
# def nodeInput(numberNode):
#     new_node = temp_key_list[0]
#     temp_key_list.pop(0)
#     new_list = []
#     for i in range(numberNode):
#         key_name = str(input(f"Enter {i+1}'th successor of {new_node}: "))
#         key_value = eval(input(f"Enter {key_name}'s heuristic value: "))
#         temp = [key_name, key_value]
#         new_list.append(temp)
#         sussList[new_node] = new_list
#         temp_key_list.append(key_name)
#     if len(temp_key_list) != 0:
#         new_node = temp_key_list[0]
#         new_numberNode = eval(
#             input(f"How many successor nodes in node {new_node}?: "))
#         nodeInput(new_numberNode)
#     else:
#         pass


# def sortList(new_list):  # Function to sort the selected list in ascending order
#     new_list.sort(key=lambda x: x[1])
#     return new_list


# # Function to find shortest path using heuristic value
# def hillClimbing_search(node, value):
#     new_list = list()
#     if node in sussList.keys():
#         new_list = sussList[node]
#         new_list = sortList(new_list)
#         if (value > new_list[0][1]):
#             value = new_list[0][1]
#             node = new_list[0][0]
#             hillClimbing_search(node, value)
#         if (value < new_list[0][1]):
#             print(
#                 f"ANSWER:\nFor given Data, the local maxima is at node '{node}' with heuristic value {value}")
#     else:
#         print(
#             f"ANSWER:\nFor given Data, the local maxima is at node '{node}' with heuristic value {value}")


# nodeInput(numberNode)
# print("The user input is as follows: \n", sussList)
# hillClimbing_search(initial_node, initial_value)

#