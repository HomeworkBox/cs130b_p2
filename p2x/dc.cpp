//
//  dc.cpp
//  p2x
//
//  Created by Tyler Weimin Ouyang on 2/25/15.
//  Copyright (c) 2015 Golden. All rights reserved.
//

#include <iostream>
#include "station.h"
#include "Header.h"
#include "heapA.h"
using namespace std;

void dc(Station* stations, int* stationsCoor, const int numberOfStations, int source){
	
	heapA *stationHeap = new heapA(stationsCoor, numberOfStations, source);
	
	// r: transmission rate squared
	unsigned long long int *r = new unsigned long long int[numberOfStations + 1];
	// marked is an arrary of marked stations' index
	int *marked = new int[numberOfStations+1];
	int *unMarked = new int[numberOfStations+1];
	
	// Initialize marks
	for (int i=1; i <= numberOfStations; i++) {
		marked[i] = 0;
		unMarked[i] = 0;
		r[i] = 0;
	}
	marked[1] = source;
	unMarked[source] = 0;
	// 1st
	stationHeap->getMin();
	for (int i=2; i<=numberOfStations/4; i++) {
		unMarked[stationHeap->getMin()]=i;
	}
	acfForDC(stations, numberOfStations, 2, numberOfStations/4, marked, unMarked, r);
	
	// 2nd
	for (int i=numberOfStations/4 + 1; i<=(numberOfStations/4) * 2; i++) {
		unMarked[stationHeap->getMin()]=i;
	}
	acfForDC(stations, numberOfStations, numberOfStations/4 + 1, (numberOfStations/4) * 2, marked, unMarked, r);
	
	// 3rd
	for (int i=(numberOfStations/4) * 2 + 1; i<=(numberOfStations/4) * 3; i++) {
		unMarked[stationHeap->getMin()]=i;
	}
	acfForDC(stations, numberOfStations, (numberOfStations/4) * 2 + 1, (numberOfStations/4) * 3, marked, unMarked, r);
	
	// 4th
	for (int i=(numberOfStations/4) * 3 + 1; i<=numberOfStations; i++) {
		unMarked[stationHeap->getMin()]=i;
	}
	acfForDC(stations, numberOfStations, (numberOfStations/4) * 3 + 1, numberOfStations, marked, unMarked, r);
	
	
	// calculate the power
	unsigned long long int totalPower=0;
	for (int k=1; k<=numberOfStations; k++) {
		totalPower += r[k];
	}
	cout << totalPower << endl;
	for (int k=1; k<=numberOfStations; k++) {
		if (r[k] != 0)
			cout << k << " " << r[k] << " " << stations[k]._parentIndex << endl;
	}
	
	
	delete [] r;
	delete [] marked;
	delete [] unMarked;
	delete stationHeap;
}