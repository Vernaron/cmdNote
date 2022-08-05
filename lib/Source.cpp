#include "noteFuncs.h"
#include "cmdNoteConfig.h"
int main(){
   std::cout << " Version " << cmdNote_VERSION_MAJOR << "."
              << cmdNote_VERSION_MINOR << std::endl;
	//std::cout<<"Please specify the mode you want to boot in: r for read, w for write:";
	writeNote();
	readNote();
	return 0;
}