#include "Read.h"
#include "Write.h"
#include "cmdNoteConfig.h"
int main(){
   std::cout << " Version " << cmdNote_VERSION_MAJOR << "."
              << cmdNote_VERSION_MINOR << std::endl;
	helloWorld();
	return 0;
}