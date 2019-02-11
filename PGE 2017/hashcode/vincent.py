#!/usr/bin/python3

import sys

class ride:
    def __init__(pickup_location, arrival_location, start_time, arrival_time):
        self.pickup_location = pickup_location
        self.arrival_location = arrival_location
        self.start_time = start_stime
        self.arrival_time = arrival_step
        self.id = 0

class cars:
    def __init__(ride, x, y):
        self.ride = ride
        self.position = []
        self.position.append(x)
        self.position.append(y)
        self.nb_rides = 0
        self.id = 0

class map:
    def __init__(x, y, nb_vehicles, nb_rides, bonus_val, steps):
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

def execute():
	RIDE_TAB.sort(sort_by_start)
	while len(RIDE_TAB) != 0:
		closest = find_closest()
		closest.position = RIDE_TAB[0].arrival_location
		closest.freeze += getDistance(RIDE_TAB[0], closest)
		RIDE_TAB.pop(0)


def parsefile(str):
    with open(str) as f:
        content = f.readlines()

    tab = map(int, content[0].split(" "))
    print (tab)



if __name__ == "__main__":
    parsefile(sys.argv[1])