#include <unistd.h>
#include <sys/wait.h>
#include <vector>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

// A fully functional shell that supports:
// $ ls -la
// $ cd /tmp
// $ exit
// $ ls > out.txt
// $ cat < out.txt
// $ ls | grep .cpp

// Option in system level = additional settings passed to a program
// ls        → just list files
// ls -l     → list with details
// ls -la    → list with details + hidden files
// ls -la /home → list /home directory

// Preventing the shell from dying when running a command
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

        if (tokens[0] == "exit") {
            exit(0);
        }

        if (tokens[0] == "cd") {
            if (tokens.size() < 2) { // 'cd' expects a specific destination like 'cd /something'
                // error message output stream
                cerr << "cd: too few arguments\n";
            } else {
                // Changing current directory of the shell process
                // chdir("/something") -> shell's current directory becomes /something
                // c_str(): converting string to const char* since chdir() requires 'const char*'
                chdir(tokens[1].c_str());
            }

            continue;
        }

        // Process id from <unistd.h>
        // Creating a copy of the current process
        // fork() doesn't return child's pid itself.
        pid_t pid = fork();

        if (pid == 0) {
            // cout << "Child pid = " << getpid() << endl;

            vector<char*> args;

            for (auto& t: tokens) {
                args.push_back(const_cast<char*>(t.data()));
            }

            // To make args = ["ls", "-la", nullptr] and inform of end for execvp.
            args.push_back(nullptr);

            // execvp(char*, char**) -> Replacing the current process(shell code copy) with another program(ls, ls -la) and run it.
            execvp(args[0],args.data()); // The address of first element in args(vector)
            perror("execvp");
            exit(1); // Forcing terminate the child process.
        } else {
            waitpid(pid, nullptr, 0);
        }
    }
}
