#include <iostream>
#include <string>

using namespace std;

void readInt(int& number)
{
    string entry;

    while (true) {
        // the user enter a string
        getline(cin, entry);

        // it is empty?
        if (entry.empty() == true) {
            continue;
        }

        try {
            size_t length;
            number = stoi(entry, &length);

            // verifying if it's an integer
            if (entry.size() == length) {
                return;
            } else {
                cout << "Enter a valid integer, try again\n";
            }
        } catch (const std::exception& e) {
            cout << "Enter a valid integer, try again\n";
        }
    }
}

void readDouble(double& number)
{
    string entry;

    while (true) {
        // the user enter a string
        getline(cin, entry);

        // it is empty?
        if (entry.empty() == true) {
            continue;
        }

        try {
            size_t length;
            number = stod(entry, &length);

            // verifying if it's an integer
            if (entry.size() == length) {
                return;
            } else {
                cout << "Enter a valid number, try again\n";
            }
        } catch (const std::exception& e) {
            cout << "Enter a valid number, try again\n";
        }
    }
}