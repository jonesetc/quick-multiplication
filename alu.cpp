#include <cstdlib>
#include <stdint.h>
#include <iostream>
#include <bitset>

using namespace std;

// A global bitset for printing in binary
bitset<16> display(0);

// Function prototypes
void multiply(int32_t&, int32_t&);
void divide(int32_t&, int32_t&);

int main(int argc, char const *argv[])
{
    // The three parts to a mult or div operation: lhs, rhs, and operator
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

    // Get the operands if they didn't choose to quit
    if (tolower(operation) != 'q')
    {
        cout << "Enter the left-hand operand" << endl;
        cin >> register1;
        cout << "Enter the right-hand operand" << endl;
        cin >> register2; 

        // Call the right function depending on the operator
        operation == '/' ? divide(register1, register2): multiply(register1, register2);

        display = register1 >> 16;
        cout << "Final hi register: " << display << endl;

        display = register1 & 0xFFFF;
        cout << "Final lo register: " << display << endl;
    }

    return 0;
}

void multiply(int32_t &multiplier, int32_t &multiplicand)
{
    display = multiplier >> 16;
    cout << "Initial hi register: " << display << endl;
    display = multiplier & 0xFFFF;
    cout << "Initial lo register: " << display << endl;

    for (int i = 0; i < 16; ++i)
    {
        if (multiplier & 1)
            multiplier += multiplicand << 16;

        display = multiplier >> 16;
        cout << "Current hi register: " << display << endl;
        display = multiplier & 0xFFFF;
        cout << "Current lo register: " << display << endl;

        multiplier >>= 1;

        display = multiplier >> 16;
        cout << "Current hi register: " << display << endl;
        display = multiplier & 0xFFFF;
        cout << "Current lo register: " << display << endl;
    }
}


void divide(int32_t &dividend, int32_t &divisor)
{
    int32_t temp = 0;

    display = dividend >> 16;
    cout << "Initial remainder: " << display << endl;
    display = dividend & 0xFFFF;
    cout << "Initial dividend: " << display << endl;

    for (int i = 0; i < 16; ++i)
    {
        dividend <<= 1;

        display = dividend >> 16;
        cout << "Current remainder: " << display << endl;
        display = dividend & 0xFFFF;
        cout << "Current dividend: " << display << endl;

        temp = dividend >> 16;
        temp -= divisor;
        dividend &= 0xFFFF;
        dividend |= temp << 16;

        display = dividend >> 16;
        cout << "Current remainder: " << display << endl;
        display = dividend & 0xFFFF;
        cout << "Current dividend: " << display << endl;

        dividend >> 31 ? dividend += divisor << 16 : dividend += 1;

        display = dividend >> 16;
        cout << "Current remainder: " << display << endl;
        display = dividend & 0xFFFF;
        cout << "Current dividend: " << display << endl;
    }
}