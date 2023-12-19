#pragma once
#include <string>

class Logger
{

public:
	void info(const std::string& message);
	void warning(const std::string& message);
	void severe(const std::string& message);
	void fatal(const std::string& message);
	Logger(const std::string& path);
	~Logger();

private:
	std::string path;
	enum class Level {INFO, WARNING, SEVERE, FATAL};
	void recordLog(std::string level, const std::string& message);
	std::string getLevel(const Level& level);
	std::string currentDateTime();
};
