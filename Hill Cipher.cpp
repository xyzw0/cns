#include <iostream>
#include <string>
#include <vector>

using namespace std;
int charToNumeric(char c) {
    return c - 'A';
}

char numericToChar(int num) {
    return 'A' + num;
}

vector<int> multiplyVectorKey(const vector<int>& inputVector, const vector<vector<int>>& keyMatrix) {
    vector<int> resultVector(2, 0);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            resultVector[i] += inputVector[j] * keyMatrix[j][i];
        }
        resultVector[i] %= 26;
    }
    return resultVector;
}

string hillCipherEncrypt(const string& plaintext, const vector<vector<int>>& keyMatrix) {
    string encryptedText = "";
    for (size_t i = 0; i < plaintext.length(); i += 2) {
        int char1 = charToNumeric(plaintext[i]);
        int char2 = charToNumeric(plaintext[i + 1]);
       
        vector<int> inputVector = {char1, char2};
        vector<int> resultVector = multiplyVectorKey(inputVector, keyMatrix);

        encryptedText += numericToChar(resultVector[0]);
        encryptedText += numericToChar(resultVector[1]);
    }
    return encryptedText;
}

int main() {
    string plaintext;
    cout << "Enter plaintext message: ";
    getline(cin, plaintext);
    
    string keyInput;
    cout << "Enter 4 digit key (e.g., 1 2 3 4 for a 2x2 matrix): ";
    getline(cin, keyInput);

    for (char &c : plaintext) {
        c = toupper(c);
    }

    if (plaintext.length() % 2 != 0) {
        plaintext += 'X';
    }

    vector<int> keyDigits;
    size_t pos = 0;

    while ((pos = keyInput.find(' ')) != string::npos) {
        keyDigits.push_back(stoi(keyInput.substr(0, pos)));
        keyInput.erase(0, pos + 1);
    }

    keyDigits.push_back(stoi(keyInput));
    
    if (keyDigits.size() != 4) {
        cerr << "Invalid key format. Please enter 4 digits." << endl;
        return 1;
    }    
    
    vector<vector<int>> keyMatrix = {{keyDigits[0], keyDigits[1]}, {keyDigits[2], keyDigits[3]}};
    string encryptedText = hillCipherEncrypt(plaintext, keyMatrix);
    cout << "Encrypted Message: " << encryptedText << endl;
    
    return 0;
}

