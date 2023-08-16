#pragma once
#ifndef ES_CORE_UTILS_FILE_SYSTEM_UTIL_H
#define ES_CORE_UTILS_FILE_SYSTEM_UTIL_H

#include <list>
#include <string>

namespace Utils
{
    namespace FileSystem {
        typedef std::list<std::string> stringList;
        
        void setHomePath(const std::string& _path);
        std::string getCWDPath();
        std::string getGenericPath(const std::string& _path);
    } // namespace FileSystem
} // namespace Utils


#endif // ES_CORE_UTILS_FILE_SYSTEM_UTIL_H
