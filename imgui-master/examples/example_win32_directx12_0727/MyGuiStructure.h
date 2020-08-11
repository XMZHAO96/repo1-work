#pragma once
#include "./imgui/imgui.h"
#include "./Rendering/imgui_impl_win32.h"
#include "./Rendering/imgui_impl_dx12.h"
#include "./Rendering/D3D_sources_code.h"
#include "gui/GuiTool.h"
#include <d3d12.h>
#include <dxgi1_4.h>
#include <tchar.h>
#include<io.h>
#include<string>
#include<iostream>
#include<vector>
using namespace std;
//------------------------------------------ÉùÃ÷---------------------------------------------
#ifdef _DEBUG
#define DX12_ENABLE_DEBUG_LAYER
#endif

#ifdef DX12_ENABLE_DEBUG_LAYER
#include <dxgidebug.h>
#pragma comment(lib, "dxguid.lib")
#endif


bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
void CreateRenderTarget();
void CleanupRenderTarget();
void WaitForLastSubmittedFrame();
FrameContext* WaitForNextFrameResources();
void ResizeSwapChain(HWND hWnd, int width, int height);
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);



class MyGuiStructure
{
public:
    int myGuiSet();
    int myGuiStructure();
    int myGuiEnd();
    bool show_demo_window;
    bool show_another_window;
    ImVec4 clear_color;
    int my_image_width;
    int my_image_height;
    
    //int Boot(HWND& hwnd, WNDCLASSEX& wc);
   // int End(HWND& hwnd, WNDCLASSEX& wc);
};
