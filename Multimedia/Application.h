/************************************************/
/* Application.h, (c) Rene Puchinger            */
/*                                              */
/* sample artihmetic compression program        */
/************************************************/

#ifndef APPLICATION_H
#define APPLICATION_H
#include "SimpleBitIOStream.h"
#include "FileIOStream.h"
#include "ARI.h"
#include<string>

using namespace std;
class Application {
	enum { ENCODE, DECODE, IDLE } state;
	ARI_encoder* enc;
	ARI_decoder* dec;
	char* fn_in;
	char* fn_out;
public:
	Application();
	~Application();
	void run();
};

#endif
