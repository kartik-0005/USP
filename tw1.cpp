#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L

#include <iostream>
#include <unistd.h>
#include <limits.h>

using namespace std;

int main() {
    int choice;
    long result;

    cout << "Enter the choice (1 for runtime limits, 2 for compile-time limits): ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Runtime configuration limits:\n";

            result = sysconf(_SC_CLK_TCK);
            cout << "Number of Clock Ticks: " << (result == -1 ? "System does not support" : to_string(result)) << endl;

            result = sysconf(_SC_CHILD_MAX);
            cout << "Maximum Number of Child Processes: " << (result == -1 ? "System does not support" : to_string(result)) << endl;

            result = pathconf("/", _PC_PATH_MAX);
            cout << "Maximum Path Length: " << (result == -1 ? "System does not support" : to_string(result)) << endl;

            result = pathconf("/", _PC_NAME_MAX);
            cout << "Maximum Characters in Filename: " << (result == -1 ? "System does not support" : to_string(result)) << endl;

            result = sysconf(_SC_OPEN_MAX);
            cout << "Maximum Number of Open Files: " << (result == -1 ? "System does not support" : to_string(result)) << endl;
            break;

        case 2:
            cout << "Compile-time configuration limits:\n";
            cout << "Maximum Child Processes: " << _POSIX_CHILD_MAX << endl;
            cout << "Maximum Open Files: " << _POSIX_OPEN_MAX << endl;
            cout << "Maximum Path Length: " << _POSIX_PATH_MAX << endl;
            cout << "Maximum Filename Length: " << _POSIX_NAME_MAX << endl;
            break;

        default:
            cout << "Invalid choice\n";
            break;
    }

    return 0;
}
