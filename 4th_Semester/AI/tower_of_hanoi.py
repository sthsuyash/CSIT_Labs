# Python function to solve the tower of hanoi

def toh(n, source, destination, temp):
    if n == 1:
        print(f"Move disk 1 from {source} to {destination}")
        return
    toh(n - 1, source, temp, destination)
    print(f"Move disk {n} from {source} to {destination}")
    toh(n-1, temp, destination, source)


# Enter the number of rods
n = int(input("Enter the number of rods: "))
toh(n, 'Source', 'Destination', 'Temp')
