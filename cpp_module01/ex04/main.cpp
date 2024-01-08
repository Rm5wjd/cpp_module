#include <fstream>
#include <iostream>
#include <string>

void replace_str(std::string& origin, const char *findStr, const char *replaceStr)
{
	std::size_t pos = origin.find(findStr);
	std::size_t find_pos = 0;
	while (pos != std::string::npos) {
		origin.erase(pos, std::strlen(findStr));
		origin.insert(pos, replaceStr);
		find_pos += std::strlen(replaceStr); 
		pos = origin.find(findStr, find_pos);
	}
}

int main(int argc, char *argv[])
{
	if (argc != 4) {
		std::cout << "input error!" << std::endl;
		return 1;
	}
	if (std::string(argv[2]).compare("") == 0) {
		std::cout << "input error!" << std::endl;
		return 1;
 	}
	std::ifstream in(argv[1]);
	std::string outFile(argv[1]);
	outFile.append(".replace");
	std::ofstream out(outFile.c_str());

	if (!in.is_open() || !out.is_open()) {
		std::cout << "no file" << std::endl;
		return 0;
	}

	std::string s;
	while (in) {
		getline(in, s);
		if (!in.eof())
			s.append("\n");
		replace_str(s, argv[2], argv[3]);
		out << s;
		if (in.eof())
			break;
	}
	in.close();
	out.close();
	return 0;
}