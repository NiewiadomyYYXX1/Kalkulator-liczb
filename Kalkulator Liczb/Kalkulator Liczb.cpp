#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
using namespace std;

void welcome(int& choice, string& input); //deklaracje funkcji poczatkowych
void printCalc(int& choice, string& input);

bool checkIsPalindrome(string input) { //sprawdzanie czy same palidromem

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

vector<string> convert_binary(string preinput) { 

    long long input = stoll(preinput); //konwert na zmienna liczbowa long long bo ma byc 12 cyfr

    if (input <= 0) { 
        return { "0" };
    }

    vector<string> binary;

    while (input > 0) { // gdy jest wieksza od zera dodaje do arraya modulo z 2
        binary.push_back(to_string(input % 2)); 
        input /= 2;   // input przez 2 aby przygotowac do kolejne petli              
    }

    reverse(binary.begin(), binary.end()); //odwraca aby byla poprawna kolejnosc

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

    cout << endl;

    printCalc(choice, input);

    system("pause");
    return 0;
}

void printCalc(int& choice, string& input) {
    string ten = "0";
    vector<string> binary;
    vector<string> eight;
    vector<string> sixteen;
    bool isPalindrome = checkIsPalindrome(input);

    switch (choice) {
        case 1: {
            ten = input;
            binary = convert_binary(input);
            eight = convert_eight(input);
            sixteen = convert_sixteen(input);
            break;
        }
        case 2: {
            binary.push_back(input);
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
    cout << ten;
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