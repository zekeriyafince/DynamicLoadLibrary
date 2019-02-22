#include <windows.h>
#include <iostream>

// DLL icindeki kullanýlacak fonksiyon icin tanýmlama yapýlmasý
// Bu yapý sayesinde DLL icindeki fonksiyonun adres degeri 
// tutularak bununla islem yapýlýr
// -> Defining the Function in DLL
using MYDLL = int(__cdecl *)();

int main()
{
	// DLL Loading
	HINSTANCE hInstLib = LoadLibrary(L"DENEMELOADDLL.dll");
	// Function pointer variable
	MYDLL myDLL;
	
	// Not found DLL
	if (!hInstLib) {
		std::cout << "DLL dosyasi yok!" << std::endl;
		return EXIT_FAILURE;
	}

	// Search function name in DLL
	myDLL = (MYDLL)GetProcAddress(hInstLib, "funcDll");
	if (!myDLL) {
		std::cout << "DLL icinde fonksiyon bulunamadi !" << std::endl;
		return EXIT_FAILURE;
	}
	// Function Lading
	if (myDLL()) {
		// Successful
		std::cout << "DLL icinde fonksiyon calisti." << std::endl;
	}
	else {
		//Error
		std::cout << "HATA: " << GetLastError() << std::endl;
	}
	

	return EXIT_SUCCESS;
}