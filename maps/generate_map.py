import random

def place_a_brick(chance):
   result = random.randint(1, chance)
   return result == 1 or result == 2

def brick(i, j):
    if (i == 1 or i == 11):
        if (j > 5 and j < 12) and place_a_brick(8):
            return 'k'
        else:
            return '*'
    else:
        if place_a_brick(3):
            return 'k'
        else:
            return '*'

def player_position(i, j):
    if (i == 1 and j == 0):
        return [True, "1"]
    if (i == 1 and j == 16):
        return [True, "B"]
    if (i == 11 and j == 0):
        return [True, "B"]
    if (i == 11 and j == 16):
        return [True, "2"]
    return [False]

def generate_map_with_actors():
    result = ""
    border = "xxxxxxxxxxxxxxxxxxx"
    result += border + "\n"
    for i in range(1, 12):
        result += "x"
        for j in range (0, 17):
            player = player_position(i, j)
            if (i % 2 == 0 and j > 0 and j % 2 == 1):
                result += "O"
            elif (player[0]):
                result += player[1]
            else:
                result += brick(i, j)
        result += 'x\n'
    result += border
    return result

def main():
    map_with_actors = generate_map_with_actors()
    return map_with_actors

print(main())