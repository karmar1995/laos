#pragma once
#include <memory>

class PerfyUi {
public:
    PerfyUi(char** argv, int argc);
    void start();
private:
    struct Impl;
    std::unique_ptr<Impl> m_pImpl;

};