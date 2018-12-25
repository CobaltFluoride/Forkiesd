#include "include/app.h"

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

int main(int argc, char **argv)
{
	// Set scheme to gtk+ and start setup utility.

	Fl::scheme("gtk+");
	SetupUI sui{100,100,360,400,"Forkies'd Setup"};

	return 0;
}
