//
//  mo.cpp
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

void mo(Station* stations, int* stationsCoor, const int numberOfStations, int source){
	
	heapA *stationHeap = new heapA(stationsCoor, numberOfStations, source);
	Station *stationsCopy = new Station[numberOfStations + 1];
	
	unsigned long long int *pi = new unsigned long long int[numberOfStations + 1];
	for (int i = 1; i <= numberOfStations; i++) {
		pi[i] = stationHeap->getMin();
		stationsCopy[i] = stations[pi[i]];
	}
	
	// r: transmission rate squared
	unsigned long long int *r = new unsigned long long int[numberOfStations + 1];
	
	// marked is an arrary of marked stations' index
	int *marked = new int[numberOfStations+1];
	int *unMarked = new int[numberOfStations+1];
	
	// 1st
	// Initialize marks
	for (int i=1; i <= numberOfStations; i++) {
		marked[i] = 0;
		unMarked[i] = i;
		r[i] = 0;
	}
	marked[1] = 1;
	unMarked[1] = 0;
	
	acsetForMO(stationsCopy, numberOfStations/4, 2, marked, unMarked, r);
	
	// 2nd
	acsetForMO(stationsCopy, (numberOfStations/4) * 2, numberOfStations/4 + 1, marked, unMarked, r);
	
	// 3rd
	acsetForMO(stationsCopy, (numberOfStations/4) * 3, (numberOfStations/4) * 2 + 1, marked, unMarked, r);
	
	// 4th
	acsetForMO(stationsCopy, numberOfStations, (numberOfStations/4) * 3 + 1, marked, unMarked, r);
	
	
	// calculate the power
	unsigned long long int totalPower=0;
	for (int k=1; k<=numberOfStations; k++) {
		totalPower += r[k];
	}
	cout << totalPower << endl;
	for (int kk = 1; kk<=numberOfStations; kk++) {
		for (int k=1; k<=numberOfStations; k++) {
			if (r[k] != 0 && pi[k] == kk) {
				if (stationsCopy[k]._parentIndex == -1)
					cout << pi[k] << " " << r[k] << " " << -1 << endl;
				else
					cout << pi[k] << " " << r[k] << " " << pi[stationsCopy[k]._parentIndex] << endl;
			}
		}
	}
	
	
	delete [] r;
	delete [] pi;
	delete [] marked;
	delete [] unMarked;
	delete [] stationsCopy;
	delete stationHeap;
}