#pragma once

#include <bitset>
#include <codecvt>
#include "TagEdit.h"

class Frame
{
public:

	char header[10];
	int size;
	std::bitset<8> bitSize[4];
	char encoding[1];
	char* data;
	std::string id;
	std::bitset<8> flags[2];

	Frame(char fHeader[10], std::string id) 
	{
		strcpy(this->header, fHeader);
		this->id = id;
		if (id.compare("COMM") == 0)
			this->size = getFrameSize(fHeader) - 6;
		else
			this->size = getFrameSize(fHeader);
		data = new char[this->size];
		flags[0] = fHeader[8];
		flags[1] = fHeader[9];
	}

	Frame(std::string id)
	{
		this->id = id;
		encoding[0] = 3;
		flags[0] = 0;
		flags[1] = 0;
	}

	Frame(std::string id, std::string newData)
	{
		this->id = id;
		this->data = new char[newData.length() * sizeof(char)];
		strcpy(this->data, newData.c_str());
		if (id.compare("COMM") == 0)
			this->size = strlen(this->data) * sizeof(char) + 6;
		else
			this->size = strlen(this->data) * sizeof(char) + 2;
		encoding[0] = 3;
		flags[0] = 0;
		flags[1] = 0;

		std::bitset<32> fixedSize = this->size;
		int sPos = 0;
		for (int i = 0; i < 4; i++)
		{
			std::bitset<8> newBitset;
			for (int j = 0; j < 7; j++) {
				newBitset[j] = fixedSize[sPos++];
			}
			bitSize[3 - i] = newBitset;
		}
	}

	void setData(const char* toSet)
	{
		this->data = new char[strlen(toSet) * sizeof(char)];
		strcpy(this->data, toSet);
		this->size = strlen(toSet) * sizeof(char) + 2;
	}

	int getFrameSize(char header[10]) {
		for (int i = 4; i < 8; i++)
		{
			this->bitSize[i - 4] = header[i];
		}
		std::string size;
		for (int i = 0; i < 4; i++)
		{
			size += bitSize[i].to_string();
		}
		std::string fixedSize;
		for (int i = 0, j = 32; i < 32; ++i, j--) {
			if (j % 8 == 0)
				continue;
			fixedSize += size[i];
		}
		return binToDec(fixedSize, fixedSize.size());
	}

	int binToDec(std::string bin, int n) {
		int result = 0;
		for (int i = n; i >= 1; i--) {
			if (bin[n - i] == '1')
				result += pow(2, (i - 1));
		}
		return result;
	}

};

