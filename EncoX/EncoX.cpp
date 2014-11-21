// EncoX.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>

#include <EncoShared\EncoShared.h>
#include <EncoDesktop\EncoDesktop.h>

#pragma comment (lib, "EncoDesktop.lib")

using namespace enco;

int _tmain(int argc, _TCHAR* argv[])
{
	DesktopView *view = new DesktopView();

	view->setSize(Vector2ui(640, 480));

	view->create();

	while (true) {
		view->update(0);
	}

	view->destroy();

	delete view;

	return 0;
}

