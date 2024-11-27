#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
using namespace std;

void welcome(int& choice, string& input); 
void printCalc(int& choice, string& input);
string joinVectorToString(vector<string>& vector);

bool checkIsPalindrome(string input) { 

    string firstInput = input;
    string lastInput = input;

    reverse(lastInput.begin(), lastInput.end());

    if (firstInput == lastInput) {
        return true;
    }
    else {
        return false;
    }
}

vector<string> convert_ten(string input) {

    long long output = 0;
    int power = 1;

    for (int i = input.size() - 1; i >= 0; i--) {
        if (input[i] == '1') {
            output += power;
        }
        power *= 2;
    }

    vector<string> ten;
    ten.push_back(to_string(output));

    return ten;

}

vector<string> convert_binary(string preinput) { 

    long long input = stoll(preinput); 

    if (input <= 0) { 
        return { "0" };
    }

    vector<string> binary;

    while (input > 0) { 
        binary.push_back(to_string(input % 2)); 
        input /= 2;                
    }

    reverse(binary.begin(), binary.end()); 

    return binary;
}

vector<string> convert_eight(string preinput) {

    long long input = stoll(preinput);

    if (input <= 0) {
        return { "0" };
    }

    vector<string> eight;

    while (input > 0) {
        eight.push_back(to_string(input % 8));
        input /= 8;
    }

    reverse(eight.begin(), eight.end());

    return eight;
}

vector<string> convert_sixteen(string preinput) {
    long long input = stoll(preinput);

    if (input <= 0) {
        return { "0" };
    }

    vector<string> sixteen;

    string output;

    while(input > 0){
        int num = input % 16;
        if (num < 10) {
            sixteen.push_back(to_string(num));
        }
        else {
            char hex = 'A' + (num - 10);
            sixteen.push_back(string(1, hex));
        }
        input /= 16;
    }

    reverse(sixteen.begin(), sixteen.end());

    return sixteen;
}

int main() {
    cout << "\n\n";

    int choice;
    string input;

    welcome(choice, input);

    if (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
        cout << "Blad: Wybrano zly system liczbowy. \n" << endl;
        main();
    }

    bool isValid = false;

    while (!isValid) {
        isValid = true;

        for (char ch : input) {
            if (choice == 1 && (ch != '0' || ch > '9')) {
                isValid = false;
                break;
            }
            else if (choice == 2 && (ch != '0' && ch != '1')) {
                isValid = false;
                break;
            }
            else if (choice == 3 && (ch < '0' && ch > '7')) {
                isValid = false;
                break;
            }
            else if (choice == 4 && !((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'F') || (ch >= 'a' && ch <= 'f'))) {
                isValid = false;
                break;
            }
        }
        if (!isValid) {
            cout << "Blad: Liczba nie jest poprawna w wybranym systemie liczbowym.";
            main();
        }
    }

    cout << endl;

    printCalc(choice, input);

    system("pause");
    return 0;
}

void printCalc(int& choice, string& input) {
    vector<string> ten;
    vector<string> binary;
    vector<string> eight;
    vector<string> sixteen;
    bool isPalindrome = checkIsPalindrome(input);

    switch (choice) {
        case 1: {
            ten.push_back(input);
            binary = convert_binary(input);
            eight = convert_eight(input);
            sixteen = convert_sixteen(input);
            break;
        }
        case 2: {
            ten = convert_ten(input);
            binary.push_back(input);
            eight = convert_eight(joinVectorToString(ten));
            sixteen = convert_sixteen(joinVectorToString(ten));
            break;
        }
        case 3: {
            eight.push_back(input);
            break;
        }
        case 4: {
            sixteen.push_back(input);
            break;
        }
        default:
            cout << "Blad" << endl;
    }

    cout << "###################################### \n";
    cout << "\n    Dziesietny: ";
    for (int i = 0; i < ten.size(); ++i) {
        cout << ten[i];
    }
    cout << "\n\n    Dwojkowy: ";
    for (int i = 0; i < binary.size(); ++i) {
        cout << binary[i];
    }
    cout << "\n\n    Osemkowy: ";
    for (int i = 0; i < eight.size(); ++i) {
        cout << eight[i];
    }
    cout << "\n\n    Szestnastkowy: ";
    for (int i = 0; i < sixteen.size(); ++i) {
        cout << sixteen[i];
    }
    cout << "\n\n    Czy jest palindromem: " << (isPalindrome ? "Tak": "Nie");
    cout << "\n" << "\n###################################### \n\n\n";

    system("pause");
    main();
}

void welcome(int& choice, string& input) {
    cout << "###################################### \n"
        << "Wybierz system liczbowy do zamiany: \n"
        << "    1 -> Dziesietny\n"
        << "    2 -> Dwojkowy\n"
        << "    3 -> Osemkowy\n"
        << "    4 -> Szesnastkowy\n"
        << "Twoj wybor: ";
    cin >> choice;

    cout << "Podaj liczbe: ";
    cin >> input;
    cout << "###################################### \n" << endl;
}

string joinVectorToString(vector<string>& vector) {
    string result;

    for (int i = 0; i < vector.size(); i++) {
        result += vector[i];
    }

    return result;
}