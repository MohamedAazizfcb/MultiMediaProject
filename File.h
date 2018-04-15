#pragma once
#include"AllIncludes.h"
#include<fstream>
class File
{
	ifstream* infile;
	ofstream* outfile;
	File();
	static File* instance;
public:
	static File* GetFileInstance();
	bool CopyFile(string infilename = "test", string outfilename = "new");
	~File();
};

