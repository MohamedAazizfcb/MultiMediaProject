#include "File.h"


File* File::instance = NULL;
File::File()
{
	infile = NULL;
	outfile = NULL;
}

File* File::GetFileInstance()
{
	if (instance == NULL)
		instance = new File();
	return instance;
}
bool File::CopyFile(string infilename, string outfilename)
{
	infilename += ".txt";
	outfilename += ".txt";
	try {
		infile = new ifstream(infilename, ifstream::binary);
		outfile = new ofstream(outfilename, ifstream::binary);
		infile->seekg(0, infile->end);
		long size = infile->tellg();
		infile->seekg(0);
		char* buffer = new char[size];
		infile->read(buffer, size);
		outfile->write(buffer, size);
		delete[] buffer;
		outfile->close();
		infile->close();
		return true;
	}
	catch (exception e)
	{
		cout << "Error : Can not copy this file!\n";
		return false;
	}

}

File::~File()
{
	if (infile != NULL)
	{
		delete infile;
		infile = NULL;
	}
	if (outfile != NULL)
	{
		delete outfile;
		outfile = NULL;
	}
}
