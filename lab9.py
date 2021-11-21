import random

def SSTF(requests, initialPos):
    localRequests = list(requests)

    position = initialPos
    movement = 0 

    while localRequests:
        closest = abs(position - localRequests[0])
        closestIndex = 0 
        for x in range(1, len(localRequests)):
            if abs(position - localRequests[x]) < closest:
                closest = abs(position - localRequests[x])
                closestIndex = x 
        movement += abs(position - localRequests[closestIndex])
        position = localRequests[closestIndex]
        # print(str(position))
        localRequests.remove(position)
    return movement 

def FCFS(requests, initialPos):
    position = initialPos
    movement = 0 

    for x in range(len(requests)):
        movement += abs(position - requests[x])
        position = requests[x]
        # print(str(position))
    return movement

def SCAN(requests, initialPos):
    direction = RIGHT 
    localRequests = list(requests)
    position = initialPos
    movement = 0 
    while localRequests:
        if position in localRequests:
            # print(str(position))
            localRequests.remove(position)
            
            if not localRequests:
                break 
        if direction == LEFT and position > LOWER_CYLINDER:
            position -= 1
        if direction == RIGHT and position < UPPER_CYLINDER:
            position += 1 
        movement += 1 

        if position == 0:
            direction = RIGHT 
        if position == UPPER_CYLINDER:
            direction = LEFT
    return movement

def C_SCAN(requests, initialPos):
    localRequests = list(requests)
    position = initialPos
    movement = 0 

    while localRequests:
        if position in localRequests:
            # print(str(position))
            localRequests.remove(position)

            if not localRequests:
                break 
        movement += 1 
        position += 1
        if position == UPPER_CYLINDER:
            position = 0 
            movement += UPPER_CYLINDER
    return movement

LEFT = "LEFT" 
RIGHT = "RIGHT"

def LOOK(requests, initialPos):
    direction = RIGHT
    localRequests = list(requests)
    localRequests.sort()
    position = initialPos
    movement = 0 

    while localRequests:
        if position <= localRequests[0]: 
            direction = RIGHT 
        if position >= localRequests[-1]:
            direction = LEFT 
        if position in localRequests:
            # print(str(position))
            localRequests.remove(position)
            
            if not localRequests:
                break 
        if direction == LEFT and position > LOWER_CYLINDER:
            position -= 1 
        if direction == RIGHT and position < UPPER_CYLINDER:
            position += 1
            movement += 1
    return movement

def C_LOOK(requests, initialPos):
    localRequests = list(requests)
    localRequests.sort()
    position = initialPos
    movement = 0

    while localRequests:
        if position in localRequests:
            # print(str(position))
            localRequests.remove(position)

            if not localRequests:
                break 
        if position > localRequests[-1]:
            movement  += abs(position - localRequests[0])
            position = localRequests[0]
        else:
            movement += 1
            position += 1
    return movement

LOWER_CYLINDER = 0 
UPPER_CYLINDER = 4999

if __name__ == "__main__":
    requests = []
    # REQUESTS = 1000
    for i in range(1000):
        number = random.randint(1, 5000) % 5000 
        requests.append(number)

    print("Tolgoin ehnii bairlaliig oruulna uu?")
    initialPos = int(input())

    print("FCFS = " + str(FCFS(requests, initialPos)))
    print("SSTF = " + str(SSTF(requests, initialPos)))
    print("SCAN = " + str(SCAN(requests, initialPos)))
    print("C-SCAN = " + str(C_SCAN(requests, initialPos)))
    print("LOOK = " + str(LOOK(requests, initialPos)))
    print("C-LOOK = " + str(C_LOOK(requests, initialPos)))

