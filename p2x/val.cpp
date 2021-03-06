//
//  val.cpp
//  p2x
//
//  Created by Tyler Weimin Ouyang on 2/28/15.
//  Copyright (c) 2015 Golden. All rights reserved.
//

#include "val.h"
using namespace std;

unsigned long long int val(int i, int j, int m, Station *stations, int ***keyP, int ***keyQ){
	// Base 1
	if (i == j) return 0;
	// Base 2
	if (m == 0) return 0-1;
	// Base 3
	if (m == 1) {
		keyP[i][j][m] = j;
		keyQ[i][j][m] = 1;
		return dist(stations[i], stations[j]);
	}
	unsigned long long int result = 0-1;
	for (int p=i+1; p<=j; p++) {
		for (int q=1; q<m; q++) {
			unsigned long long int tmp = val(i, p, q, stations, keyP, keyQ) + val(p, j, m-q, stations, keyP, keyQ);
			if (tmp < result){
				result = tmp;
				keyP[i][j][m] = p;
				keyQ[i][j][m] = q;
			}
		}
	}
	return result;
}

void traceBack(int i, int j, int m, int ***keyP, int ***keyQ, Station *stations, unsigned long long int *r){
	if (i >=j || i == keyP[i][j][m] ) return;
	if (j == keyP[i][j][m]) {
		stations[j]._parentIndex = i;
		unsigned long long int tmp = dist(stations[i], stations[j]);
		r[i] = (r[i]>tmp ? r[i]:tmp);
		return;
	}
	traceBack(i, keyP[i][j][m], keyQ[i][j][m], keyP, keyQ, stations, r);
	traceBack(keyP[i][j][m], j, m-keyQ[i][j][m], keyP, keyQ, stations, r);
	
}