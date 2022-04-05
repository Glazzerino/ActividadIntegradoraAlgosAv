#include <vector>
#include <fstream>
#include "KMP.h"
#include "Substring.h"
#include "Manacher.h"
#include <unordered_map>

using uint = unsigned int;

class Entry {
public:
  Entry(std::string filename, std::vector<std::string>& mal_codes);

	std::unordered_map<std::string, std::vector<uint>>& get_matches();
	uint get_total_matches();
  std::pair<uint, uint> get_palindrome();
	const std::string& get_text();
private:
	std::string raw_text;
	uint total_matches;
  std::unordered_map<std::string, std::vector<uint>> matches;
  std::pair<uint, uint> palindrome;
};

Entry::Entry(std::string filename, std::vector<std::string>& mal_codes) {
  std::ifstream file(filename);
  std::string line;
	total_matches = 0;
	matches = {};
  this->raw_text = "";
  while(getline(file, line))
    this->raw_text += std::string(line + "\n");
  uint pos = 0;
  for (std::string code : mal_codes) {
		auto positions = KMP_search(raw_text, code);
		if (!positions.empty())
			matches.insert(make_pair(code, positions));
		total_matches += positions.size();	
  } 
}

const std::string& Entry::get_text() {
	return raw_text;
}

std::unordered_map<std::string, std::vector<uint>>& Entry::get_matches() {
	return matches;
}

uint Entry::get_total_matches() {
	return this->total_matches;
}