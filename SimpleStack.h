#pragma once
#include "TDataRoot.h"

class TStack : public TDataRoot {
protected:
	int TopIndex;
	int GetNextIndex(int index);
public:
	TStack(int Size = MemSize);
	void Put(const TData& Val);
	string Get();
	void Print();
	bool IsValid();
	int GGiveCount();

};
