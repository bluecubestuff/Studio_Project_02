
#include "Application.h"
#include "DetectMemoryLeak.h"

int main( void )
{
	Application app;
	app.Init();
	app.Run();
	app.Exit();
	_CrtDumpMemoryLeaks();
}