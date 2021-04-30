/* 
 * This file is part of the Fibonacci X distribution (https://github.com/wmthornton/Fibonacci-X).
 * Copyright (c) 2021 Wayne Michael Thornton aka DextersLaboratory2020.
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <unistd.h>
#include <stdlib.h>
#include "colors.h"

using namespace std;
using std::cout; using std::cin;
using std::endl; using std::string;

int main() {

    // Define the integer variables for use by the program in generating Fibonacci numbers. 
    int n, t1 = 0, t2 = 1, nextTerm = 0;

    // Define string variables for determining current working directory and file save directory.
    string homedir = getenv("HOME");
    string usrdir = homedir + "/Desktop";

    // Define variables to correspond to menu commands.
    string warranty = "show w";
    string conditions = "show c";
    char command;

    // Define a boolean value to display text while operations are being performed.
    bool working = false;

    system("clear"); // Clear the terminal screen before continuing. Not the best as 'system' can be a security hole, but
                     // we are using it nonetheless.

        // Determine the current working directory and display warning to user if the user is not currently inside their Desktop folder.
        char tmp[256];
        getcwd(tmp, 256);

        if (getcwd(tmp, 256) != usrdir) {

            cout << "DIRECTORY MISMATCH!";
            cout << "\n";
            cout << "This program must be run while your current working directory is set\n";
            cout << "to your Desktop folder. This is because we save output over 100 calculations to a file on\n";
            cout << "your Desktop so that you can access them later outside of the program.";
            cout << "\n";

            return 0;
        }

    cout << "Current working directory: " << tmp << endl;
    cout << "\n";
    cout << "Fibonacci-X (fib) Copyright (C) 2021 Wayne Thornton\n";
    cout << "This program comes with ABSOLUTELY NO WARRANTY; for details type\n"; 
    cout << "'w'. This is free software, and you are welcome to redistribute\n"; 
    cout << "it under certain conditions; type `c' for details.\n";
    cout << "\n";
    cout << "Enter a command (w for warranty, c for conditions, n for number entry): ";
    
    cin >> command;
    cout << "\n";

    switch (command) {
        case 'w':
            system("clear");
            //cout << "WARRANTY";
            return 0;
        case 'c':
            system("clear");
            //cout << "CONDITIONS";
            return 0;
        case 'n':
            cout << "Enter the number of terms: ";
            cin >> n;
            cout << "\n";
        default:
            cout << BOLD(FRED("Invalid Entry. Dropping to shell prompt.")) << endl;
            return 0;
    }

    // Prevent smartasses from overloading the memory buffers of the system by typing in large numbers of calculations.
    if (n >= 100000) {

        cout << BOLD(FRED("Unable to calculate due to memory buffer constraints! Dropping to shell prompt.")) << endl;
        return 0;
    }

    if (n <= 100) {

        working = true;
        cout << "Please wait while calculations are performed...";
        cout << "\n";
        cout << "\n";

        while (working == true) {
            // User can redirect output to file using standard terminal commands.
            //freopen ("Fibonacci.txt","w",stdout);
            cout << "Fibonacci Series: ";

            for (int i = 1; i <= n; ++i) {
                // Prints the first two terms.
                if(i == 1) {
                    cout << t1 << "  ";
                    continue;
                }
                if(i == 2) {
                    cout << t2 << "  ";
                    continue;
                }
                nextTerm = t1 + t2;
                t1 = t2;
                t2 = nextTerm;
                
                cout << nextTerm << "  ";

                working = false;
            
            }
            cout << "\n";
            cout << "\n";
            cout << "Calculations Complete! Dropping to shell prompt...";

        }

    } else {

        cout << "You have entered more than 100 calculations.\n";
        cout << "Output will be redirected to a file on your\n";
        cout << "desktop named 'Fibonacci.txt'\n";
        cout << "\n";
        cout << "\n";

        working = true;
        cout << "Please wait while calculations are performed. When completed you will drop back to a shell prompt.\n";
        cout << "\n";

        while (working == true) {
        // User can redirect output to file using standard terminal commands.
        freopen ("Fibonacci.txt","w",stdout);
        cout << "Fibonacci Series: ";

        for (int i = 1; i <= n; ++i) {
            // Prints the first two terms.
            if(i == 1) {
                cout << t1 << "  ";
                continue;
            }
            if(i == 2) {
                cout << t2 << "  ";
                continue;
            }
            nextTerm = t1 + t2;
            t1 = t2;
            t2 = nextTerm;
        
            cout << nextTerm << "  ";

            working = false;
            
        }

        fclose(stdout);

    }
    
    return 0;

    }

}

