#include <iostream> 
#include <cctype> 

std::string vigenereCipherEncrypt(const std::string& plaintext, const std::string& keyword) { 

    std::string encryptedText = ""; 

    for (size_t i = 0, j = 0; i < plaintext.length(); ++i) { 
        char currentChar = plaintext[i]; 

        if (isalpha(currentChar)) { 
            currentChar = toupper(currentChar); 
            char keyChar = keyword[j % keyword.length()]; 
            keyChar = toupper(keyChar); 
            int shift = keyChar - 'A'; 
            char encryptedChar = 'A' + (currentChar - 'A' + shift) % 26;    
            encryptedText += encryptedChar; 
            ++j; 
        } 
        else { 
            encryptedText += currentChar; 
        } 
    } 
    return encryptedText; 
} 

int main() { 
    std::string plaintext, keyword; 
    std::cout << "Enter the plaintext message: "; 
    std::getline(std::cin, plaintext); 
    std::cout << "Enter the keyword: "; 
    std::cin >> keyword; 
    std::string encryptedMessage = vigenereCipherEncrypt(plaintext, keyword); 
    std::cout << "Encrypted Message: " << encryptedMessage << std::endl; 
    return 0; 
}   
