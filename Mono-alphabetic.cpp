#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>
using namespace std;

string generateKey() {
    string key = "abcdefghijklmnopqrstuvwxyz";
    srand(time(0));
    random_shuffle(key.begin(), key.end());
    return key;
}

string encrypt(string plaintext, string key) {
    string ciphertext = plaintext;

    for (int i = 0; i < plaintext.length(); i++) {

        if (isalpha(plaintext[i])) {
            char ch = tolower(plaintext[i]);

            ciphertext[i] = isupper(plaintext[i]) ? toupper(key[ch - 'a']) :
            key[ch - 'a'];
        }
    }
    return ciphertext;
}

string decrypt(string ciphertext, string key) {
    string plaintext = ciphertext;
    for (int i = 0; i < ciphertext.length(); i++) {
        if (isalpha(ciphertext[i])) {
            char ch = tolower(ciphertext[i]);
            size_t index = key.find(tolower(ciphertext[i]));
            plaintext[i] = isupper(ciphertext[i]) ? toupper('a' + index) : 'a'+ index;
        }
    }
    return plaintext;
}

int main() {
    string key = generateKey();
    string plaintext;

    cout << "Enter plaintext: ";

    getline(cin, plaintext);

    string encryptedText = encrypt(plaintext, key);
    cout << "Original Text: " << plaintext << endl;
    cout << "Encrypted Text: " << encryptedText << endl;
    string decryptedText = decrypt(encryptedText, key);
    cout << "Decrypted Text: " << decryptedText << endl;
    
    return 0;
}
