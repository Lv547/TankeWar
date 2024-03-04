// TankWarConsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Controller.h"
#include "ConsoleView.h"
#include "ModelA.h"


int _tmain(int argc, _TCHAR* argv[])
{
   Controller *game = new Controller(new ConsoleView(),new ModelA());
	game->Go();
    return 0;
}

