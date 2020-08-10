#include "./imgui/imgui.h"
#include "./Rendering/imgui_impl_win32.h"
#include "./Rendering/imgui_impl_dx12.h"
#include "./Rendering/D3D_sources_code.h"
#include "gui/GuiTool.h"
#include "MyGuiStructure.h"
#include <d3d12.h>
#include <dxgi1_4.h>
#include <tchar.h>
#include<io.h>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

#ifdef _DEBUG
#define DX12_ENABLE_DEBUG_LAYER
#endif

#ifdef DX12_ENABLE_DEBUG_LAYER
#include <dxgidebug.h>
#pragma comment(lib, "dxguid.lib")
#endif


void getFiles(string path, vector<string>& files);
const char* filePath = "pics";
const char* filePathtxt = "output_file.txt";
//const char* filePath2 = "C:\\Users\\zhao_\\Pictures\\imgui-master";
int MyGuiStructure::myGuiSet()
{
    show_demo_window = true;
    show_another_window = false;
    clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    my_image_width = 0;
    my_image_height = 0;
    return 0;
}

int MyGuiStructure::myGuiStructure()
{

    ImGui_ImplDX12_NewFrame();
    ImGui_ImplWin32_NewFrame();
    show_demo_window = true;
    show_another_window = false;
    ImGui::NewFrame();
    // 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
    {
        static float f = 0.0f;
        static int counter = 0;

        ImGui::Begin("My Demo GUI");                          // Create a window called "Hello, world!" and append into it.

        ImGui::Text("My Resource Management.");               // Display some text (you can use a format strings too)
        ImGui::Checkbox("Materials", &show_demo_window);      // Edit bools storing our window open/close state
        ImGui::Checkbox("Files", &show_another_window);
        if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
            counter++;
        ImGui::SameLine();
        ImGui::Text("counter = %d", counter);

        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::End();
    }
    // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
    if (show_demo_window)
        //   ImGui::ShowDemoWindow(&show_demo_window);
    {
        //ImGui::Begin("MAT Management", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
        ImGui::Begin("MAT Management");
        ImGui::Text("Here is MAT");

        if (!ImGui::CollapsingHeader("Pics"))
        {
            vector<string> files;

            getFiles(filePath, files);
            char str[30];//
            int size = files.size();
            int count = 1;
            for (int i = 0; i < size; i++)
            {
                if (ImGui::TreeNode(files[i].c_str()))
                {
                    static bool no_titlebar = false;
                    static bool no_resize = false;
                    static bool no_scrollbar = false;
                    ImGuiWindowFlags window_flags = 0;
                    if (no_titlebar)        window_flags |= ImGuiWindowFlags_NoTitleBar;
                    if (no_resize)          window_flags |= ImGuiWindowFlags_NoResize;
                    if (no_scrollbar)       window_flags |= ImGuiWindowFlags_NoScrollbar;

                    ImGuiIO& io = ImGui::GetIO();
                    ImGui::SetNextWindowBgAlpha(0);
                    ImGui::Checkbox("No titlebar", &no_titlebar);
                    ImGui::Checkbox("No resize", &no_resize);
                    ImGui::Checkbox("No sc", &no_scrollbar);
                    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
                    ImGui::Begin(files[i].c_str(), NULL, window_flags);
                    ImVec2 size = ImGui::GetWindowSize();



                    //int descriptor_index = count; // The descriptor table index to use (not normally a hard-coded constant, but in this case we'll assume we have slot 1 reserved for us)
                    //D3D12_CPU_DESCRIPTOR_HANDLE my_texture_srv_cpu_handle = g_pd3dSrvDescHeap->GetCPUDescriptorHandleForHeapStart();
                    //my_texture_srv_cpu_handle.ptr += (handle_increment * descriptor_index);
                    //D3D12_GPU_DESCRIPTOR_HANDLE my_texture_srv_gpu_handle = g_pd3dSrvDescHeap->GetGPUDescriptorHandleForHeapStart();
                    //my_texture_srv_gpu_handle.ptr += (handle_increment * descriptor_index);
                 //   int count = 0;
                 //   D3D12_CPU_DESCRIPTOR_HANDLE my_texture_srv_cpu_handle = feedimg(count);
                 //   bool ret = LoadTextureFromFile(files[i].c_str(), g_pd3dDevice, my_texture_srv_cpu_handle, &my_texture, &my_image_width, &my_image_height);
                 //   IM_ASSERT(ret);

                   // count++;

                   // bool ret = LoadTextureFromFile(files[i].c_str(), g_pd3dDevice, my_texture_srv_cpu_handle, &my_texture, &my_image_width, &my_image_height);
                 //   IM_ASSERT(ret);


                   // ImGui::Image((ImTextureID)my_texture_srv_gpu_handle.ptr, ImVec2((float)size.x, (float)size.y));
                    ImGui::End();
                    ImGui::PopStyleVar();
                    ImGui::TreePop();
                }

            }

        }
        if (!ImGui::CollapsingHeader("Search"))
        {
            
            static ImGuiTextFilter filter;
            ImGui::Text("Files usage:\n"
                "  \"\"         display all lines\n"
                "  \"xxx\"      display lines containing \"xxx\"\n"
                "  \"xxx,yyy\"  display lines containing \"xxx\" or \"yyy\"\n"
                "  \"-xxx\"     hide lines containing \"xxx\"");
            filter.Draw();
            //
           vector<string> files;
          // ImGui::BulletText("charr");
           // getfilesfun(filePathtxt, files3);
           // int size2 = files3.size();
            //int count2 = 1;
           // cout << size2 << endl;
           // vector<string> files;
            //string filestemp;
           // for (int j = 1; j < 3; j++)
           // {
              //  files3[j] = ReadLine("output_file.txt", j);
            //}
                     
           // getFiles(filePath, files);                    
           //ImGui::BulletText("%s", Path1);
           
          //  for (int i = 0; i < IM_ARRAYSIZE(files[i].c_str()); i++)
          //      if (filter.PassFilter(files[i].c_str()))
          //          ImGui::BulletText("%s", files[i].c_str());
           string filestemp;
         //  filestemp = ReadLine("output_file.txt", 1);
           
           
           for (int i = 0; i < 7; i++)
                     if (i<7)
                         ImGui::BulletText(ReadLine("output_file.txt", i).c_str());
        
        }

        ImGui::End();
    }
    // 3. Show another simple window.
    if (show_another_window)
    {
        ImGui::Begin("My Files Management", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
       // ImGui::Text("Hello from another window!");
        //--------------------------------------------
        if (ImGui::CollapsingHeader("files"))
        {
            // Helper class to easy setup a text filter.
            // You may want to implement a more feature-full filtering scheme in your own application.
            static ImGuiTextFilter filter;
            ImGui::Text("Files usage:\n"
                "  \"\"         display all lines\n"
                "  \"xxx\"      display lines containing \"xxx\"\n"
                "  \"xxx,yyy\"  display lines containing \"xxx\" or \"yyy\"\n"
                "  \"-xxx\"     hide lines containing \"xxx\"");
            filter.Draw();
            //
           // vector<string> files2;

            //获取该路径下的所有文件  
           // getFiles(filePath2, files2);
            //char str2[30];//
            //int size2 = files2.size();


            // int count2 = 1;
            // cout << size2 << endl;

          //  for (int i = 0; i < IM_ARRAYSIZE(files2[i].c_str()); i++)
        //        if (filter.PassFilter(files2[i].c_str()))
         //           ImGui::BulletText("%s", files2[i].c_str());
        }

        ImGui::End();
    }
    return 0;
}

int MyGuiStructure::myGuiEnd()
{
    WaitForLastSubmittedFrame();
    ImGui_ImplDX12_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();
    return 0;
}
