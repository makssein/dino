#include <save.hpp>

float saveFile::load(const std::string path) {
    s_file.open(path, std::ios::in);

    if (!s_file.good()) {
        s_file.close();
        return -1;
    }
    float value = 0;

    s_file >> value;

    s_file.close();

    return value;
}

void saveFile::save(const std::string path, const std::string value) {
    s_file.open(path, std::ios::out);

    s_file << value << '\n';

    s_file.close();
}

std::fstream saveFile::s_file;