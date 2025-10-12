#pragma once
#include "common.hpp"


class bytes {
	

public:
	INT index;
	void Write4(BYTE* data, UINT val);
	void WriteBytes(BYTE* data, UINT length, BYTE* string);
	UINT Read4(BYTE* data);
	void ReadBytes(BYTE* data, BYTE* outData, UINT Lengt);

};

extern bytes* g_Bytes;