
#ifdef DENEMELOADDLL_EXPORTS
#define DENEMELOADDLL_API __declspec(dllexport)

class Ince {
public:
	DENEMELOADDLL_API int __cdecl funcDll();
};



#else
#define DENEMELOADDLL_API __declspec(dllimport)

#endif

