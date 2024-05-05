#include <iostream> 
#include <string> 
using namespace std;

string toLowerCase(string input) {
    string output;

    for (char ch : input) {
        output+=tolower(ch);
    }
    return output;
}

string encrypt(string text, int shift) { 
    string result;
    for (char ch : text) { 
        if (isalpha(ch)) {
            char encryptedChar = isupper(ch) ?
                    (ch - 'A' + shift) % 26 + 'A' :
                    (ch - 'a' + shift) % 26 + 'a'; 
            result += encryptedChar;
        } 
        else {
        result += ch;
        }
 
    }
    return result;
}

string decrypt(string encryptedText, int shift) { 
    string result;
    for (char ch : encryptedText) { 
        if (isalpha(ch)) {
            char decryptedChar = isupper(ch) ?
                        (ch - 'A' - shift + 26) % 26 + 'A' :
                        (ch - 'a' - shift + 26) % 26 + 'a'; 
            result += decryptedChar;
        } 
        else {
            result += ch;
        }
    }
    return result;
}

int main() { 
    string text; 
    int shift;

    cout << "Enter a string: "; 
    getline(cin, text); 

    text = toLowerCase(text);

    cout << "Enter the Caesar Cipher shift value: "; 
    cin >> shift;

    string encrypted = encrypt(text, shift); 
    string decrypted = decrypt(encrypted, shift);

    cout << "Encrypted text: " << encrypted << endl; 
    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}


