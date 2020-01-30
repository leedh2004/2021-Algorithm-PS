import sys

def isBlock(y, x):
	 if y < 0 or x < 0 or y >= len(room) or x >= len(room[0]) or room[y][x] == -1:
	 	return True

	 return False

def spreadDust(y, x):
	move_y = [-1, 0, 1, 0]
	move_x = [0, 1, 0, -1]
	spreadAmount = room[y][x] // 5

	for i in range(4):
		new_y = y + move_y[i]
		new_x = x + move_x[i]

		if not isBlock(new_y, new_x):
			spreaded_dust_room[new_y][new_x] = spreaded_dust_room[new_y][new_x] + spreadAmount
			room[y][x] = room[y][x] - spreadAmount			

def totalDust_before_cleaner():
	for y in range(len(room)):
		for x in range(len(room[0])):
			room[y][x] = room[y][x] + spreaded_dust_room[y][x]

def step1():
	for y in range(len(room)):
		for x in range(len(room[0])):
			if room[y][x] == -1:
				continue
			spreadDust(y, x)
	
	totalDust_before_cleaner()

def findCleaner():
	for y in range(len(room)):
		for x in range(len(room[0])):
			if room[y][x] == -1:
				return [y, x]

def removeDust_upperCase():
	pos_cleaner = findCleaner()
	
	current_y = pos_cleaner[0] - 1
	current_x = pos_cleaner[1]
	new_y = current_y
	new_x = current_x
	
	while True:
		if current_y != 0 and current_x == pos_cleaner[1]:
			new_y = current_y - 1
		elif current_y == 0 and current_x != len(room[0]) - 1:
			new_x = current_x + 1
		elif current_x == len(room[0]) - 1 and current_y != pos_cleaner[0]:
			new_y = current_y + 1
		elif current_x != pos_cleaner[1]:
			new_x = current_x - 1
		
		room[current_y][current_x] = room[new_y][new_x]
		current_y = new_y
		current_x = new_x

		if new_y == pos_cleaner[0] and new_x == pos_cleaner[1]:
			room[pos_cleaner[0]][pos_cleaner[1] + 1] = 0
			break

def removeDust_lowCase():
	pos_cleaner = findCleaner()
	
	current_y = pos_cleaner[0] + 2
	current_x = pos_cleaner[1]
	new_y = current_y
	new_x = current_x
	
	while True:
		if current_y != len(room) - 1 and current_x == pos_cleaner[1]:
			new_y = current_y + 1
		elif current_y == len(room) - 1 and current_x != len(room[0]) - 1:
			new_x = current_x + 1
		elif current_x == len(room[0]) - 1 and current_y != pos_cleaner[0] + 1:
			new_y = current_y - 1
		elif current_x != pos_cleaner[1]:
			new_x = current_x - 1
		
		room[current_y][current_x] = room[new_y][new_x]
		current_y = new_y
		current_x = new_x

		if new_y == pos_cleaner[0] + 1 and new_x == pos_cleaner[1]:
			room[pos_cleaner[0] + 1][pos_cleaner[1] + 1] = 0
			break

def step2():
	removeDust_upperCase()
	removeDust_lowCase()
	
r, c, t = map(int, sys.stdin.readline().split())
room = list()

for _ in range(r):
	room.append(list(map(int, sys.stdin.readline().split())))

for _ in range(t):
	spreaded_dust_room = [[0 for x in range(c)] for y in range(r)]
	step1()
	step2()
	
total = 2
for y in range(r):
	total = total + sum(room[y])

print(total)