#ifndef CONCATENA_H_
#define CONCATENA_H_

#include "list.h"

enum ConcType {
	kCopy,
	kNoCopy
};

extern Item* Concatena(Item* i1, Item* i2, enum ConcType c);
#endif // !CONCATENA_H_
