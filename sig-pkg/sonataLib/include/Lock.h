/*******************************************************************************

 File:    Lock.h
 Project: OpenSonATA
 Authors: The OpenSonATA code is the result of many programmers
          over many years

 Copyright 2011 The SETI Institute

 OpenSonATA is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 OpenSonATA is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with OpenSonATA.  If not, see<http://www.gnu.org/licenses/>.
 
 Implementers of this code are requested to include the caption
 "Licensed through SETI" with a link to setiQuest.org.
 
 For alternate licensing arrangements, please contact
 The SETI Institute at www.seti.org or setiquest.org. 

*******************************************************************************/

//
// Lock class
//
// $Header: /home/cvs/nss/sonata-pkg/sonataLib/include/Lock.h,v 1.4 2008/11/18 23:18:59 kes Exp $
//
#ifndef _LockH
#define _LockH

#include <pthread.h>
#include <string>
#include "Sonata.h"
#include "Types.h"

using std::string;

namespace sonata_lib {

struct LockTiming {
	uint64_t locks;
	float maxWait;
	float wait;

	LockTiming(): locks(0), maxWait(0), wait(0) {}
};

class Lock {
public:
	Lock(string name_ = "Default", LockType type = RecursiveLock);
	~Lock();

	void lock();
	bool trylock();
	void unlock();

	void name(string& name_);

private:
//	int count;
//	int policy;
//	int priority;
//	dxLockType type;
	pthread_mutex_t mutex;
//	pthread_t owner;
	string mname;
	LockTiming timing;

	friend class Condition;

	// forbidden
	Lock(const Lock&);
	Lock& operator=(const Lock&);
};

}

#endif
