 
#include <iostream> 
#include <string> 
#include <vector> 
 
std::string rail_fence_encrypt(const std::string& plaintext, int key) { 
    std::vector<std::vector<char>> rail(key, std::vector<char>(plaintext.length(), '.')); 
 
    bool dir_down = false; 
    int row = 0, col = 0; 
 
    for (char c : plaintext) { 
        if (row == 0 || row == key - 1) { 
            dir_down = !dir_down; 
        } 
 
        rail[row][col++] = c; 
 
        dir_down ? ++row : --row; 
    } 
 
    std::string result; 
    for (int i = 0; i < key; ++i) { 
        for (int j = 0; j < plaintext.length(); ++j) { 
            if (rail[i][j] != '.') { 
                result += rail[i][j]; 
            } 
        } 
    } 
 
    return result; 
} 
 
int main() { 
    std::string plaintext; 
    int key; 
 
    std::cout << "Enter a text to encrypt: "; 
    std::getline(std::cin, plaintext); 
                                                                
std::cout << "Enter the number of rails: "; 
std::cin >> key; 
std::string encrypted_text = rail_fence_encrypt(plaintext, key); 
std::cout << "Encrypted text: " << encrypted_text << std::endl; 
return 0; 
}
