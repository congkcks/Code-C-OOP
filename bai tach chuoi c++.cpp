#include <iostream>
#include <string>
#include <sstream>
#include <vector>
int main() {
    std::string str = "Hello, world! How are you?";
    
    std::vector<std::string> words;
    std::stringstream ss(str);
    std::string word;
    
    while (ss >> word) {
        words.push_back(word);
    }
    
    // In các t? dã tách
    for (const std::string& w : words) {
        std::cout << w << std::endl;
    }
    
    return 0;
}
