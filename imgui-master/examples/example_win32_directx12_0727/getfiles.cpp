#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include<io.h>
#include<string>
#include<iostream>
#include<vector>
#include "Rendering/D3D_sources_code.h"
#include "./imgui/imgui.h"
#include "./Rendering/imgui_impl_win32.h"
#include "./Rendering/imgui_impl_dx12.h"

#include <d3d12.h>
#include <dxgi1_4.h>
#include <tchar.h>
#include<io.h>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

void getfilesfun(string path, vector<string>& files)
{
   // string path = "output_file.txt";
   

    ifstream in(path.c_str());   
    if (!in.is_open())
    {
        cerr << "open file failed!" << endl;
        exit(-1);
    }   
    string s = "";
    while (getline(in, s))
    {
        //cout << s << endl;
        files.push_back(s);
    }

    cout << files[0] << endl;
    in.close();
   

  
}

string ReadLine(char* filename, int line)
{
    int i = 0;
    string temp;
    fstream file;
    file.open(filename, ios::in);

    if (line <= 0)
    {
        return "Error 1: 行数错误，不能为0或负数。";
    }

    if (file.fail())
    {
        return "Error 2: 文件不存在。";
    }

    while (getline(file, temp) && i < line - 1)
    {
        i++;
    }

    file.close();
    return temp;
}

