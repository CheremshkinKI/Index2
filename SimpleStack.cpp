#include "SimpleStack.h"

#include <iostream>
int TStack::GetNextIndex(int index)
{
	return ++index;
}

TStack::TStack(int Size) : TDataRoot(Size)
{
	TopIndex = -1;
}

string TStack::Get()
{
	TData tmp = "-1";
	if (pMem == NULL) SetRetCode(StackNoMemory);
	else {
		if (IsEmpty()) SetRetCode(StackEmpty);
		else {
			tmp = pMem[TopIndex--];
			DataCount--;
		}
	}
	return tmp;
}

void TStack::Print()
{
	for (int i = 0; i < DataCount; i++) {
		std::cout << pMem[i] << " ";
	}
	std::cout << std::endl;
}

bool TStack::IsValid()
{
	if (GetRedCode() != 0)
	{
		return false;
	}
	if (pMem == NULL)
	{
		return false;
	}
	if (IsEmpty())
	{
		return false;
	}
	if (IsFull())
	{
		return false;
	}
	if (MemDataSize < DataCount)
	{
		return false;
	}
	return true;
}

int TStack::GGiveCount()
{
	return DataCount;
}

void TStack::Put(const TData &Val)
{
	if (pMem == NULL) SetRetCode(StackNoMemory);
	else {
		if (IsFull()) SetRetCode(StackFull);
		else {
			TopIndex = GetNextIndex(TopIndex);
			pMem[TopIndex] = Val;
			DataCount++;

		}
	}
}
