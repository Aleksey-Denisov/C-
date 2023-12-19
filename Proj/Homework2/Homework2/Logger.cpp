#define _CRT_SECURE_NO_WARNINGS
#include "Logger.h"
#include <iostream>
#include <fstream>
#include <ctime>

Logger::Logger(const std::string& path)
{
	this->path = path;
}

Logger::~Logger()
{
	//Освобождение ресурса при завершении использования
}

void Logger::info(const std::string& message)
{
	recordLog(getLevel(Level::INFO), message);
}

void Logger::warning(const std::string& message)
{
	recordLog(getLevel(Level::WARNING), message);
}

void Logger::severe(const std::string& message)
{
	recordLog(getLevel(Level::SEVERE), message);
}

void Logger::fatal(const std::string& message)
{
	recordLog(getLevel(Level::FATAL), message);
}

void Logger::recordLog(std::string level, const std::string& message)
{
	std::ofstream logFile;
	logFile.open(path, std::ios::app);
	if (logFile.is_open())
	{
		logFile << currentDateTime() << "	" << level << "	" << message << std::endl;
	}
	logFile.close();
}

std::string Logger::getLevel(const Level& level)
{
	switch (level)
	{
	case Level::INFO:
		return "INFO";
	case Level::WARNING:
		return "WARNING";
	case Level::SEVERE:
		return "SEVERE";
	case Level::FATAL:
		return "FATAL";
	default:
		break;
	}
	return "";
}

std::string Logger::currentDateTime()
{
	time_t rawtime = std::time(0);
	struct tm* timeinfo = localtime(&rawtime);
	char buffer[80];
	strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
	return buffer;
}
