#include "./imgui/imgui.h"
#include "./Rendering/imgui_impl_win32.h"
#include "./Rendering/imgui_impl_dx12.h"
#include "./Rendering/D3D_sources_code.h"
#include "PlatformDisplayWindow.h"
#include <d3d12.h>
#include <dxgi1_4.h>
#include <tchar.h>
#include<io.h>
#include<string>
//#include "GuiTool.h"
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




int PlatformDisplayWindow::WindowSet(HWND& hwnd, WNDCLASSEX& wc)
{
    //Windows Language
    wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, _T("ImGui Example"), NULL };
    ::RegisterClassEx(&wc);
    hwnd = ::CreateWindow(wc.lpszClassName, _T("Dear ImGui DirectX12 Example"), WS_OVERLAPPEDWINDOW, 100, 100, 1280, 800, NULL, NULL, wc.hInstance, NULL);
    if (!CreateDeviceD3D(hwnd))
    {
        CleanupDeviceD3D();
        ::UnregisterClass(wc.lpszClassName, wc.hInstance);
        return 1;
    }
    //----------------------------------------------END-------------------------------------------------------
    // Show the window
    ::ShowWindow(hwnd, SW_SHOWDEFAULT);
    ::UpdateWindow(hwnd);
    IMGUI_CHECKVERSION();//In the file "imgui.h"
    //Use this before use ImGui
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    initalD3D(hwnd);
    // return 0;
}

int PlatformDisplayWindow::WindowEnd(HWND& hwnd, WNDCLASSEX& wc)
{
    CleanupDeviceD3D();
    ::DestroyWindow(hwnd);
    ::UnregisterClass(wc.lpszClassName, wc.hInstance);
    // Create application window
    return 0;
}
