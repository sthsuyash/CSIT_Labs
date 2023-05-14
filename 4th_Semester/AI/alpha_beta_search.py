tree = [
    [[5, 1, 2], [8, -8, -9]],
    [[9, 4, 5], [-3, 4, 3]]
]  # tree to search
root = 0  # root depth
pruned = 0  # times pruned

# function to search tree


def children(branch, depth, alpha, beta):
    global root  # global root depth to compare with current depth
    global pruned  # global times pruned to count times pruned
    i = 0  # index of child
    for child in branch:
        if type(child) is list:  # if child is a list, call children function recursively
            (nalpha, nbeta) = children(child, depth + 1, alpha, beta)
            if depth % 2 == 1:
                beta = min(beta, nalpha)
            else:
                alpha = max(alpha, nbeta)
            branch[i] = nalpha if depth % 2 == 0 else nbeta
            i += 1
        else:
            if depth % 2 == 0 and alpha < child:
                alpha = child
            if depth % 2 == 1 and beta > child:
                beta = child
            if alpha >= beta:
                pruned += 1
                break
    return (alpha, beta)

# function to call search


def alphabeta(branch=tree, depth=root, alpha=-15, beta=15):
    global pruned

    (alpha, beta) = children(branch, depth, alpha, beta)

    if depth == root:
        best_move = max(branch) if depth % 2 == 0 else min(branch)
        print("(alpha, beta): ", alpha, beta)
        print("Result: ", best_move)
        print("Times pruned: ", pruned)

    return (alpha, beta, branch, pruned)


if __name__ == "__main__":
    alphabeta()
