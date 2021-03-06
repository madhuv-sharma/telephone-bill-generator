from math import *
import csv


def dist(lat1, lon1, lat2, lon2):
	lat1, lon1, lat2, lon2 =  map(radians, [lat1, lon1, lat2, lon2])
	c = 2 * asin(sqrt(sin((lat2-lat1)/2)**2 + cos(lat1) * cos(lat2) * sin((lon2-lon1)/2)**2)) 
	r = 6371.137	#Radius of Earth at equator in kilometers
	return c * r


def main():
	x, y = 0, 0 # Set the coordinates of the Telephone Booth
	with open("cities_data.csv", "r") as infile, open("output_cities.csv", "w", newline="") as outfile:
		csv_reader = csv.reader(infile, delimiter = ',')
		csv_writer = csv.writer(outfile, delimiter = ',')
		l = 0
		for row in csv_reader :
			if l != 0 :
				row[4] = dist(float(x), float(y), float(row[2]), float(row[3]))
			csv_writer.writerow(row)
			l += 1


if __name__ == '__main__':
	main()