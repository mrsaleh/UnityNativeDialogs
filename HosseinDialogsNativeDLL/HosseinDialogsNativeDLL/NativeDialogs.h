#pragma once

#include <Windows.h>
#include <shobjidl.h> 
#include <iostream>

extern "C" __declspec(dllexport) HWND __stdcall HosseinFindProcessWindow(DWORD pid);
extern "C" __declspec(dllexport) DWORD __stdcall HosseinFindCurrentProcessId();
extern "C" __declspec(dllexport) void __stdcall HosseinRestoreWindow(HWND _hwnd);
extern "C" __declspec(dllexport) void __stdcall HosseinShowWindow(HWND _hwnd);
extern "C" __declspec(dllexport)  LPWSTR __stdcall HosseinOpenFile(HWND _parentHandle);

