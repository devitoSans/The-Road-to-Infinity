#include <iostream>
#include <filesystem>
#include <string>

std::string goToParentPath(std::string path, int how_many = 1) {
    int index = path.length() - 1;
    // char(92) = '\'
    while(index >= 0 && path[index] != char(92) && path[index] != '/') {
        path.pop_back();
        index--;
    }
    return path;
}

std::string addPath(std::string a, std::string b) {
    std::filesystem::path dir(a);
    std::filesystem::path file(b);
    std::filesystem::path full_path = dir / file;
    return full_path.string();
}

std::string getRootPath() {
    std::filesystem::path cwd = std::filesystem::current_path();
    return cwd.string();
}

signed main() {
    std::string path = getRootPath();
    std::string parent_path = goToParentPath(path);
    std::cout << parent_path;
    std::string file = "hehe.txt";
    std::cout << addPath(parent_path, file);
}