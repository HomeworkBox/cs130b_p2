//
//  acf.cpp
//  p2
//
//  Created by Tyler Weimin Ouyang on 2/11/15.
//  Copyright (c) 2015 Tyler. All rights reserved.
//

#include <iostream>
#include "station.h"
#include "Header.h"
#include "heapA.h"
using namespace std;

void acf(Station* stations, int* stationsCoor, const int numberOfStations, int source){
	
	// r & q: transmission rate squared
	unsigned long long int *r = new unsigned long long int[numberOfStations + 1];
	unsigned long long int *q = new unsigned long long int[numberOfStations + 1];
	// p: sum of transmission rates squared
	unsigned long long int *p = new unsigned long long int[numberOfStations + 1];
	// t: array of transmission rate squared from tree
	unsigned long long int *t = new unsigned long long int;
	// marked is an arrary of marked stations' index
	int *marked = new int[numberOfStations+1];
	int *unMarked = new int[numberOfStations+1];
	for (int i = 1; i<=numberOfStations; i++) {
		unMarked[i] = i;
	}
	
	for (int i=1; i <= numberOfStations; i++) {
		r[i] = 0;
		marked[i] = 0;
		p[i] = 0-1;
	}
	marked[1] = source;
	unMarked[source] = 0;
	for (int i=2; i <= numberOfStations; i++) {
		unsigned int* indexOfMinL = new unsigned int[numberOfStations+1];
		for (int kk = 1; kk <= numberOfStations; kk++) indexOfMinL[kk]=0-1;
		for (int j = 1; j<=numberOfStations; j++) {
			if (unMarked[j]==0) continue;
			// mark Oj
			marked[i] = j;
			r[j] = 0;
			//For each marked station Ol do
			for (int k=1; k <= i-1; k++) {
				int l = marked[k];
				for (int kk = 1; kk <= numberOfStations; kk++) q[kk] = r[kk];
				unsigned long long int tmp = dist(stations[l], stations[j]);
				q[l] = (q[l]>tmp ? q[l]:tmp);
				//tree
				unsigned long long int tmpP = tree2(q, marked, stations, i, numberOfStations);
				if (tmpP < p[j]) {
					indexOfMinL[j] = l;
					p[j] = tmpP;
				}
				else if (tmpP == p[j] && indexOfMinL[j] > l){
					indexOfMinL[j] = l;
				}
			}
			// unmark Oj
			marked[i] = 0;
		}
		int j = 0, l=0;
		unsigned long long int minP = 0-1;
		for (int k=1; k <= numberOfStations; k++) {
			if (p[k] < minP) {
				j=k;
				l=indexOfMinL[j];
				minP = p[k];
			}
			p[k] = 0-1;
		}
		// mark Oj
		marked[i] = j;
		unMarked[j] = 0;
		unsigned long long int tmp = dist(stations[l], stations[j]);
		r[l] = (r[l]>tmp ? r[l]:tmp);

		//tree
		t = tree(r, marked, stations, i, numberOfStations);
		for (int k=1; k<=i; k++) {
			int ll = marked[k];
			r[ll] = t[ll];
		}

		delete [] indexOfMinL;
	}
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
	delete [] q;
	delete [] p;
	delete [] t;
	delete [] marked;
	delete [] unMarked;
}
