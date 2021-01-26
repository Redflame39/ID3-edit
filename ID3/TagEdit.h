#pragma once

#include <list>
#include <iostream>
#include <fstream>
#include <bitset>
#include <codecvt>
#include "Frame.h"

using namespace System;

class TagEdit
{
public:

	std::list<Frame> framesList;
	std::list<Frame> editedFrames;
	bool tagPresence;

	TagEdit()
	{

	}

	TagEdit(String^ pathC)
	{
		MarshalString(pathC, this->path);
		this->file.open(path, std::ios_base::binary | std::ios::in);
		if (file.is_open())
		{
			if (file.peek() == (int)'I')
			{
				this->file.read(header, 10);
				this->size = getTagSize(this->header);
				this->version = header[3];
				tagPresence = true;
			}
			else
				tagPresence = false;
		}
		file.close();
		readMedia();
	}

	void readFrames()
	{
		file.open(path, std::ios_base::binary | std::ios::in);
		if (file.is_open())
		{
			framesList.clear();
			file.seekg(10, std::ios_base::beg);
			int curr = file.tellg();
			while (curr != size)
			{
				char fHeader[10];
				file.read(fHeader, 10);
				/*if (strcmp(fHeader, "") == 0)
					break;*/
				std::string id;
				for (int i = 0; i < 4; i++)
					id += fHeader[i];
				if (!isID(id))
					break;
				Frame frame(fHeader, id);
				file.read(frame.encoding, 1);
				if (id.compare("COMM") == 0)
				{
					curr = file.tellg();
					file.seekg(curr + 4);
					file.read(frame.data, frame.size + 1);
				}
				else
					file.read(frame.data, frame.size - 1);
				curr = file.tellg();
				framesList.push_back(frame);
			}
			file.close();
		}
	}

	bool isID(std::string id)
	{
		return !id.compare("TIT2") || !id.compare("TPE1") || !id.compare("TPE2") || !id.compare("TALB") || !id.compare("TRCK") || !id.compare("TDRC") || !id.compare("TCON") || !id.compare("TCOM") || !id.compare("COMM");
	}

	void readMedia()
	{
		FILE* fs = fopen(path.c_str(), "rb");
		FILE* fd = fopen("C:/Users/User/source/repos/ID3/ID3/mediaInfo.txt", "wb");
		if (fs != NULL && fd != NULL)
		{
			if (tagPresence == false)
				fseek(fs, this->size, SEEK_SET);
			else
				fseek(fs, this->size+10, SEEK_SET);
			int ch;
			while ((ch = fgetc(fs)) != EOF) 
			{
				fputc(ch, fd);
			}
			fclose(fs);
			fclose(fd);
		}
		
	}

	std::string getData(std::string id) {
		for (Frame f : framesList) {
			if (f.id.compare(id) == 0 && f.data != NULL)
				return f.data;
		}
		return "";
	}

	void setData(System::String^ data, std::string id)
	{
		std::string s = "";
		MarshalString(data, s);
		for (Frame f : framesList) {
			if (f.id.compare(id) == 0)
				f.setData(s.c_str());
		}
	}

	void writeData() 
	{
		file.open(path, std::ios_base::binary | std::ios::out);
		file.clear();
		countSize();
		if (editedFrames.size() != 0)
		{
			writeHeader();
			writeFrames();
		}
		file.close();
		writeMedia();
	}

	void writeHeader() 
	{
		if (!tagPresence)
			this->version = 4;
		file << "ID3";
		file.write(reinterpret_cast<char*>(&this->version), sizeof(char));
		file.write("\x00", 1);
		file.write("\x00", 1);
		for (int i = 0; i < 4; i++)
		{
			char s = binToDec(bitSize[i].to_string(), bitSize[i].to_string().length());
			file.write(reinterpret_cast<char*>(&s), sizeof(char));
		}
	}

	void writeFrames()
	{
		for (Frame f : editedFrames)
		{
			file << f.id;
			for (int i = 0; i < 4; i++)
			{
				char s = binToDec(f.bitSize[i].to_string(), f.bitSize[i].to_string().length());
				file.write(reinterpret_cast<char*>(&s), sizeof(char));
			}
			file.write(reinterpret_cast<char*>(&f.flags[0]), sizeof(char));
			file.write(reinterpret_cast<char*>(&f.flags[1]), sizeof(char));

			file.write(reinterpret_cast<char*>(&f.encoding), sizeof(char));
			if (f.id.compare("COMM") == 0)
			{
				file << "eng";
				file.write("\x00", 1);
			}
			file << f.data;
			file.seekp(0, std::ios::end);
			file.write(reinterpret_cast<char*>("\x00"), sizeof(char));
		}
	}

	void writeMedia()
	{
		FILE* fs = fopen("C:/Users/User/source/repos/ID3/ID3/mediaInfo.txt", "rb");
		FILE* fd = fopen(path.c_str(), "ab");
		if (fs != NULL && fd != NULL)
		{
			fseek(fs, 0, SEEK_SET);
			fseek(fd, 0, SEEK_END);
			char ch;
			while (!feof(fs)) 
			{
				ch = fgetc(fs);
				fputc(ch, fd);
			}
			fclose(fs);
			fclose(fd);
		}
	}

	void countSize()
	{
		this->size = 0;
		for (Frame f : editedFrames)
		{
			this->size += 10;
			this->size += f.size;
		}

		std::bitset<32> fixedSize = this->size;
		int sPos = 0;
		for (int i = 0; i < 4; i++)
		{
			std::bitset<8> newBitset;
			for (int j = 0; j < 7; j++) {
				newBitset[j] = fixedSize[sPos++];
			}
			bitSize[3-i] = newBitset;
		}
	}

	std::list<Frame> checkFrames() 
	{
		std::list<Frame> toWrite;
		for (Frame f : framesList)
		{
			if (strcmp(f.data, "") != 0)
			{
				std::bitset<32> fixedSize = f.size;
				for (int i = 0; i < 4; i++)
				{
					std::bitset<8> newBitset;
					for (int j = 0; j < 7; j++) {
						newBitset[j] = fixedSize[i * 8 + j];
					}
					f.bitSize[3 - i] = newBitset;
				}
				toWrite.push_back(f);
			}
		}
		return toWrite;
	}

	void addFrame(std::string id, String^ newData)
	{
		std::string newStr;
		MarshalString(newData, newStr);
		editedFrames.push_back(Frame(id, newStr.c_str()));
	}

	static int binToDec(std::string bin, int n) {
		int result = 0;
		for (int i = n; i >= 1; i--) {
			if (bin[n - i] == '1')
				result += pow(2, (i - 1));
		}
		return result;
	}

	static void MarshalString(String^ s, std::string& os);

	static void MarshalWString(String^ s, std::wstring& os);

	static std::string getPath();

	static void setPath(String^ p);

	static bool checkValidInput(System::String^ input, std::string id);

private:

	static std::string path;
	std::fstream file;
	char header[10];
	size_t size;
	std::bitset<8> bitSize[4];
	char version;

	int getTagSize(char header[10]) 
	{
		for (int i = 6; i < 10; i++) 
		{
			this->bitSize[i - 6] = this->header[i];
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

};

std::string TagEdit::path = "";

std::string TagEdit::getPath()
{
	return path;
}

void TagEdit::setPath(String^ p)
{
	TagEdit::MarshalString(p, path);
}

void TagEdit::MarshalString(String^ s, std::string& os) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}


bool TagEdit::checkValidInput(System::String^ input, std::string id)
{
	std::string editedInput;
	TagEdit::MarshalString(input, editedInput);
	const char* inArray = editedInput.c_str();
	if (id.compare("TRCK") == 0 || id.compare("TDRC") == 0)
	{
		for (int i = 0; i < strlen(inArray); i++)
		{
			if (inArray[i] < 48 || inArray[i] > 57)
				return false;
		}
	}
	else
		for (int i = 0; i < strlen(inArray); i++)
		{
			if (inArray[i] < 32 || inArray[i] > 127)
				return false;
		}	
	return true;
}


