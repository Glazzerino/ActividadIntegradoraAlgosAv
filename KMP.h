
class KMP {
public:
  static unsigned int search(std::string text, std::string pattern) {
      int i = 0;
      int j = 0;
      int n = text.length();
      int m = pattern.length();
      std::vector<int> lps(m);
      lps[0] = 0;
  
      while (i < m - 1) {
          if (pattern[i] == pattern[j]) {
              i++;
              j++;
              lps[i] = j;
          } else if (j > 0) {
              j = lps[j - 1];
          } else {
              i++;
          }
      }
  
      i = 0;
      j = 0;
      while (i < n && j < m) {
          if (text[i] == pattern[j]) {
              i++;
              j++;
          } else if (j > 0) {
              j = lps[j - 1];
          } else {
              i++;
          }
      }
  
      if (j == m) {
          return i - m;
      } else {
          return -1;
      }
  }
};