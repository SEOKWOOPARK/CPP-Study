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
        istringstream ss(line);
        string token;

        while (ss >> token) {
            tokens.push_back(token);
        }

        if (tokens.empty()) {
            continue;
        }

        pid_t pid = fork();

        if (pid == 0) {
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
