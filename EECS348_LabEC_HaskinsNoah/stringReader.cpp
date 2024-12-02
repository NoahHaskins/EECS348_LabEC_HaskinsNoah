//Noah Haskins
//Extra Credit Lab
//Points towards Exam Please

#include <iostream>      // For input and output
#include <iomanip>       // For controlling output format (e.g., fixed, setprecision)
#include <string>        // For handling strings
#include <cctype>        // For character checks like isdigit

using namespace std;

// Function prototype for extractNumeric, which validates and extracts a numeric value
double extractNumeric(const string& str);

// Function to validate and extract a numeric value from the string
double extractNumeric(const string& str) {
    int len = str.length();  // Get the length of the input string
    bool hasDecimal = false;  // Flag to track if a decimal point is present
    bool hasSign = false;     // Flag to track if a sign (+ or -) is present

    if (len == 0 || len > 20) {  // Reject input if it is empty or too long
        return -999999.99;  // Return error value
    }

    // Loop through each character in the string to validate it
    for (int i = 0; i < len; ++i) {
        char c = str[i];  // Get the current character

        if (isdigit(c)) {  // If the character is a digit, continue
            continue;
        } else if (c == '+' || c == '-') {  // Check if the character is a sign
            if (i == 0 && !hasSign) {  // A sign is valid only at the start of the string
                hasSign = true;  // Mark that a sign has been encountered
            } else {
                return -999999.99;  // Return error if the sign is misplaced
            }
        } else if (c == '.') {  // Check if the character is a decimal point
            if (!hasDecimal) {  // A decimal point is valid only once
                hasDecimal = true;  // Mark that a decimal point has been encountered
            } else {
                return -999999.99;  // Return error if there are multiple decimal points
            }
        } else {
            return -999999.99;  // Return error if the character is invalid
        }
    }

    // Try to convert the validated string to a double
    try {
        return stod(str);  // Convert the string to a double
    } catch (...) {  // Catch any conversion errors
        return -999999.99;  // Return error if the conversion fails
    }
}

int main() {
    string input;  // Variable to store user input

    // Infinite loop to continuously prompt the user for input
    while (true) {
        cout << "Enter a string (or 'END' to quit): ";  // Prompt user for input
        cin >> input;  // Read user input into the string variable

        if (input == "END") {  // Check if the user wants to exit
            break;  // Exit the loop
        }

        // Call extractNumeric to validate and extract a number from the input
        double number = extractNumeric(input);

        if (number != -999999.99) {  // Check if the input is valid
            // Display the valid number formatted to 4 decimal places
            cout << "The input is: " << fixed << setprecision(4) << number << endl;
        } else {
            // Display a message indicating the input is invalid
            cout << "The input is invalid." << endl;
        }
    }

    return 0;  // Indicate successful program termination
}


