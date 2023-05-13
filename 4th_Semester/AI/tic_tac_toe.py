# TODO retry if the position is already taken

import time
import os

board = [' ' for x in range(9)]
player = 1

''' Win Flags '''
Win = 1
Draw = -1
Running = 0
Stop = 1
###########################
Game = Running
Mark = 'X'


# This Function Draws Game Board
def DrawBoard():
    print(" %c | %c | %c " % (board[0], board[1], board[2]))
    print("___|___|___")
    print(" %c | %c | %c " % (board[3], board[4], board[5]))
    print("___|___|___")
    print(" %c | %c | %c " % (board[6], board[7], board[8]))
    print("   |   |   ")


# This Function Checks position is empty or not
def CheckPosition(x):
    if (board[x] == ' '):
        return True
    else:
        return False


# This Function Checks player has won or not
def CheckWin():
    global Game
    # Horizontal winning condition
    if (board[0] == board[1] and board[1] == board[2] and board[0] != ' '):
        Game = Win
    elif (board[3] == board[4] and board[4] == board[5] and board[3] != ' '):
        Game = Win
    elif (board[6] == board[7] and board[7] == board[8] and board[6] != ' '):
        Game = Win

    # Vertical Winning Condition
    elif (board[0] == board[3] and board[3] == board[6] and board[0] != ' '):
        Game = Win
    elif (board[1] == board[4] and board[4] == board[7] and board[1] != ' '):
        Game = Win
    elif (board[2] == board[5] and board[5] == board[8] and board[2] != ' '):
        Game = Win

    # Diagonal Winning Condition
    elif (board[0] == board[4] and board[4] == board[8] and board[4] != ' '):
        Game = Win
    elif (board[2] == board[4] and board[4] == board[6] and board[4] != ' '):
        Game = Win

    # Match Tie or Draw Condition
    elif (board[0] != ' ' and
          board[1] != ' ' and
          board[2] != ' ' and
          board[3] != ' ' and
          board[4] != ' ' and
          board[5] != ' ' and
          board[6] != ' ' and
          board[7] != ' ' and
          board[8] != ' '):
        Game = Draw
    else:
        Game = Running


print("Tic-Tac-Toe Game\n")
print("Player 1 [X] --- Player 2 [O]\n")
print()
print()
print("Please Wait...")
time.sleep(1)

while (Game == Running):
    os.system('cls')
    DrawBoard()
    if (player % 2 != 0):
        print("Player 1's chance")
        Mark = 'X'
    else:
        print("Player 2's chance")
        Mark = 'O'

    choice = int(
        input("Enter the position between [1-9] where you want to mark: "))
    if (CheckPosition(choice)):
        board[choice] = Mark
        player += 1
        CheckWin()

os.system('cls')
DrawBoard()
if (Game == Draw):
    print("Game Draw")
elif (Game == Win):
    player -= 1

if (player % 2 != 0):
    print("Player 1 Won")
else:
    print("Player 2 Won")
