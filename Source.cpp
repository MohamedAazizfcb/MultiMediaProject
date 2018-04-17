#include"AllIncludes.h"
#include"File.h"
#include"Encoder.h"
#include "Decoder.h"
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ofstream out("binary.bin", ios::binary);
	//out.write("11111111", 111);
	//char a = 65;
	//cout << a << endl;
	string text, x;
	cin >> text;
	while (cin >> x)
		text += " " + x;
	Encoder encoder; Decoder decoder;
	encoder.constructHuffmanTree(text);
	decoder.startDecoding(encoder.getHuffmanTree().top(), encoder.getEncodedText());
	/*File* file = File::GetFileInstance();
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
	}*/

	return 0;
}