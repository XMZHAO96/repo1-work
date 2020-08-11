#include "./imgui/imgui.h"
#include "./Rendering/imgui_impl_win32.h"
#include "./Rendering/imgui_impl_dx12.h"
#include "./Rendering/D3D_sources_code.h"
#include "./gui/GuiTool.h"
#include "examples/example_win32_directx12_0727/PlatformDisplayWindow.h"
#include "example_win32_directx12_0727/MyGuiStructure.h"
#include "example_win32_directx12_0727/VfsSys.h"
#include "example_win32_directx12_0727/vfs.h"
#include "example_win32_directx12_0727/makefile.h"
#include <d3d12.h>
#include <dxgi1_4.h>
#include <tchar.h>
#include<io.h>
#include<string>
#include<iostream>
#include<vector>
using namespace std;




int main(int, char**)

{

   //-----------------------------------构建虚拟文件夹-----------------------------------------
   // VfsSys();
   //----------------------------------------end-----------------------------------------------
  
    PlatformDisplayWindow* window = new PlatformDisplayWindow();
    window->WindowSet(window->hwnd, window->wc);
    MyGuiStructure* gui = new MyGuiStructure();
    GuiTool* tool = new GuiTool();

    gui->myGuiSet();
    while (1)
    {
        tool->myGui();
    }
    

    gui->myGuiEnd();
    window->WindowEnd(window->hwnd, window->wc);
}

