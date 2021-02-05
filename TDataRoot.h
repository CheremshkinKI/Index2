#pragma once
#include <iostream>
#include "TDataCom.h"
#include <string>
using namespace std;
#define MemSize 30
#define StackEmpty -101
#define StackFull -102
#define StackNoMemory -103
typedef std::string TElem;
typedef TElem* PTElem;
typedef std::string TData;
enum TMemType {MEM_HOLDER,MEM_RENTER};
class TDataRoot :public TDataCom 
{
protected:
	PTElem pMem;
	int MemDataSize;
	int DataCount;
	TMemType MemType;
	void SetMem(void* pMem, int size);
public:
	TDataRoot(int Size = MemSize);
	~TDataRoot();
	int GiveCount();
	virtual bool IsEmpty();
	virtual bool IsFull();
	virtual void Put(const TData& val) = 0;
	virtual TData Get() = 0;
	virtual void Print() = 0;
	virtual bool IsValid() = 0;
};