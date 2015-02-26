//
//  Header.h
//  p2
//
//  Created by Tyler Weimin Ouyang on 2/11/15.
//  Copyright (c) 2015 Tyler. All rights reserved.
//

#ifndef p2_Header_h
#define p2_Header_h

// ACSF
void acsf(Station* stations, int* stationsCoor, const int numberOfStations, int source);
inline unsigned long long int dist(Station &a, Station &b){
	int dx = a._x - b._x;
	int dy = a._y - b._y;
	return dx*dx + dy*dy;
}
// ACSet
void acset(Station* stations, int* stationsCoor, const int numberOfStations, int source);
int closestToSet(Station *stations, int* marked, int i, int numberOfStations, int* unMarked);

//ACF
void acf(Station* stations, int* stationsCoor, const int numberOfStations, int source);
//int* closestTwo(Station *stations, int* marked, int markedNumber,  int numberOfStations, int* unMarked);

// Tree
unsigned long long int* tree(unsigned long long int *r, int *addressBook, Station *stations, int size, int n);
unsigned long long int tree2(unsigned long long int *r, int *addressBook, Station *stations, int size, int n);
#endif
