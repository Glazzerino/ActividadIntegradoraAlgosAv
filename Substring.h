using namespace std;
using uint = unsigned int;
class Substring {
public:
  static uint search(string a, string b) {
    vector<vector<uint>> mat(a.length()+1, vector<uint>(b.length()+1, 0));
    uint max = 0;
		uint finalPos = 0;
    std::string max_string = "";
    // If string matches, add previous match's counter of previous matches
    for (uint i=1; i<a.length()+1; i++) {
      for (uint j=1; j<b.length()+1; j++) {
        if (a[i-1] == b[j-1]) {
          mat[i][j] += mat[i-1][j-1] + 1;
          max = mat[i][j] > max ? mat[i][j] : max;
          if(mat[i][j] == max) finalPos = i - 1;
        }
      }
    }
  
    for(int finalPos; finalPos >= 0; finalPos--){
      max_string =+ a[finalPos]; 
    }
    
    return (max_string.length());
    }
};