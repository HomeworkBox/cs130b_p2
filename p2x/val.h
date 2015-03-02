//
//  val.h
//  p2x
//
//  Created by Tyler Weimin Ouyang on 2/28/15.
//  Copyright (c) 2015 Golden. All rights reserved.
//

#ifndef __p2x__val__
#define __p2x__val__

#include <iostream>
#include "Header.h"

unsigned long long int val(int i, int j, int m, Station *stations, int ***keyP, int ***keyQ);
void traceBack(int i, int j, int m, int ***keyP, int ***keyQ, Station *stations, unsigned long long int *r);
// without recomputation
unsigned long long int val2(int i, int j, int m, Station *stations, int ***keyP, int ***keyQ, unsigned long long int ***results);

// Iterative without recomputation
unsigned long long int val3(int i, int j, int m, Station *stations, int ***keyP, int ***keyQ, unsigned long long int ***results);

#endif /* defined(__p2x__val__) */
