/************************************************/
/* Application.cpp, (c) Rene Puchinger          */
/************************************************/

#include "Application.h"
#include <iostream>

Application::Application() {
	enc = NULL;  // encoder
	dec = NULL;  // decoder


	string inputFile, outputFile;
	cout << "Enter The name of the input file\n";
	cin >> inputFile;
	outputFile = inputFile;
	int pos = inputFile.find("tsv");
	if (pos != string::npos) {
		outputFile.replace(pos, 3, "ppm");   // 5 = length( $name )
	}
	fn_in = const_cast<char*>(inputFile.c_str());
	fn_out = const_cast<char*>(outputFile.c_str());
	enc = new ARI_encoder;
	dec = new ARI_decoder;
	state = ENCODE;
	this->run();
	inputFile = inputFile.substr(0, pos - 1);
	inputFile += "_compressed.tsv";
	state = DECODE;
	fn_in = const_cast<char*>(outputFile.c_str());
	fn_out = const_cast<char*>(inputFile.c_str());
	this->run();
}

void Application::run() {
	if (state == ENCODE) {
		FileInputStream* fin = new FileInputStream(fn_in);
		FileOutputStream* fout = new FileOutputStream(fn_out);
		SimpleBitOutputStream* bout = new SimpleBitOutputStream(fout);
		enc->encode(fin, bout);
		std::cout << "File compressed successfully." << std::endl;
		
	}
	else if (state == DECODE) {
		FileInputStream* fin = new FileInputStream(fn_in);
		SimpleBitInputStream* bin = new SimpleBitInputStream(fin);
		FileOutputStream* fout = new FileOutputStream(fn_out);
		dec->decode(bin, fout);
		std::cout << "File decompressed successfully." << std::endl;
		
	}
}

Application::~Application() {
	if (enc)
		delete enc;
	if (dec)
		delete dec;
}
