#include <iostream>
#include <tchar.h>
#include<io.h>
#include<string>
#include<iostream>
#include<vector>
#include "example_win32_directx12_0727/vfs.h"
#include "Rendering/D3D_sources_code.h"

//---------------------------------------在这里生成了虚拟的文件夹root--------------------
//const char* filePath2 = "C:\\Users\\zhao_\\Pictures\\imgui-master";
const char* filePath2 = "pics";
const char* filePath3 = "res";



int VfsSys()
{
    cout << "Welcome to Virtual File System" << endl << endl;
    vfs File;
    //char* aa;
    File.s_ShowDir("root");
    //aa = File.i_ShowDir("root");
    cout << "Enter help for more info." << endl << endl;
  
    vector<string> files2;

    //获取该路径下的所有文件  
    getFiles(filePath2, files2);
    //char str[30];//
    int size2 = files2.size();


     //int count2 = 1;
    // cout << size2 << endl;
    

    for (int i = 0; i < 5; i++)
        //   if (filter.PassFilter(files2[i].c_str()))
         //      ImGui::BulletText("%s", files2[i].c_str());
    {
        cout << files2[i] << endl;      
        File.s_LoadFile((char*)files2[i].c_str());
    }
    // File.s_LoadFile(files2.c_str());
    vector<string> files3;

    //获取该路径下的所有文件  
    getFiles(filePath3, files3);
    //char str[30];//
    int size3 = files3.size();


    //int count2 = 1;
   // cout << size2 << endl;


    for (int i = 0; i < 2; i++)
        //   if (filter.PassFilter(files2[i].c_str()))
         //      ImGui::BulletText("%s", files2[i].c_str());
    {
        cout << files3[i] << endl;
        File.s_LoadFile((char*)files3[i].c_str());
    }
    // File.s_LoadFile(files2.c_str());
    char* pp=NULL;
    //size_t yy = 0;
   // yy++;
    pp = File.dir(1,3);



    return 0;
}

