#include <filesystem>
#include <string_view>
#include "funcs.hpp"

namespace fs = std::filesystem;

int main(int argc, char** argv) {
   if (argc >= 2) {
      for (int i = 1; i < argc; ++i) {
         if (fs::exists(argv[i]) && !fs::is_directory(argv[i]))
            imgToHeader(argv[i]);
         else
            error(std::string{argv[i]} + (fs::is_directory(argv[i]) ? " is a directory" : " does not exist"));
      }
   }
   else error("no file provided");
   return EXIT_SUCCESS;
}