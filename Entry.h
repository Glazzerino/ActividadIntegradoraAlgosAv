#include <vector>
#include <fstream>
#include "KMP.h"
#include "Substring.h"
#include "Manacher.h"

using uint = unsigned int;

class Entry {
public:
  Entry(std::string filename, std::vector<std::string>& mal_codes);
  std::vector<std::pair<uint, uint>>& get_matches();
  std::pair<uint, uint> get_palindrome();
	const std::string& get_text();
private:
	std::string raw_text;
  std::vector<std::pair<uint, uint>> matches;
  std::pair<uint, uint> palindrome;
};

Entry::Entry(std::string filename, std::vector<std::string>& mal_codes) {
  std::ifstream file(filename);
  std::string line;
	matches = {};
  this->raw_text = "";
  while(getline(file, line))
    this->raw_text += std::string(line + "\n");
  uint pos = 0;
  for (std::string code : mal_codes) {
    pos = KMP::search(this->raw_text, code);
  	if (pos != -1) {
			matches.push_back(std::make_pair(pos, code.size()));
		}
  } 
}

const std::string& Entry::get_text() {
	return raw_text;
}

std::vector<std::pair<uint, uint>>& Entry::get_matches() {
	return matches;
}