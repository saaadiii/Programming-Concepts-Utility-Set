#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void checkNumericConstant() {
    string input;
    cout << "Enter input: ";
    cin >> input;

    bool isNumeric = true;

    for (int i = 0; i < input.length(); i++) {
        if (input[i] < '0' || input[i] > '9') {
            isNumeric = false;
            break;
        }
    }

    if (isNumeric)
        cout << "This is a numeric constant." << endl;
    else
        cout << "This is not numeric." << endl;
}

void checkOperator() {
    string input;
    cout << "Enter expression: ";
    cin.ignore();
    getline(cin, input);

    int count = 1;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '%' || input[i] == '=') {
            cout << "operator " << count << ": " << input[i] << endl;
            count++;
        }
    }

    if (count == 1)
        cout << "No operator found.\n";
}

void checkCommentLine() {
    string input;
    cout << "Enter input: ";
    cin.ignore();
    getline(cin, input);

    if (input.substr(0, 2) == "//")
        cout << "This is a single line comment.\n";
    else if (input.substr(0, 2) == "/*" && input.substr(input.size() - 2) == "*/")
        cout << "This is a multiple line comment.\n";
    else
        cout << "This is not a comment.\n";
}

void checkIdentifier() {
    string input;
    cout << "Enter input: ";
    cin >> input;

    if ((input[0] >= 'A' && input[0] <= 'Z') || (input[0] >= 'a' && input[0] <= 'z') || input[0] == '_') {
        bool valid = true;
        for (int i = 1; i < input.length(); i++) {
            if (!((input[i] >= 'A' && input[i] <= 'Z') ||(input[i] >= 'a' && input[i] <= 'z') ||(input[i] >= '0' && input[i] <= '9') ||input[i] == '_')) {
                valid = false;
                break;
            }
        }
        if (valid)
            cout << "Valid Identifier" << endl;
        else
            cout << "Invalid Identifier" << endl;
    } else {
        cout << "Invalid Identifier" << endl;
    }
}

void findArrayAverage() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    float sum = 0;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    float avg =  (sum / n) ;
    cout << "Average value = " << avg << endl;
}

void findArrayMinMax() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    cout << "Minimum value = " << min << endl;
    cout << "Maximum value = " << max << endl;
}

void concatenateFullName() {
    string first, last;
    cout << "Enter first name: ";
    cin >> first;
    cout << "Enter last name: ";
    cin >> last;
    cout << "Full name = " << first + " " + last << endl;
}

int main() {
    int choice;

    while (true) {
        system("cls");
        cout << "=====================================\n";
        cout << "       USER MENU\n";
        cout << "=====================================\n";
        cout << "1. Check Numeric Constant\n";
        cout << "2. Check Operator\n";
        cout << "3. Check Comment Line\n";
        cout << "4. Check Identifier\n";
        cout << "5. Find Average of Array\n";
        cout << "6. Find Min and Max of Array\n";
        cout << "7. Concatenate Full Name\n";
        cout << "0. Exit\n";
        cout << "=====================================\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        cout << endl;

        switch (choice) {
            case 1: checkNumericConstant();
            break;
            case 2: checkOperator();
            break;
            case 3: checkCommentLine();
             break;
            case 4: checkIdentifier();
             break;
            case 5: findArrayAverage();
             break;
            case 6: findArrayMinMax();
            break;
            case 7: concatenateFullName();
            break;
            case 0:
                cout << "Exiting program... Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }

        cin.ignore();
        cout << "\nPress Enter to return to menu...";
        cin.get();
    }

    return 0;
}
