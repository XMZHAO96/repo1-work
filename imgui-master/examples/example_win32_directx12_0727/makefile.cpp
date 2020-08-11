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
#include "makefile.h"
using namespace std;

//----------------------------------把虚拟文件夹解析后的信息存入文件---------------------
vector<string> makefile()
{
    vector<string> filestxt;
    for (int i = 0; i < 7; i++)
    {
        filestxt[i] = ReadLine("output_file.txt", i);
    }
    return filestxt;
}
