#pragma once
#define DataOK 0
#define DataErr -1
#include <string>
class TDataCom
{
protected:
	int RetCode;
	void SetRetCode(int ret) { RetCode = ret; }
public:
	TDataCom() :RetCode(DataOK) {};
	virtual ~TDataCom() {};
	int GetRedCode() 
	{
		int temp = RetCode;
		RetCode = DataOK;
		return temp;
	}
};