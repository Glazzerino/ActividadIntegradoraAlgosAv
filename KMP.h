#include <vector>
#include <string>

std::vector<unsigned int> KMP_search(std::string text, std::string pattern) {
    std::vector<unsigned int> result;
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int m = pattern.size();
    unsigned int n = text.size();
    std::vector<unsigned int> pi(m);
    pi[0] = 0;
    for (unsigned int k = 1; k < m; k++) {
        while (j > 0 && pattern[k] != pattern[j]) {
            j = pi[j - 1];
        }
        if (pattern[k] == pattern[j]) {
            j++;
        }
        pi[k] = j;
    }
    while (i < n) {
        while (j > 0 && text[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == m) {
            result.push_back(i - m + 1);
            j = pi[j - 1];
        }
        i++;
    }
    return result;
}
