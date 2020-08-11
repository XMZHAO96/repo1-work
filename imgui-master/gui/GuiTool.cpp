#include "./imgui/imgui.h"
#include "./Rendering/imgui_impl_win32.h"
#include "./Rendering/imgui_impl_dx12.h"
#include "./Rendering/D3D_sources_code.h"
#include "GuiTool.h"
#include "example_win32_directx12_0727/MyGuiStructure.h"
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
//----------------------------------这个函数是imgui的整体框架的调用--------------------------------
int GuiTool::myGui()
{

    // Main loop
    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    while (msg.message != WM_QUIT)
    {
        if (::PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            continue;
        }

        // Start the Dear ImGui frame
        MyGuiStructure* p_Gui = new  MyGuiStructure();
        p_Gui->myGuiStructure();

        testD3D(clear_color);
    }



    return 0;

}
