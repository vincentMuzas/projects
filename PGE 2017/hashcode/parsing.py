#!/usr/bin/python3

import sys

#globals :

CAR_TAB = []
RIDE_TAB = []
NB_VEHICLES = 0
NB_RIDES = 0
BONUS_VAL = 0
NB_STEPS = 0

class ride:
    def __init__(self, pickup_location, arrival_location, start_time, arrival_time):
        self.pickup_location = pickup_location
        self.arrival_location = arrival_location
        self.start_time = start_time
        self.arrival_time = arrival_time
        self.id = 0

class car:
    def __init__(self, x, y, id):
        self.position = []
        self.position.append(int(x))
        self.position.append(int(y))
        self.id = int(id)
        self.nb_rides = 0
        self.ride = []
        self.freeze = 0

class infos:
    def __init__(self, x, y, nb_vehicles, nb_rides, bonus_val, steps):
        self.x = x      #nb rows
        self.y = y      #nb_columns
        self.nb_vehicles = nb_vehicles
        self.nb_rides = nb_rides
        self.bonus_val = bonus_val
        self.nb_steps = steps


def sort_by_start(ride1, ride2):
	if (ride1.start_time > ride2.start_time):
		return 1
	return 0

def	getDistance(car, posToGo):
	distance = abs(car.position[0] - posToGo[0]) + abs(car.position[1] - posToGo[1])
	return distance + car.freeze

#RIDE_TAB
#CAR_TAB

def cmp_to_key(mycmp):
    'Convert a cmp= function into a key= function'
    class K(object):
        def __init__(self, obj, *args):
            self.obj = obj
        def __lt__(self, other):
            return mycmp(self.obj, other.obj) < 0
        def __gt__(self, other):
            return mycmp(self.obj, other.obj) > 0
        def __eq__(self, other):
            return mycmp(self.obj, other.obj) == 0
        def __le__(self, other):
            return mycmp(self.obj, other.obj) <= 0  
        def __ge__(self, other):
            return mycmp(self.obj, other.obj) >= 0
        def __ne__(self, other):
            return mycmp(self.obj, other.obj) != 0
    return K


def	find_closest():
	closest_car = 0
	fewer_distance = getDistance(CAR_TAB[0], RIDE_TAB[0].arrival_location)

	for car in CAR_TAB:
		if (getDistance(car, RIDE_TAB[0]) < fewer_distance and car.freeze + getDistance(car, RIDE_TAB[0]) > NB_STEPS):
			closest_car = car
	return closest_car

def execute():
	RIDE_TAB.sort(key= cmp_to_key(sort_by_start))
	while (len(RIDE_TAB) != 0):
		closest = find_closest()
		if (closest == 0):
			return 0
		closest.position = RIDE_TAB[0].arrival_location
		closest.freeze += getDistance(RIDE_TAB[0], closest)
		RIDE_TAB.pop(0)

def parsefile(str):
	with open(str) as f:
		content = f.readlines()
	tab = [int(x) for x in content[0].split()]
	info = infos(tab[0], tab[1], tab[2], tab[3], tab[4], tab[5])
	NB_VEHICLES = info.nb_vehicles
	NB_RIDES = info.nb_rides
	BONUS_VAL = info.bonus_val
	NB_STEPS = info.bonus_val
	for i in range(0, info.nb_vehicles):
		CAR_TAB.append(car(0, 0, i))
	i = i + 1
	for i in range(0, info.nb_rides):
		tab = [int(x) for x in content[i + 1].split()]
		RIDE_TAB.append(ride(int(tab[0]), int(tab[1]), int(tab[2]), int(tab[3])))

def Poutput(cars):
	for x in range(len(cars)):
		print("{0}".format(x + 1), end=' ')
		for y in range(len(cars[x].ride)):
			print("{0}".format(cars[x].ride[y].id), end=' ')
		print()

if __name__ == "__main__":
    parsefile(sys.argv[1])
    execute()
    Poutput(CAR_TAB)
