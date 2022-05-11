// Copyright (c) 2022 Alex De Meo All rights reserved
//
// Created By: Alex De Meo
// Date: 05/10/22
// Description: gets an operation and two numbers from user, calulates an answer
// with the numbers and operation entered
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stof;

// This function takes the inputted operation and numbers from the user and
// creates an equation with it.
string calculate(float num1flt, float num2flt, string operation) {
    string result;
    float calc;
    // checks which operation was entered
    if (operation == "/") {
        calc = num1flt / num2flt;
        // this was a workaround for a bug that was causing the function to not
        // return anything
        result = std::to_string(calc);
    } else if (operation == "*" || operation == "x") {
        calc = num1flt * num2flt;
        result = std::to_string(calc);
    } else if (operation == "+") {
        calc = num1flt + num2flt;
        result = std::to_string(calc);
    } else if (operation == "-") {
        calc = num1flt - num2flt;
        result = std::to_string(calc);
    } else {
        result = "The inputted operation was invalid";
    }

    // returns result to main
    return result;
}


int main() {
    // collecting user input
    string operation, num1, num2;
    cout << "Enter the operation of your equation: ";
    cin >> operation;

    cout << "Enter the first number to be calculated: ";
    cin >> num1;

    cout << "Enter the second number to be calculated: ";
    cin >> num2;

    try {
        // converting to float
        float num1flt = stof(num1);
        float num2flt = stof(num2);
        // calls the calulcate function
        string answer = calculate(num1flt, num2flt, operation);
        // decides which answer to output
        if (answer == "The inputted operation was invalid") {
            cout << endl << answer;
        } else {
            double numAnswer = stod(answer);
            cout.precision(5);
            cout << endl << num1 << " " << operation << " " << num2 <<
            " = " << numAnswer;
        }
    } catch (...) {
        cout << "Entered numbers must be actual numbers";
    }
}
