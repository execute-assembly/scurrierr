#include "bytes.hpp"
#include <iostream>



void bytes::Write4(BYTE* data, UINT val) {
	memcpy(data + index, &val, sizeof(val));
	this->index += 4;
}


void bytes::WriteBytes(BYTE* data, UINT length, BYTE* string) {
	memcpy(data + index, string, length);
	this->index += length;
}

UINT bytes::Read4(BYTE* data) {
	UINT val;
	memcpy(&val, data + this->index, sizeof(val));
	this->index += 4;

	return val;
}
void bytes::ReadBytes(BYTE* data, BYTE* outData, UINT Length) {
	memcpy(outData, data + this->index, Length);

	this->index += Length;

}


bytes* g_Bytes = NULL;