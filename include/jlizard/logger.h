/*
 * MIT License
 * 
 * Copyright (c) 2025 Salem Bouraoui
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES, OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * 
 */
 
#ifndef LOGGER_H
#define LOGGER_H

#include <ctime>
#include <iostream>
#include <string>

/**
 * @namespace jlizard::logger
 * @brief Provides simple logging functionality for the jlizard library
 */
namespace jlizard::logger
{
    /**
     * @enum LogLevel
     * @brief Defines logging severity levels
     */
    enum class LogLevel : unsigned char {
        NONE = 0, /**< No logging */
        DEBUG,    /**< Debug-level messages */
        INFO,     /**< Informational messages */
        WARNING,  /**< Warning messages */
        ERROR,    /**< Error messages */
        MAX       /**< Upper bound of log levels */
    };

    /**
     * @brief Log a message with the specified log level
     * 
     * This function outputs a log message to the appropriate stream (std::cout or std::cerr)
     * based on the log level. Error messages go to std::cerr, all others go to std::cout.
     * 
     * @param msg The message to log
     * @param log_level The severity level of the log message (default: INFO)
     */
    void log(const std::string& msg, const LogLevel log_level = LogLevel::INFO);
    
    /**
     * @brief Log an error message
     * 
     * Convenience function that logs a message with ERROR level.
     * Error messages are output to std::cerr.
     * 
     * @param msg The error message to log
     */
    inline void error(const std::string& msg) { log(msg, LogLevel::ERROR); }
    
    /**
     * @brief Log a warning message
     * 
     * Convenience function that logs a message with WARNING level.
     * Warning messages are output to std::cout.
     * 
     * @param msg The warning message to log
     */
    inline void warn(const std::string& msg) { log(msg, LogLevel::WARNING); }
    
    /**
     * @brief Log an informational message
     * 
     * Convenience function that logs a message with INFO level.
     * Info messages are output to std::cout.
     * 
     * @param msg The informational message to log
     */
    inline void info(const std::string& msg) { log(msg, LogLevel::INFO); }
}

#endif //LOGGER_H