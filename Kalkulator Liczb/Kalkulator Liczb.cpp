#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
using namespace std;

void welcome(int& choice, int& input);
void printCalc(int& choice, int& input);

vector<int> convert_binary(int input) {
    if (input <= 0) { 
        return { 0 }; 
    }

    vector<int> binary;

    while (input > 0) {
        binary.push_back(input % 2); 
        input /= 2;                 
    }

    reverse(binary.begin(), binary.end());

    return binary;
}

int main() {
    cout << "\n\n";

    int choice;
    int input;

    welcome(choice, input);

    if (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
        cout << "Blad: Wybrano zly system liczbowy. \n" << endl;
        main();
    }

    cout << endl;

    printCalc(choice, input);

    system("pause");
    return 0;
}

void printCalc(int& choice, int& input) {
    int ten = 0;
    vector<int> binary;
    int eight = 0;
    string sixteen = "0";
    bool isPalindrome = false;

    switch (choice) {
        case 1: {
            ten = input;
            binary = convert_binary(input);
            break;
        }
        case 2: {
            binary.push_back(input);
            break;
        }
        case 3: {
            eight = input;
            break;
        }
        case 4: {
            sixteen = input;
            break;
        }
        default:
            cout << "Blad" << endl;
    }

    cout << "###################################### \n";
    cout << "\n    Dziesietny: ";
    cout << ten;
    cout << "\n\n    Dwojkowy: ";
    for (int i = 0; i < binary.size(); ++i) {
        cout << binary[i];
    }
    cout << "\n\n    Osemkowy: ";
    cout << eight;
    cout << "\n\n    Szestnastkowy: ";
    cout << sixteen;
    cout << "\n\n    Czy jest palindromem: " << (isPalindrome ? "Tak": "Nie");
    cout << "\n" << "\n###################################### \n\n\n";

    system("pause");
    main();
}

void welcome(int& choice, int& input) {
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