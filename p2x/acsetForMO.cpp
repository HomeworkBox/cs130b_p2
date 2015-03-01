//
//  acsetForMO.cpp
//  p2
//
//  Created by Tyler Weimin Ouyang on 2/11/15.
//  Copyright (c) 2015 Tyler. All rights reserved.
//

#include <iostream>
#include "Header.h"

using namespace std;

void acsetForMO(Station* stations, const int numberOfStations, int startIndex, int endIndex, int *marked, int *unMarked, unsigned long long int *r){
	
	// q: transmission rate squared
	unsigned long long int *q = new unsigned long long int[numberOfStations + 1];
	// p: sum of transmission rates squared
	unsigned long long int *p = new unsigned long long int[numberOfStations + 1];
	// t: array of transmission rate squared from tree
	unsigned long long int *t = new unsigned long long int;

	for (int i=startIndex; i <= endIndex; i++) {
		int j = closestToSet(stations, marked, i, numberOfStations, unMarked);
		marked[i] = j;
		unMarked[j] = 0;
		r[j] = 0;
		//For each marked station Ol such that l != j do
		for (int k=1; k <= i; k++) {
			int l = marked[k];
			if (l !=j ) {
				for (int k = 1; k <= numberOfStations; k++) q[k] = r[k];
				unsigned long long int tmp = dist(stations[l], stations[j]);
				q[l] = (q[l]>tmp ? q[l]:tmp);
				//tree
				p[l] = tree2(q, marked, stations, i, numberOfStations);
			}
		}
		
		//Let l be the smallest integer such that l!= j, Ol is a marked station, and p[l] ≤ p[k] for every Ok that is marked;
		int l = marked[1];
		for (int k=2; k<=i; k++) {
			int tmpL = marked[k];
			if (tmpL != j){
				if (p[tmpL] < p[l]) l = tmpL;
				else if (p[tmpL] == p[l] && tmpL < l) l = tmpL;
			}
		}
		unsigned long long int tmp = dist(stations[l], stations[j]);
		r[l] = (r[l]>tmp ? r[l]:tmp);
		//tree
		t = tree(r, marked, stations, i, numberOfStations);
		for (int k=1; k<=i; k++) {
			int l = marked[k];
			r[l] = t[l];
		}
	}

	
	delete [] q;
	delete [] p;
	delete [] t;

}
