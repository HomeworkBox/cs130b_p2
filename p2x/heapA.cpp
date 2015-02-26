//
//  heapA.cpp
//  p2
//
//  Created by Tyler Weimin Ouyang on 2/8/15.
//  Copyright (c) 2015 Tyler. All rights reserved.
//

#include "heapA.h"

heapA::heapA(const int* stationsCoor, const int size, int source){
	
	this->stationHeap = new StationForHeap[size+1];
	this->currentSize = size;
	int sourceX = stationsCoor[source*2-2];
	int sourceY = stationsCoor[source*2-1];
	
	for (int i = 1; i <= size; i++) {
		int x = stationsCoor[i*2-2] - sourceX;
		int y = stationsCoor[i*2-1] - sourceY;
		stationHeap[i]._distToSourceSquared = x*x + y*y;
		stationHeap[i]._index = i;
	}
	
	// Heapify
	for (int i=size/2; i>=1; i--) {
		percolateDown(i);
	}
}

heapA::~heapA(){
	delete []stationHeap;
}

int heapA::getMin(){
	// deleteMin of heap
	int returnIndex = stationHeap[1]._index;
	stationHeap[1] = stationHeap[currentSize];
	currentSize--;
	percolateDown(1);
	return returnIndex;
}
// ?? maybe iniline
void heapA::percolateDown(int index){
	
	int childIndex;
	StationForHeap tmp = stationHeap[index];
	
	for (; index*2 <= currentSize; index = childIndex) {
		childIndex = index*2;
		if ( childIndex != currentSize && stationHeap[childIndex+1] < stationHeap[childIndex])
			childIndex++;
		if (stationHeap[childIndex]<tmp)
			stationHeap[index]=stationHeap[childIndex];
		else
			break;
	}
	stationHeap[index]=tmp;
}