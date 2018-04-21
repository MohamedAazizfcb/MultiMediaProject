#include "AllIncludes.h"


size_t GetSizeOfFile(const wstring & path)
{
	struct _stat fileinfo;
	_wstat(path.c_str(), &fileinfo);
	return fileinfo.st_size;
}

wstring LoadUtf8FileToString(const wstring & filename)
{

	std::wstring buffer;            // stores file contents
	FILE* f = _wfopen(filename.c_str(), L"rtS, ccs=UTF-8");
	// Failed to open file
	if (f == NULL)
	{
		// ...handle some error...
		return buffer;
	}
	size_t filesize = GetSizeOfFile(filename);
	// Read entire file contents in to memory
	if (filesize > 0)
	{
		buffer.resize(filesize);
		size_t wchars_read = fread(&(buffer.front()), sizeof(wchar_t), filesize, f);
		buffer.resize(wchars_read);
		buffer.shrink_to_fit();
	}
	fclose(f);
	fflush(f);
	return buffer;
}
