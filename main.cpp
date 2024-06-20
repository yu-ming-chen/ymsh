#include <iostream>
#include <sstream>
#include <vector>

void ymsh_split_line(std::string& line, std::vector<std::string>& args) {
    std::stringstream ss(line);
    std::string arg;
    while (ss >> arg) {
        args.emplace_back(arg);
    }
}

void ymsh_loop() {
  std::string line;
  int status;

  do {
    std::cout << "> ";
    getline(std::cin, line);
    
    std::vector<std::string> args;
    ymsh_split_line(line, args);

    for(auto& w : args) {
        std::cout << w << std::endl;
    }
    // status = lsh_execute(args);
    status = true;
  } while (status);
}


int main(int argc, char *argv[]) {
  // Load config files, if any.

  // Run command loop.
  ymsh_loop();

  // Perform any shutdown/cleanup.
  return EXIT_SUCCESS;
}