#include<iostream>

class Log
{
public:
    enum Level
    {
        LogError = 0, LogWarning, LogInfo
    };

private:
    Level m_LogLevel = LogInfo;

public:
    void SetLevel(Level level)
    {
        m_LogLevel = level;
    }

    void Error(const char* message)
    {
        if (m_LogLevel >= LogError)
            std::cout << "[ERROR]: " << message << std::endl;
    }

    void Warn(const char* message)
    {
        if (m_LogLevel >= LogWarning)
            std::cout << "[WARNING]: " << message << std::endl;
    }

    void Info(const char* message)
    {
        if (m_LogLevel >= LogInfo)
            std::cout << "[INFO]: " << message << std::endl;
    }

};

int main()
{
    Log log;
    log.SetLevel(Log::LogWarning);
    log.Warn("You have been warned!");
    log.Error("Error is found!!");
    std::cin.get();
}