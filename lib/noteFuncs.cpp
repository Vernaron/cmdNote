#include "noteFuncs.h"
void replaceWord(std::string& mainString, std::string subString, std::string replacementString);
void readNote(){
	std::ofstream checkFile;
	checkFile.open("Notes", std::ios::app);
	checkFile.close();
	std::ifstream file;
	file.open("Notes");
	std::string output;
	while(!file.eof()){
		std::getline(file, output);
		if(std::regex_match(output, std::regex(".*TIME.*"))){
			replaceWord(output, "(.*)(TIME)(.*)", "$1$3");
			output='\n'+output;
		}
		else{
			output="\n    "+output;
		}
		std::cout<<output;
	}
	file.close();
	std::cout<<"Press Enter to Exit";
	std::cin.ignore();
}
void writeNote(){
	std::string newEntry;
	std::string input=" ";
	std::cout<<"You have now entered a new entry in Write mode. Whenever you want to end this mode, type endNote";
	std::ofstream file;
	file.open("Notes", std::ios::app);
	auto entryDate=std::chrono::system_clock::now();
	std::time_t entryTimeFinal = std::chrono::system_clock::to_time_t(entryDate);
	newEntry+="TIME"+newEntry+std::ctime(&entryTimeFinal);
	std::cout<<newEntry;
	do{
		std::getline(std::cin, input);
		newEntry+=input+'\n';
	}while(!std::regex_match(input, std::regex("end(n|N)ote")));
	std::cout<<newEntry<<" "<<input;
	replaceWord(newEntry, ".*end(n|N)ote\n*.*", "");
	file<<newEntry;
	file.close();
}
void replaceWord(std::string& mainString, std::string subString, std::string replacementString){
	if(subString==replacementString){
		return;
	}
	mainString=std::regex_replace(mainString, std::regex(subString), replacementString);
}