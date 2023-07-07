#include <iostream>

using namespace std;

void getch()
{
    char character;

    do {
        cout << "Press enter to continue";
    } while ((character = getchar()) != '\n');
    system("clear");
}