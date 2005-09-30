#pragma once

#include <windows.h>
#include <tchar.h>
#include "imm.h"

class CandList
{
public:
	CandList(void);
	~CandList(void);
	void setTotalCount(int c){	cl.dwCount = c;	}
	int getTotalCount(){ return cl.dwCount; }
	void setPageSize(int s){ cl.dwPageSize = s; }
	int getPageSize(){ return cl.dwPageSize; }
	void setPageStart(int i){ cl.dwPageStart = i; }
	int getPageStart(){ return cl.dwPageStart; }
	void setCand(int i, LPCTSTR cand);
	LPCTSTR getCand(int i){ return candStr[i]; }
protected:
    CANDIDATEINFO  ci;
    CANDIDATELIST  cl;
    DWORD offset[50];
#ifdef	UNICODE
    TCHAR candStr[80][16];
#else
    TCHAR candStr[80][32];
#endif
};
