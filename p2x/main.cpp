//
//  main.cpp
//  p2
//
//  Created by Tyler Weimin Ouyang on 2/10/15.
//  Copyright (c) 2015 Tyler. All rights reserved.
//

#include <iostream>
#include "station.h"
#include "Header.h"

using namespace std;

int main(int argc, const char * argv[]) {
	int method, n, s;
	cin >> method >> n >> s;
	
	// Allocate memory for stations' coordinates
	int *stationsCoor = new int[n*2];
	for (int i = 0; i < n; i++) {
		cin >> stationsCoor[i*2] >> stationsCoor[i*2+1];
	}
	
	Station *stations = new Station[n+1];
	for (int i=1; i<=n; i++) {
		stations[i]._x = stationsCoor[i*2-2];
		stations[i]._y = stationsCoor[i*2-1];
		stations[i]._parentIndex = 0;
	}
	stations[s]._parentIndex = -1;
	switch (method) {
		case 1:
			acsf(stations, stationsCoor, n, s);
			break;
		case 2:
			acset(stations, n, s);
			break;
		case 3:
			acf(stations, n, s);
			break;
		case 4:
			dc(stations, stationsCoor, n, s);
			break;
		default:
			cout << "Invalid method!\n";
			return 0;
	}
	
	delete []stations;
	delete []stationsCoor;
	return 0;
}
