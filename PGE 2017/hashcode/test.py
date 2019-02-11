def Poutput(cars):
	for x in range(len(cars)):
		print("{0}".format(x + 1), end=' ')
		for y in range(len(cars[x].ride)):
			print("{0}".format(cars[x].ride[y].id), end=' ')
		print()
