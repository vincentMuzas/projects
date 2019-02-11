def	getDistance(car, posToGo)
	distance = abs(car.position[0] - posToGo[0]) + abs(car.position[1] - posToGo[1])
	return distance + car.freeze
end