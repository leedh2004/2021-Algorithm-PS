get = input()
comp = "UCPC"
comp_i = 0

for j in get:
	if comp[comp_i] == j:
		comp_i += 1

	if comp_i == 4:
		break;

if comp_i == 4:
	print("I love UCPC")
else :
	print("I hate UCPC") 