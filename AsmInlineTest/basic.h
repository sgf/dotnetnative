#pragma once
#include "windows.h"

class CBasicApp {
public:

	BOOL		bStart;
	BOOL		bInitialize;
	BOOL HS_InitializeService();
	BOOL HS_StartService();

};
