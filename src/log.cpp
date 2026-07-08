#include "log.h"

#include <print>
#include <chrono>
#include <format>

const std::string ANSI_COLOR_RESET = "\033[0m";
const std::string ANSI_COLOR_BRIGHT_GREEN = "\033[92m";
const std::string ANSI_COLOR_BRIGHT_RED  = "\033[91m";
const std::string ANSI_COLOR_RED = "\033[31m";

void print_message(const std::string & color, const std::string & level, const std::string & message)
{
    auto now = std::chrono::system_clock::now();
    auto truncated_now = std::chrono::floor<std::chrono::seconds>(now);
    auto local_time = std::chrono::zoned_time{std::chrono::current_zone(), truncated_now};

    std::string timestamp = std::format("{:%Y-%m-%d %H:%M:%S}", local_time);
    std::println("{} {} {:<10} {}{}", color, timestamp, level, message, ANSI_COLOR_RESET);
}

void log_info(std::string msg)
{
    print_message(ANSI_COLOR_BRIGHT_GREEN, "[INFO]" ,msg);
}

void log_error(std::string msg)
{
    print_message(ANSI_COLOR_BRIGHT_RED, "[ERROR]" ,msg);
}

void log_critical(std::string msg)
{
    print_message(ANSI_COLOR_RED, "[CRITICAL]" ,msg);
}