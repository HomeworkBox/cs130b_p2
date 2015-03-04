//
//  val3.cpp
//  p2x
//
//  Created by Tyler Weimin Ouyang on 2/28/15.
//  Copyright (c) 2015 Golden. All rights reserved.
//

#include "val.h"
using namespace std;

unsigned long long int val3(int i, int j, int m, Station *stations, int ***keyP, int ***keyQ, unsigned long long int ***results){
	
	// for all distances
	for (int d = 1; d <= j-1; d++){
		// for all starting points
		for (int s = 1; s <= j - d; s++){
			// Direct connection
			unsigned long long int distance = dist(stations[s], stations[s+d]);
			for (int aM = 1; aM <= m; aM++){
				results[s][s+d][aM] = distance;
				keyP[s][s+d][aM] = s+d;
				keyQ[s][s+d][aM] = 1;
			}
			// must via transmitter s+w
			for (int w = 1; w < d; w++) {
				// for all numbers of segments
				for (int e = 2; e <= m; e++){
					keyQ[s][s+d][e] = 1;
					// for all numbers of segments on left, Q
					for (int l = 1; l < e; l++) {
						unsigned long long int tmp = results[s][s+w][l] + results[s+w][s+d][e-l];
						if (results[s][s+d][e] > tmp){
							results[s][s+d][e] = tmp;
							keyP[s][s+d][e] = s+w;
							keyQ[s][s+d][e] = l;
						}
					}
				}
			}
		}
	}
	return results[i][j][m];
}


