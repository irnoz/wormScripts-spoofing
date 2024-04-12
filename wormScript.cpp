#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <cstdlib>
#include <ctime>

namespace fs = std::filesystem;

int main() {
    int num_files;
    std::string output_dir = getenv("HOME"); // Get the home directory path
    output_dir += "/Desktop/binary_files";   // Append custom folder path

    std::cout << "Enter the number of files to create: ";
    std::cin >> num_files;

    // Create directory if it does not exist
    fs::create_directories(output_dir);

    // Seed the random number generator
    std::srand(std::time(nullptr));

    for (int i = 1; i <= num_files; i++) {
        std::ofstream file(output_dir + "/file_" + std::to_string(i) + ".txt");
        if (file.is_open()) {
            for (int j = 0; j < 100; j++) {
                std::string binary_string;
                for (int k = 0; k < 50; k++) {
                    binary_string += std::rand() % 2 ? '1' : '0';
                }
                file << binary_string << '\n';
            }
            file.close();
        }
    }

    std::cout << "Files created successfully on the desktop.\n";

    // Listing files
    std::cout << "Contents of " << output_dir << ":\n";
    for (const auto& entry : fs::directory_iterator(output_dir)) {
        std::cout << entry.path() << '\n';
    }

    // Ask if user wants to see the contents of the first file
    char view_files;
    std::cout << "Do you want to see the files created? (y/n): ";
    std::cin >> view_files;

    if (view_files == 'y' || view_files == 'Y') {
        std::ifstream file(output_dir + "/file_1.txt");
        if (file.is_open()) {
            std::string line;
            std::cout << "Contents of " << output_dir << "/file_1.txt:\n";
            while (std::getline(file, line)) {
                std::cout << line << '\n';
            }
            file.close();
        }
    }

    // Ask if user wants to delete the files
    char delete_files;
    std::cout << "Do you want to delete the created binary files? (y/n): ";
    std::cin >> delete_files;

    if (delete_files == 'y' || delete_files == 'Y') {
        fs::remove_all(output_dir);
        std::cout << "Files deleted successfully.\n";
    }

    return 0;
}

