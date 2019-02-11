def	find_closest()
	closest_car = None
	fewer_distance = getDistance(CAR_TAB[0], RIDE_TAB[0])

	for car in CAR_TAB
		if (getDistance(car, RIDE_TAB[0]) < fewer_distance and car.freeze + getDistance(car, RIDE_TAB[0]) > NB_STEPS)
			closest_car = car
	return closest_car