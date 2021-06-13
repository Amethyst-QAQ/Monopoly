#include "GameLogic.h"
#include <string>
#include <cstdlib>
#include <time.h>
#include <Windows.h>
#include <io.h>
#include <iostream>s

#define DLL_PATH "./dlls"

bool isServer = false;

void getFiles(std::string path, std::vector<std::string>& files)
{
    //文件句柄
    long   hFile = 0;
    //文件信息
    struct _finddata_t fileinfo;
    std::string p;
    if ((hFile = _findfirst(p.assign(path).append("/*").c_str(), &fileinfo)) != -1)
    {
        do
        {
            //如果是目录,迭代之
            //如果不是,加入列表
            if ((fileinfo.attrib & _A_SUBDIR))
            {
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
                    getFiles(p.assign(path).append("/").append(fileinfo.name), files);
            }
            else
            {
                files.push_back(p.assign(path).append("/").append(fileinfo.name));
            }
        } while (_findnext(hFile, &fileinfo) == 0);
        _findclose(hFile);
    }
}

LPCWSTR stringToLPCWSTR(std::string orig)
{
    wchar_t* wcstring = 0;
    try
    {
        size_t origsize = orig.length() + 1;
        const size_t newsize = 100;
        size_t convertedChars = 0;
        if (orig == "")
        {
            wcstring = (wchar_t*)malloc(0);
            mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);
        }
        else
        {
            wcstring = (wchar_t*)malloc(sizeof(wchar_t) * (orig.length() - 1));
            mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);
        }
    }
    catch (std::exception e)
    {
    }
    return wcstring;
}

inline bool isDll(std::string fileName)
{
    int len = fileName.length();
    return
        fileName[len - 4] == '.' &&
        fileName[len - 3] == 'd' &&
        fileName[len - 2] == 'l' &&
        fileName[len - 1] == 'l';
}

int main(int argc, char **argv)
{
	srand(time(NULL));
	std::srand(time(NULL));


	std::vector<std::string> files;
	getFiles(DLL_PATH, files);

    std::vector<HMODULE> libs;

    for (auto i : files)
    {
        if (isDll(i))
        {
            HMODULE temp = LoadLibrary(stringToLPCWSTR(i));
            libs.push_back(temp);
        }
    }

	if (argc == 2 && argv[1] == std::string("server"))
		isServer = true;
	GameLogic logic;
	GameLogic::instance = &logic;
	logic.startGame();
	while (logic.round());

    for (auto i : libs)
    {
        FreeLibrary(i);
    }

	logic.cleanup();
	return 0;
}