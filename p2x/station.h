//
//  station.h
//  p2
//
//  Created by Tyler Weimin Ouyang on 2/11/15.
//  Copyright (c) 2015 Tyler. All rights reserved.
//

#ifndef __p2__station__
#define __p2__station__

#include <stdio.h>

struct Station{
	int _x;
	int _y;
	int _parentIndex;
	
//	Station *parent;
};

struct StationForHeap{
	unsigned long long int _distToSourceSquared;
	int _index;
	
	bool operator< (const StationForHeap &a) const {
		if (_distToSourceSquared < a._distToSourceSquared)
			return true;
		else if (_distToSourceSquared > a._distToSourceSquared)
			return false;
		else
			return _index < a._index;
	}
};

#endif /* defined(__p2__station__) */
