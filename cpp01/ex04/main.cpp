#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

static void	openInFile(std::ifstream &file, std::string fileName) {
	file.open(fileName.c_str(), std::ifstream::in);
	if (!file) {
		std::cout << "Cannot open file " << fileName << std::endl;
		exit(EXIT_FAILURE);
	}
}

static void	openOutFile(std::ifstream &inFile, std::ofstream &file, std::string fileName) {
	fileName.append(".replace");
	file.open(fileName.c_str(), std::ofstream::out);
	if (!file) {
		std::cout << "Cannot create file " << fileName << std::endl;
		inFile.close();
		exit(EXIT_FAILURE);
	}
}

static bool	isStrNextTo(std::string str, std::ifstream &inFile) {
	char	c;

	if (str.size() == 1)
		return true;
	for (int i = 1; i < (int)str.size(); i++) {
		inFile.get(c);
		if (str[i] != c)
			return false;
	}
	return true;
}

static void	copyFile(std::ifstream &inFile, std::ofstream &outFile, std::string s1, std::string s2) {
	int		pos;
	char	c;

	while (inFile.get(c)) {
		if (s1.size() > 0 and c == s1[0]) {
			pos = inFile.tellg();
			if (!isStrNextTo(s1, inFile)) {
				inFile.seekg(pos);
				outFile << c;
			}
			else
				for (int i = 0; i < (int)s2.size(); i++)
					outFile << s2[i];
		}
		else
			outFile << c;
	}
}

int	main(int argc, char const *argv[]) {
	std::ifstream	inFile;
	std::ofstream	outFile;

	if (argc != 4) {
		std::cout << "Usage: ./sed <filename> <string_to_replace> <string_that_replace>" << std::endl;
		return 1;
	}
	openInFile(inFile, argv[1]);
	openOutFile(inFile, outFile, argv[1]);
	copyFile(inFile, outFile, argv[2], argv[3]);
	inFile.close();
	outFile.close();
	return 0;
}