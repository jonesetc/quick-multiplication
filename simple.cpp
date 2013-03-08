#include <cstdlib>
#include <stdint.h>
#include <iostream>
#include <bitset>

using namespace std;

// A global bitset for printing in binary
bitset<16> display(0);

int main(int argc, char const *argv[])
{
    char operation;
    int32_t register1;
    int32_t register2;

    cout << "Enter / for division, * for multiplication, or q to quit" << endl;
    cin >> operation;

    // Repeat until we get a good operator or a q
    while (operation != '/' && operation != '*' && tolower(operation) != 'q')
    {
        cout << "Enter a valid operation: / for division, " 
            << "* for multiplication, or q to quit" << endl;
        cin >> operation;
    }

    if (tolower(operation) != 'q')
    {
        cout << "Enter the left-hand operand" << endl;
        cin >> register1;
        cout << "Enter the right-hand operand" << endl;
        cin >> register2; 

        // Call the right function depending on the operator
        register1 = operation == '/' ? register1 / register2 : \
            register1 * register2;

        // If division, set the hi register to the remainder
        if (operation == '/')
            register1 |= (register1 % register2) << 16;

        display = register1 >> 16;
        cout << "Final hi register: " << display << endl;

        display = register1 & 0xFFFF;
        cout << "Final lo register: " << display << endl;
    }

    return 0;
}