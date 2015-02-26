//
//  tree.cpp
//  p2
//
//  Created by Tyler Weimin Ouyang on 2/11/15.
//  Copyright (c) 2015 Tyler. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include "station.h"
#include "Header.h"

// tree1 returns the total power

unsigned long long int* tree(unsigned long long int *r, int *addressBook, Station *stations, int size, int n){
	unsigned long long int *t = new unsigned long long int[n+1];
	
	int *unMarked = new int[size+1];
	int *Q = new int[size+1];
	int head = 1, tail = 1;
	
	// initailize unmarked
	for (int i = 1; i<= size; i++) {
		unMarked[i] = addressBook[i];
	}
	for (int i = 1; i<= n; i++) {
		t[i] = 0;
	}
	
	// add source to Q, and mark it
	Q[1] = unMarked[1];
	unMarked[1] = 0;
	
	// while Q is not empty do
	while (head <= tail) {
		int i = Q[head];
		unsigned int *L = new unsigned int[size+1]; // at most size unmarked stations within ri
		unsigned int *indexInUnmarked = new unsigned int[size+1];
		head ++;
		// build L
		int sizeOfL = 0;
		for (int k=2; k <= size; k++) {
			if ( unMarked[k] != 0 && unMarked[k] != i ) { //the set of all unmarked stations in S
				if (dist(stations[i], stations[unMarked[k]]) <= r[i] ) {
					L[++sizeOfL] = unMarked[k]; // found an element for L
					indexInUnmarked[sizeOfL] = k;
				}
			}
		}

		L[0] = 0-1;
		// while L is not empty do
		for (int k = 1; k <= sizeOfL; k++) {
			unsigned int j = 0;
			for (int kk = 1; kk <= sizeOfL; kk++) {
				if (L[kk]!= 0 && L[kk] < L[j]) j =kk;
			}
			if (j==0) printf("attention!!!\n"); //??
			
			stations[L[j]]._parentIndex = i;
			unsigned long long int distance = dist(stations[i], stations[L[j]]);
			if (distance > t[i]) t[i] = distance; // update t[i]
			unMarked[indexInUnmarked[j]] = 0; //mark station Oj
			Q[++tail] = L[j]; // add j to Q
			L[j] = 0; // delete j form L
		}
		delete []L;
		delete []indexInUnmarked;
	}

	delete []unMarked;
	delete []Q;
	return t;
}
unsigned long long int tree2(unsigned long long int *r, int *addressBook, Station *stations, int size, int n) {
	unsigned long long int *t = tree(r,  addressBook,  stations,  size, n);
	// calculate the power
	unsigned long long int result=0;
	for (int k=1; k <= size; k++) {
		result += t[addressBook[k]];
	}
	delete [] t;
//	std::cout<< "total is" << result<<"...."<<std::endl;
	return result;
}