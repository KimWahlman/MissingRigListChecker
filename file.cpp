#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <ctime>

void readFile(std::string filename, std::vector<std::string>& v) {
	std::ifstream inFile(filename);
	std::string line = "";

	while(std::getline(inFile, line)) {
		v.push_back(line);
	}
	inFile.close();
}

std::string printDateTime() {
	auto end = std::chrono::system_clock::now();
	std::time_t endTime = std::chrono::system_clock::to_time_t(end);
	std::string str = std::ctime(&endTime);
	std::string filename = str.substr(0,3) + " " + str.substr(4,3) + " " + str.substr(9,1) + " " + str.substr(20,4);
	return filename;
}

void run() {
	std::vector<std::string> f1;
	std::vector<std::string> f2;

	std::cout << "Check:\n1. Tent\n2. Container\n\n>> ";
	unsigned int option = 0;
	std::cin >> option;

	if(option == 1)
    {
        readFile("tent_trueList.txt", f1);
        readFile("tent_listToCheck.txt", f2);
    } else {
        readFile("container_trueList.txt", f1);
        readFile("container_listToCheck.txt", f2);
    }

	bool exists = false;

	std::string filename;

	if(option == 1)
        filename = "tent_missingRigs " + printDateTime() + ".txt";
    else
        filename = "container_missingRigs " + printDateTime() + ".txt";

    std::ofstream fileToSave(filename);

	if(fileToSave.is_open()) {
		fileToSave << printDateTime() << std::endl;
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

int main() {
	run();
}
