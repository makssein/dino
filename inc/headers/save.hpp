#pragma once
#include "myHeaders.h"

class saveFile {
public:
    static float load(const std::string path);
    static void save(const std::string path, const std::string value);
private:

    static std::fstream s_file;
};