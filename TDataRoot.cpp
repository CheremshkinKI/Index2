#include "TDataRoot.h"
using namespace std;
#include <iostream>
void TDataRoot::SetMem(void* pMem, int size)
{
	if (MemType == MEM_HOLDER) delete this->pMem;
	this->pMem = NULL;

	this->pMem = (TElem*)pMem;
	MemType = MEM_RENTER;
	MemDataSize = size;
}


TDataRoot::TDataRoot(int Size)
{
	DataCount = 0;
	MemDataSize = Size;
	if (Size <= 0)
	{
		pMem =NULL;
		MemType = MEM_RENTER;
	}
	else
	{
		pMem = new TElem[MemSize];
		MemType = MEM_HOLDER;
	}
}

TDataRoot::~TDataRoot()
{
	if (MemType == MEM_HOLDER)
	{
		delete pMem;
	}
	pMem = NULL;
}

int TDataRoot::GiveCount()
{
	return DataCount;
}

bool TDataRoot::IsEmpty()
{
	return DataCount==0;
}

bool TDataRoot::IsFull()
{
	return DataCount == MemDataSize;
}
