//
//  Header.h
//  p2
//
//  Created by Tyler Weimin Ouyang on 2/11/15.
//  Copyright (c) 2015 Tyler. All rights reserved.
//

#ifndef __p2_Header_h
#define __p2_Header_h
#include "station.h"
#include "heapA.h"
#include "val.h"

inline unsigned long long int dist(Station &a, Station &b){
	int dx = a._x - b._x;
	int dy = a._y - b._y;
	return dx*dx + dy*dy;
}

// ACSF
void acsf(Station* stations, int* stationsCoor, const int numberOfStations, int source);

// ACSet
void acset(Station* stations, const int numberOfStations, int source);
int closestToSet(Station *stations, int* marked, int i, int numberOfStations, int* unMarked);
void acsetForMO(Station* stations, const int numberOfStations, int startIndex, int endIndex, int *marked, int *unMarked, unsigned long long int *r);

// ACF
void acf(Station* stations, const int numberOfStations, int source);
void acfForDC(Station* stations, const int numberOfStations, int startIndex, int endIndex, int *marked, int *unMarked, unsigned long long int *r);

// DC
void dc(Station* stations, int* stationsCoor, const int numberOfStations, int source);

// My own
void mo(Station* stations, int* stationsCoor, const int numberOfStations, int source);

// DP with Recomputation
void dpR(Station* stations, const int numberOfStations, int k);

// DP without recomputation
void dpNonR(Station* stations, const int numberOfStations, int inK);

// DP Iterative
void dpIter(Station* stations, const int numberOfStations, int inK);

// Tree
unsigned long long int* tree(unsigned long long int *r, int *addressBook, Station *stations, int size, int n);
unsigned long long int tree2(unsigned long long int *r, int *addressBook, Station *stations, int size, int n);
#endif
