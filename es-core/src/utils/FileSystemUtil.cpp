#include "FileSystemUtil.h"

#include <iostream>
#include <stdlib.h>
#include <unistd.h>

namespace Utils
{
    namespace FileSystem {
        static std::string homePath = "";
        void setHomePath(const std::string& _path)
        {
            homePath = getGenericPath(_path);
        }

        std::string getHomePath()
        {
            // only construct the homepath once
            if (homePath.length()) {
                return homePath;
            }

            // check for HOME environment variable
            const char* envHome = getenv("HOME");
            if (envHome)
                homePath = getGenericPath(envHome);

            // no homepath found, fall back to cureent working directory
            if (!homePath.length())
                homePath = getCWDPath();
            
            return homePath;
        }

        std::string getCWDPath()
        {
            char temp[512];
            return (getcwd(temp, 512) ? getGenericPath(temp):"");
        }

        std::string getGenericPath(const std::string& _path)
        {
            std::string path = _path;
            size_t offset = std::string::npos;

            // convert '\\' to '/'
            while ((offset = path.find('\\')) != std::string::npos) {
                path.replace(offset, 1, "/");
            }

            // remove double '/'
            while ((offset = path.find("//")) != std::string::npos) {
                path.erase(offset, 1);
            }

            // remove trailing '/' when the path is more than a simple '/'
            while (path.length() > 1 && ((offset = path.find_last_of('/')) == (path.length() - 1))) {
                path.erase(offset, 1);
            }

            return path;
        }
    } // namespace FileSystem
} // namespace Utils

int main(int argc, char** argv)
{
    if(argv[1])
        std::cout << Utils::FileSystem::getGenericPath(argv[1]) << std::endl;
}