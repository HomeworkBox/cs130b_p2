//
//  dpNonR.cpp
//  p2x
//
//  Created by Tyler Weimin Ouyang on 2/28/15.
//  Copyright (c) 2015 Golden. All rights reserved.
//

#include <iostream>
#include "Header.h"
using namespace std;

void dpNonR(Station* stations, const int numberOfStations, int inK){
	
	// New sequence
	int *p = new int[numberOfStations + 1];
	// Power
	unsigned long long int *r = new unsigned long long int[numberOfStations+1];
	// keys
	int ***keyP = new int**[numberOfStations + 1];
	int ***keyQ = new int**[numberOfStations + 1];
	unsigned long long int ***results = new unsigned long long int**[numberOfStations+1];
	for (int i=1; i<=numberOfStations; i++) {
		keyP[i] = new int*[numberOfStations+1];
		keyQ[i] = new int*[numberOfStations+1];
		results[i] = new unsigned long long int*[numberOfStations+1];
		for (int k=1; k<=numberOfStations; k++) {
			keyP[i][k] = new int[inK+1];
			keyQ[i][k] = new int[inK+1];
			results[i][k] = new unsigned long long int[inK+1];
			for (int j = 1; j <= inK; j++) {
				results[i][k][j] = 0-1;
			}
		}
	}
	
	// Bubble sort
	for (int i=1; i <= numberOfStations; i++){
		p[i] = i;
		r[i] = 0;
	}
	for (int i=1; i <= numberOfStations - 1; i++) {
		for (int j=1; j <= numberOfStations - i; j++){
			if (stations[j]._x > stations[j+1]._x) {
				//swap
				Station tmp = stations[j];
				stations[j] = stations[j+1];
				stations[j+1] = tmp;
				
				int tmpId = p[j];
				p[j] = p[j+1];
				p[j+1] = tmpId;
			}
		}
	}
	//for (int i=1; i<=numberOfStations;i++) cout<< p[i]<<" ";
	cout << val2(1, numberOfStations, inK, stations, keyP, keyQ, results) << endl;
	traceBack(1, numberOfStations, inK, keyP, keyQ, stations, r);
	/*
	 for (int i=1; i<=numberOfStations; i++){
		for (int j =i+1; j<=numberOfStations; j++) {
	 cout << endl<<"i=" <<i << ", j="<<j<<endl;
	 for (int k=1; k<=inK; k++)	cout << keyP[i][j][k] << " ";
	 
		}
		cout <<endl<<"-----------"<<endl;
	 }
	 */
	stations[1]._parentIndex = -1;
	for (int k=1; k<=numberOfStations; k++) {
		for (int j =1; j<=numberOfStations;j++){
			if (p[j]==k && r[j] != 0)
				cout << k << " " << r[j] << " " << (stations[j]._parentIndex == -1 ? -1:p[stations[j]._parentIndex]) << endl;
		}
	}
	
	delete [] p;
	delete [] r;
	for (int i=1; i<=numberOfStations; i++){
		for (int k=1; k<=numberOfStations; k++) {
			delete [] keyP[i][k];
			delete [] keyQ[i][k];
			delete [] results[i][k];
		}
		delete [] keyP[i];
		delete [] keyQ[i];
		delete [] results[i];
	}
	
	delete [] keyP;
	delete [] keyQ;
	delete [] results;
}

