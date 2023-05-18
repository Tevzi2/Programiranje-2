//
// Created by Tevz on 18/05/2023.
//

#include <Log.hpp>

Log::Log(LogType type, source_location s)
{
    f.open(file, std::ios::app);

    time_t tim = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    struct tm* t = std::localtime(&tim);
    char buffer[80];

    strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S", t);

    f << std::string{buffer}
        << " "
        << to_string(type)
        << " "
        << "["
        << s.function_name()
        << "#"
        << s.line()
        << "] ";
}

Log::~Log()
{
    if(f.is_open())
        f.close();
}