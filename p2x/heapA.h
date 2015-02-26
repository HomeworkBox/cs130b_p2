//
//  heapA.h
//  p2
//
//  Created by Tyler Weimin Ouyang on 2/8/15.
//  Copyright (c) 2015 Tyler. All rights reserved.
//

#ifndef __p1__heapA__
#define __p1__heapA__

#include <stdio.h>
#include "station.h"

class heapA{
private:
	int currentSize;
	StationForHeap *stationHeap;
public:
	heapA(const int* stationsCoor, const int size, int source);
	~heapA();
	void percolateDown(int index);
	int getMin();
};
#endif /* defined(__p1__heapA__) */
