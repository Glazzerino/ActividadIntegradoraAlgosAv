#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Entry.h"
using namespace std;
using uint = unsigned int;

int main() {
  string x;
  vector<string> codigos;
  vector<string> transmisiones;
  fstream newFile;
  newFile.open("mcode.txt");
	
  while(newFile >> x){
    codigos.push_back(x);    
  }
	
  newFile.close();
	
	string file_name;
	
	for (int i=1; i<=3; i++) {
		file_name = "transmission" + to_string(i) + ".txt";
		cout << file_name << '\n';
		Entry entry(file_name, codigos);
		auto matches = entry.get_matches();
		cout << entry.get_total_matches() << '\n';
		cout << entry.get_text() << '\n';
		
  }
  
} 