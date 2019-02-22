
#include "stdafx.h"
#include <windows.h>
#include<iostream>
#include "DenemeLoadDLL.h"

extern "C" 
{
	// This is an example of an exported function.
	DENEMELOADDLL_API int __cdecl funcDll()
	{
		// Get Computer NETBIOS Name
		TCHAR  pszComputerNameBilgi[MAX_PATH];
		DWORD  dwbufComputerNameCount = MAX_PATH;

		if (GetComputerName(pszComputerNameBilgi, &dwbufComputerNameCount))
		{
			wprintf(L"\Computer Name : %s\n", pszComputerNameBilgi);
			return 1;
		}
		return 0;

	}
}

