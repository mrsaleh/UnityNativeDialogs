// HosseinDialogsNativeDLL.cpp : Defines the exported functions for the DLL application.
//

// NativeDialogs.cpp : Defines the exported functions for the DLL application.
//


#include "NativeDialogs.h"



using namespace std;


HWND __stdcall HosseinFindProcessWindow(DWORD pid)
{	
	std::pair<HWND, DWORD> params = { 0, pid };

	// Enumerate the windows using a lambda to process each window
	BOOL bResult = EnumWindows([](HWND hwnd, LPARAM lParam) -> BOOL
	{
		auto pParams = (std::pair<HWND, DWORD>*)(lParam);

		DWORD processId;
		if (GetWindowThreadProcessId(hwnd, &processId) && processId == pParams->second)
		{
			// Stop enumerating
			SetLastError(-1);
			pParams->first = hwnd;
			return FALSE;
		}

		// Continue enumerating
		return TRUE;
	}, (LPARAM)&params);

	if (!bResult && GetLastError() == -1 && params.first)
	{
		return params.first;
	}

	return 0;
}

DWORD __stdcall HosseinFindCurrentProcessId() {
	return GetCurrentProcessId();
}

void __stdcall HosseinRestoreWindow(HWND _hwnd) {
	ShowWindow(_hwnd, SW_RESTORE);
}

void __stdcall HosseinShowWindow(HWND _hwnd) {
	ShowWindow(_hwnd, SW_SHOW);
}

// This is an example of an exported function.
LPWSTR __stdcall HosseinOpenFile(HWND _parentHandle)
{
	//COINIT_DISABLE_OLE1DDE | COINIT_APARTMENTTHREADED
	/*
	HRESULT hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);	
	if (FAILED(hr)) {
		cout << "CoInitializeEx failed!" << endl;
		return 1;
	}
	*/	
	IFileOpenDialog *pFileOpen = NULL;

	// Create the FileOpenDialog object.
	HRESULT  hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL,
		IID_IFileOpenDialog, reinterpret_cast<void**>(&pFileOpen));

	if (FAILED(hr)) {
		cout << "CoCreateInstance Failed!" << endl;
		return NULL;
	}

	// Show the Open dialog box.
	hr = pFileOpen->Show(_parentHandle);

	// Get the file name from the dialog box.
	if (FAILED(hr)) {
		cout << "Dialog show method failed" << endl;
		return NULL;		
	}


	IShellItem *pItem;
	hr = pFileOpen->GetResult(&pItem);
	if (FAILED(hr)) {
		cout << "Dialog get result method failed!" << endl;
		return NULL;		
	}

	LPWSTR szFilename;

	hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &szFilename);

	// Display the file name to the user.
	if (FAILED(hr)) {
		cout << "Dialog get display name failed!" << endl;
		return NULL;
	}

	pItem->Release();


	pFileOpen->Release();

	//CoUninitialize();

	return szFilename;
}

