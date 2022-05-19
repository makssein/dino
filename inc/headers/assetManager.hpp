#pragma once
#include <unordered_map>
#include <string>

template<typename T>
class assetManager {
public:
    void load(const std::string& name, const std::string& path) {
        m_assets[name].loadFromFile(path);
    }
    T& get(const std::string& name) {
        return m_assets[name];
    }
private:
    std::unordered_map<std::string, T> m_assets;
};