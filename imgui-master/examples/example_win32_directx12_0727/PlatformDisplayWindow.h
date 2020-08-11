#pragma once
#include "./imgui/imgui.h"
#include "./Rendering/imgui_impl_win32.h"
#include "./Rendering/imgui_impl_dx12.h"
#include "./Rendering/D3D_sources_code.h"
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

//---------------------------------------------ÉùÃ÷---------------------------------------
class PlatformDisplayWindow
{
public:
    int WindowSet(HWND& hwnd, WNDCLASSEX& wc);
    //int Boot(HWND& hwnd, WNDCLASSEX& wc);
   // int End(HWND& hwnd, WNDCLASSEX& wc);
    int WindowEnd(HWND& hwnd, WNDCLASSEX& wc);
    HWND hwnd;
    WNDCLASSEX wc;
};
