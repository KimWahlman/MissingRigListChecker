#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void readFile(std::string filename, std::vector<std::string>& v) {
	std::ifstream inFile(filename);
	std::string line = "";
	
	while(std::getline(inFile, line)) {
		v.push_back(line);
	}
	inFile.close();
}

int main() {
	std::vector<std::string> f1;
	std::vector<std::string> f2;
	
	readFile("trueList.txt", f1);
	readFile("listToCheck.txt", f2);
	
	bool exists = false;
	
	std::ofstream fileToSave("missingRigs.txt");
	if(fileToSave.is_open()) {
		for(unsigned int i = 0; i < f1.size(); i++) {
			exists = false;
			for(unsigned int j = 0; j < f2.size(); j++) {
				if(f1[i] == f2[j]) { exists = true; }
			}
			
			if(!exists) {
				std::string str = f1[i] + " is missing.";
				fileToSave << str << std::endl;
			}
		}
		fileToSave.close();
	}
	std::cout << "Exiting...\n";
}
