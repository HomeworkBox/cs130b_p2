//
//  acfForDC.cpp
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

void acfForDC(Station* stations, const int numberOfStations, int startIndex, int endIndex, int *marked, int *unMarked, unsigned long long int *r){
	
	// q: transmission rate squared
	unsigned long long int *q = new unsigned long long int[numberOfStations + 1];
	// p: sum of transmission rates squared
	unsigned long long int *p = new unsigned long long int[numberOfStations + 1];
	// t: array of transmission rate squared from tree
	unsigned long long int *t = new unsigned long long int;

	for (int i=1; i <= numberOfStations; i++) {
		p[i] = 0-1;
	}
	
	for (int i=startIndex; i <= endIndex; i++) {
		unsigned int* indexOfMinL = new unsigned int[numberOfStations+1];
		for (int kk = 1; kk <= numberOfStations; kk++) indexOfMinL[kk]=0-1;
		// For each unmarked station Oj do
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
				
				//cout << l << " to "<< j <<" "<< tmp << endl;
				q[l] = (q[l]>tmp ? q[l]:tmp);
				if (l==12 || l==16) cout << "l="<<l<<" -> j="<< j<<"; q[l]="<<q[l]<<" q[12]="<<q[12]<<endl;
				//tree
				unsigned long long int tmpP = tree2(q, marked, stations, i, numberOfStations);
				if (l==16) cout<<"after tree, q[12]=" << q[12]<<endl;
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
		if (j==5||j==23)
			cout << "-----l="<<l<<" -> j="<< j<<"; r[l]="<<r[l]<<" r[12]="<<r[12]<<endl;
		//tree
		t = tree(r, marked, stations, i, numberOfStations);
		for (int k=1; k<=i; k++) {
			int ll = marked[k];
			r[ll] = t[ll];
		}
		if (r[12]!=4056461) cout<<"r[12] is being changed j="<<j<<" l="<<l<<" r[12]=" <<r[12]<<endl;
		delete [] indexOfMinL;
	}
	// calculate the power
	unsigned long long int totalPower=0;
	for (int k=1; k<=numberOfStations; k++) {
		totalPower += r[k];
		if (unMarked[k]!=0) cout <<"unmared has non 0 !!!!!!!!!!!!!!"<<endl;
	}
	
	cout << endl << totalPower << endl;
		for (int k=1; k<=numberOfStations; k++) {
				if (stations[k]._parentIndex == -1)
					cout << k << " " << r[k] << " " << -1 << endl;
				else
					cout << k << " " << r[k] << " " << stations[k]._parentIndex << endl;
		
		
	}

	delete [] q;
	delete [] p;
	delete [] t;

}


