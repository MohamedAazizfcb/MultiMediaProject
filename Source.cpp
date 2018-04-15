#include"AllIncludes.h"
#include"File.h"

int main()
{
	File* file = File::GetFileInstance();
	system("cls");
	{
		char infilename[400];
		char outfilename[400];
		cout << "Enter the INPUT file name OR press Enter if it is test (DONOT WRITE THE EXTENSION!): ";
		cin.getline(infilename, '\n');
		cout << "\nEnter the OUTPUT file name OR press Enter if it is new (DONOT WRITE THE EXTENSION!):  ";
		cin.getline(outfilename, '\n');
		system("cls");
		if (infilename[0] == '\0'  && outfilename[0] == '\0')
			file->CopyFile();
		else if (infilename[0] == '\0' && outfilename[0] != '\0')
			file->CopyFile("test", outfilename);
		else if (infilename[0] != '\0'  && outfilename[0] == '\0')
			file->CopyFile(infilename);
		else
			file->CopyFile(infilename, outfilename);
		
	}
	return 0;
}