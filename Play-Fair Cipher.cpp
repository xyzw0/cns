#include <iostream> 
#include <cctype> 
#include <string> 
#include <algorithm> 
 
using namespace std; 
 
class PlayfairCipher { 
private: 
    string keySquare; 
 
    void prepareKey(const string& key) { 
        keySquare = ""; 
 
        for (char c : key) { 
            if (isalpha(c) && keySquare.find(toupper(c)) == string::npos) { 
                keySquare += toupper(c); 
            } 
        } 
        for (char c = 'A'; c <= 'Z'; ++c) { 
            if (c != 'J' && keySquare.find(c) == string::npos) { 
                keySquare += c; 
            } 
        } 
    } 
 
    pair<int, int> findPosition(char letter) { 
        int row, col; 
        for (row = 0; row < 5; ++row) { 
            for (col = 0; col < 5; ++col) { 
                if (keySquare[row * 5 + col] == letter) { 
                    return {row, col}; 
                } 
            } 
        } 
        return {-1, -1}; 
    } 
 
public: 
    PlayfairCipher(const string& key) { 
        prepareKey(key); 
    } 
 
    string encrypt(const string& plaintext) { 
        string processedText = preprocessText(plaintext); 
        string ciphertext = ""; 
 
        for (int i = 0; i < processedText.length(); i += 2) { 
            char first = processedText[i]; 
            char second = processedText[i + 1]; 
 
            pair<int, int> posFirst = findPosition(first); 
            pair<int, int> posSecond = findPosition(second); 
 
            if (posFirst.first == posSecond.first) { 
                ciphertext += keySquare[posFirst.first * 5 + (posFirst.second + 1) % 5]; 
                ciphertext += keySquare[posSecond.first * 5 + (posSecond.second + 1) % 5]; 
            } 
            else if (posFirst.second == posSecond.second) { 
                ciphertext += keySquare[((posFirst.first + 1) % 5) * 5 + posFirst.second]; 
                ciphertext += keySquare[((posSecond.first + 1) % 5) * 5 + posSecond.second]; 
            } 
            else { 
                ciphertext += keySquare[posFirst.first * 5 + posSecond.second]; 
                ciphertext += keySquare[posSecond.first * 5 + posFirst.second]; 
            } 
        } 
 
        return ciphertext; 
    } 
 
    string preprocessText(const string& text) { 
        string processedText = ""; 
        for (char c : text) { 
            if (isalpha(c)) { 
                processedText += toupper(c); 
                if (c == 'J') 
                    processedText.back() = 'I'; 
            } 
        } 
 
        if (processedText.length() % 2 != 0) { 
            processedText += 'Z'; 
        } 
 
        return processedText; 
    } 
}; 
                                                                 
int main() { 
    string key, plaintext; 
    cout << "Enter the key text: "; 
    getline(cin, key); 
    cout << "Enter the plain text: "; 
    getline(cin, plaintext); 
    PlayfairCipher cipher(key); 
    string ciphertext = cipher.encrypt(plaintext); 
    cout << "Key text: " << key << endl; 
    cout << "Plain text: " << plaintext << endl; 
    cout << "Cipher text: " << ciphertext << endl; 
    return 0; 
} 
