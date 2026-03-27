#include <unistd.h>
#include <sys/wait.h>
#include <vector>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

int main() {

    while (true) {
        // flush -> immediately printed to screen and waits for user input
        cout << "$ " << flush;

        string line;

        if (!getline(cin,line)) {
            break;
        }

        vector<string> tokens;

        // Reading from a string instead of keyboard
        istringstream ss(line);
        string token;

        while (ss >> token) { // >> operator reads one word at a time while skipping whitespace
            tokens.push_back(token);
        }

        if (tokens.empty()) {
            continue;
        }

        // Process id from <unistd.h>
        // Creating a copy of the current process
        // fork() doesn't return child's pid itself.
        pid_t pid = fork();

        if (pid == 0) {
            cout << "Child's pid = " << getpid() << endl;

            vector<char*> args;

            for (auto& t: tokens) {
                args.push_back(t.data());
            }

            args.push_back(nullptr);
            execvp(args[0],args.data());
            perror("execvp");
            exit(1);
        } else {
            waitpid(pid, nullptr, 0);
        }
    }

}
