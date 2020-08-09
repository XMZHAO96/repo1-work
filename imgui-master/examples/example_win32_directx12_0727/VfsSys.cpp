#include <iostream>
#include <tchar.h>
#include<io.h>
#include<string>
#include<iostream>
#include<vector>
#include "example_win32_directx12_0727/vfs.h"
#include "Rendering/D3D_sources_code.h"

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
    

    for (int i = 0; i < 10; i++)
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
  
    while (1)
    {
        cout << "cmd: ";
        char command[60] = "";
        gets_s(command);
        if (strcmp(command, "") == 0)
            continue;
        if (strcmp(command, "exit") == 0)
        {
            cout << "Exit virtual file system\n";
            return 0;
        }
        if (strcmp(command, "test") == 0)
        {
            //cout << aa ;
           // return 0;
        }
        File.s_Command(command);
    }
    return 0;
}
