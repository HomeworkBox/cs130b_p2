//
//  acsf.cpp
//  p2
//
//  Created by Tyler Weimin Ouyang on 2/11/15.
//  Copyright (c) 2015 Tyler. All rights reserved.
//

#include <iostream>
#include "Header.h"
using namespace std;

void acsf(Station* stations, int* stationsCoor, const int numberOfStations, int source){
	
	heapA *stationHeap = new heapA(stationsCoor, numberOfStations, source);
	
	// r & q: transmission rate squared
	unsigned long long int *r = new unsigned long long int[numberOfStations + 1];
	unsigned long long int *q = new unsigned long long int[numberOfStations + 1];
	// p: sum of transmission rates squared
	unsigned long long int *p = new unsigned long long int[numberOfStations + 1];
	// t: array of transmission rate squared from tree
	unsigned long long int *t = new unsigned long long int;
	// marked is an arrary of marked stations' index
	int *marked = new int[numberOfStations+1];
	
	for (int i=1; i <= numberOfStations; i++) {
		r[i] = 0;
		marked[i] = 0;
	}
	marked[1] = source;
	stationHeap->getMin();
	for (int i=2; i <= numberOfStations; i++) {
		int j =stationHeap->getMin();
		marked[i] = j;
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
//		for (int k=1; k<=i; k++){
//			cout << "p" << k<< " is " << p[k]<< " r" << k<< " is " << r[k]<<endl;
//		}
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
//	for (int k=1; k<=numberOfStations; k++) {
//		cout << "p" << k<< " is " << p[k]<< endl;
//		cout << "r" << k<< " is " << r[k]<< endl;
//		cout << "q" << k<< " is " << q[k]<<endl;
//		cout << "t" << k<< " is " << t[k]<< endl;
//		cout << "marked" << k<< " is " << marked[k]<<endl;
//	}
	delete [] r;
	delete [] q;
	delete [] p;
	delete [] t;
	delete stationHeap;
	delete [] marked;
}