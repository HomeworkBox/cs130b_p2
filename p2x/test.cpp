//
//  test.cpp
//  p1
//
//  Created by Tyler Weimin Ouyang on 2/9/15.
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
	
	unsigned long long int *q = new unsigned long long int[n+1];
	int *marked = new int[n+1];
	for (int k=1; k<=n; k++) {
		marked[k] = k;
	}
	marked[1] =s;
	marked[s] =1;
	q[1] = 346120480;
	q[2] = 253285253;
	q[3] = (unsigned long long int)190751860;
	q[4] = 105585017;
	q[5] = 75820685;
	q[6] = (unsigned long long int)159685952;
	q[7] = (unsigned long long int)159685952;
	q[8] = (unsigned long long int)0;
	q[9] = (unsigned long long int)223283761;
	q[10] = (unsigned long long int)92351464;
	
	cout << tree2(q, marked, stations,10, 10) << endl;
	//cout << (unsigned long long int) 0-1 ;
	// Allocate memory for stations' coordinates

	
	
	
	return 0;
}