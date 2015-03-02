//
//  val2.cpp
//  p2x
//
//  Created by Tyler Weimin Ouyang on 2/28/15.
//  Copyright (c) 2015 Golden. All rights reserved.
//

#include "val.h"
using namespace std;

unsigned long long int val2(int i, int j, int m, Station *stations, int ***keyP, int ***keyQ, unsigned long long int ***results){
	if (results[i][j][m] < (unsigned long long int)0-1) {
		return results[i][j][m];
	}
	// Base 1
	if (i == j) return 0;
	// Base 2
	if (m == 0) return 0-1;
	// Base 3
	if (m == 1) {
		keyP[i][j][m] = j;
		keyQ[i][j][m] = 1;
		results[i][j][m] = dist(stations[i], stations[j]);
		return results[i][j][m];
	}
	unsigned long long int result = 0-1;
	for (int p=i+1; p<=j; p++) {
		for (int q=1; q<m; q++) {
			unsigned long long int tmp1 = val2(i, p, q, stations, keyP, keyQ, results);
			unsigned long long int tmp2 = val2(p, j, m-q, stations, keyP, keyQ, results);
			results[i][p][q] = tmp1;
			results[p][j][m-q] = tmp2;
			if (tmp1+tmp2 < result){
				result = tmp1+tmp2;
				keyP[i][j][m] = p;
				keyQ[i][j][m] = q;
			}
			
		}
	}
	return result;
}


