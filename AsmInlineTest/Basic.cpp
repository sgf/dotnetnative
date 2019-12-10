﻿#include "basic.h"
#include "DxGlobalStage.h"
#include <assert.h>
#include "HShield.h"
#include "HSUpChk.h"
#pragma comment(lib,"HShield.lib")
#pragma comment(lib,"HSUpChk.lib")


//declare this fucking codes!
//find DO_RTC_CATCH _rtc_catch;
//add this below.

// msgbox title 
TCHAR szTitle[500] = ("HackShield");
// paths
TCHAR	g_szHShieldPath[MAX_PATH] = { 0, };
TCHAR	g_szIniPath[MAX_PATH] = { 0, };

//then..
//find
CBasicApp::CBasicApp() :
	m_bIsActive(TRUE),
	m_bRedrawScreen(FALSE),
	m_bShutDown(FALSE),
	//add this codes below
	bStart(FALSE),
	bInitialize(FALSE)

	//and then again..find
	BOOL CBasicApp::InitInstance()

	below 	DXPARAMSET::INIT();
//add this codes.
// first process to call hackshield.
HS_InitializeService();
// 2nd process to activate hackshield
// check if  initialization is successful if not return;
if (bInitialize) HS_StartService();
// hackshield validation process .
if (!bStart || !bInitialize)
{
	MessageBox(NULL, "Force Exit.", "TangINA Cheater ka!", MB_OK);
	return FALSE;
}


//and lastly!
//add this code on the last line .
//CALLER CODES HERE EDUJ HACKSHIELD APPLICATION
int __stdcall AhnHS_Callback(long lCode, long lParamSize, void* pParam)
{
	TCHAR msg[128] = { 0 };
	LPCTSTR lpszMsg(NULL);
	bool bAppExit(false);
	switch (lCode)
	{
		//Engine Callback
	case AHNHS_ENGINE_DETECT_GAME_HACK:
	{
		bAppExit = true;
		_stprintf(msg, _T("Game Hack found\n%s"), (char*)pParam);
		DxGlobalStage::GetInstance().CloseGame(msg);

		break;
	}
	case AHNHS_ENGINE_DETECT_WINDOWED_HACK:
	{
		//ShowMsgAndExitWithTimer(_T("Windowed Hack found."));

		break;
	}
	case AHNHS_ACTAPC_DETECT_SPEEDHACK:
	{
		bAppExit = true;
		_stprintf(msg, _T("Game Hack found\n%s"), (char*)pParam);
		DxGlobalStage::GetInstance().CloseGame(msg);
		break;
	}


	case AHNHS_ACTAPC_DETECT_KDTRACE:
	case AHNHS_ACTAPC_DETECT_KDTRACE_CHANGED:
	{
		bAppExit = true;
		_stprintf(msg, _T("AHNHS_ACTAPC_DETECT_KDTRACE_CHANGED"), lCode);
		DxGlobalStage::GetInstance().CloseGame(msg);
		break;
	}

	case AHNHS_ACTAPC_DETECT_AUTOMACRO:
	{
		bAppExit = true;
		_stprintf(msg, _T("AHNHS_ACTAPC_DETECT_AUTOMACRO"), lCode);
		DxGlobalStage::GetInstance().CloseGame(msg);

		break;
	}

	case AHNHS_ACTAPC_DETECT_ABNORMAL_FUNCTION_CALL:
	{
		bAppExit = true;
		_stprintf(msg, _T("Detect Abnormal Memory Access\n%s"), (char*)pParam);
		DxGlobalStage::GetInstance().CloseGame(msg);
		break;
	}
	case AHNHS_ACTAPC_DETECT_ABNORMAL_MEMORY_ACCESS:
	{
		bAppExit = true;
		_stprintf(msg, _T("Detect Memory Access\n%s"), (char*)pParam);
		DxGlobalStage::GetInstance().CloseGame(msg);
		break;
	}


	case AHNHS_ACTAPC_DETECT_AUTOMOUSE:
	{
		bAppExit = true;
		_stprintf(msg, _T("HackShield DETECT_AUTOMOUSE."), lCode);
		DxGlobalStage::GetInstance().CloseGame(msg);
		break;
	}
	case AHNHS_ACTAPC_DETECT_DRIVERFAILED:
	{
		bAppExit = true;
		_stprintf(msg, _T("HackShield DETECT_DRIVERFAILED."), lCode);
		DxGlobalStage::GetInstance().CloseGame(msg);
		break;
	}
	case AHNHS_ACTAPC_DETECT_HOOKFUNCTION:
	{
		bAppExit = true;;
		_stprintf(msg, _T("HackShield Detect D3D Hack. (%s)"), (char*)pParam);
		DxGlobalStage::GetInstance().CloseGame(msg);
		break;
	}
	case AHNHS_ACTAPC_DETECT_MESSAGEHOOK:
	{
		bAppExit = true;
		_stprintf(msg, _T("HackShield DETECT_MESSAGEHOOK."), lCode);
		DxGlobalStage::GetInstance().CloseGame(msg);
		break;
	}
	case AHNHS_ACTAPC_DETECT_MODULE_CHANGE:
	{
		bAppExit = true;
		_stprintf(msg, _T("HackShield DETECT_MODULE_CHANGE."), lCode);
		DxGlobalStage::GetInstance().CloseGame(msg);
		break;
	}
	case AHNHS_ACTAPC_DETECT_ENGINEFAILED:
	{
		bAppExit = true;
		_stprintf(msg, _T("HackShield DETECT_ENGINEFAILED."), lCode);
		DxGlobalStage::GetInstance().CloseGame(msg);
		break;
	}
	case AHNHS_ACTAPC_DETECT_CODEMISMATCH:
	{
		bAppExit = true;
		_stprintf(msg, _T("HackShield CODEMISMATCH."), lCode);
		DxGlobalStage::GetInstance().CloseGame(msg);
		break;
	}
	case AHNHS_ACTAPC_DETECT_MEM_MODIFY_FROM_LMP:
	case AHNHS_ACTAPC_DETECT_LMP_FAILED:
	{
		bAppExit = true;
		_stprintf(msg, _T("HackShield Detect memory modify."), lCode);
		DxGlobalStage::GetInstance().CloseGame(msg);
		break;
	}
	case AHNHS_ACTAPC_DETECT_ABNORMAL_HACKSHIELD_STATUS:
	{
		bAppExit = true;
		if (lCode != HS_ERR_ALREADY_GAME_STARTED)
		{
			bAppExit = true;
			_stprintf(msg, _T("HackShield Service already started by other game"), lCode);
			DxGlobalStage::GetInstance().CloseGame(msg);
			break;
		}
		else
		{
			bAppExit = true;
			_stprintf(msg, _T("HackShield Service Error"), lCode);
			DxGlobalStage::GetInstance().CloseGame(msg);
			break;
		}
	}
	case AHNHS_ACTAPC_DETECT_PROTECTSCREENFAILED:
	{
		bAppExit = true;
		_stprintf(msg, _T("HackShield PROTECTSCREENFAILED."), lCode);
		DxGlobalStage::GetInstance().CloseGame(msg);
		break;
	}

	}
	return 1;
}
BOOL CBasicApp::HS_StartService()
{
	TCHAR msg[128] = { 0 };
	int		nRet;

	nRet = _AhnHS_StartService();

	if (nRet != HS_ERR_OK)
	{
		switch (nRet)
		{
		case HS_ERR_START_ENGINE_FAILED:
		case HS_ERR_DRV_FILE_CREATE_FAILED:
		case HS_ERR_REG_DRV_FILE_FAILED:
		case HS_ERR_START_DRV_FAILED:
		default:
			_stprintf(msg, _T("A problem occurred in the hack prevention feature.(%x)"), nRet);
			DxGlobalStage::GetInstance().CloseGame(msg);
			break;
		}
		bStart = TRUE;
		DxGlobalStage::GetInstance().CloseGame(msg);
		return FALSE;
	}

	return TRUE;

}
BOOL CBasicApp::HS_InitializeService()
{
	TCHAR* pEnd = NULL;
	TCHAR	szFullFileName[MAX_PATH] = { 0, };
	TCHAR msg[128] = { 0 };
	LPCTSTR lpszMsg(NULL);
	int		nRet;
	TCHAR szFullFilePath[MAX_PATH] = { 0, };
	DWORD dwRet;

	//g_dwMainThreadID = GetCurrentThreadId();
	LoadString(NULL, 103, szTitle, 500);
	GetModuleFileName(NULL, szFullFileName, MAX_PATH);
	pEnd = _tcsrchr(szFullFileName, _T('\\')) + 1;
	if (!pEnd)
	{
		return FALSE;
	}
	*pEnd = _T('\0');

	_stprintf(g_szIniPath, _T("%s"), szFullFileName);
	_stprintf(g_szHShieldPath, _T("%s\\HackShield"), szFullFileName);
	_tcscat(szFullFileName, _T("\\HackShield\\EhSvc.dll"));


	nRet = _AhnHS_Initialize(szFullFileName, AhnHS_Callback,
		1000,
		"B228F2916A48AC24",
		AHNHS_CHKOPT_ALL
		| AHNHS_SELFDESTRUCTION_RATIO_FAST
		| AHNHS_DISPLAY_HACKSHIELD_TRAYICON
		| AHNHS_DISPLAY_HACKSHIELD_LOGO
		| AHNHS_CHKOPT_LOADLIBRARY
		| AHNHS_CHKOPT_PROTECT_D3DX
		| AHNHS_CHKOPT_LOCAL_MEMORY_PROTECTION
		| AHNHS_ALLOW_SVCHOST_OPENPROCESS
		| AHNHS_ALLOW_LSASS_OPENPROCESS
		| AHNHS_ALLOW_CSRSS_OPENPROCESS
		| AHNHS_DONOT_TERMINATE_PROCESS
		| AHNHS_CHKOPT_PROTECTSCREEN
		| AHNHS_CHKOPT_SELF_DESTRUCTION,
		AHNHS_SPEEDHACK_SENSING_RATIO_HIGHEST);

	if (nRet != HS_ERR_OK)
	{
		switch (nRet)
		{
		case HS_ERR_COMPATIBILITY_MODE_RUNNING:
		case HS_ERR_NEED_ADMIN_RIGHTS:
		case HS_ERR_INVALID_FILES:
		case HS_ERR_INIT_DRV_FAILED:
		case HS_ERR_DEBUGGER_DETECT:
		case HS_ERR_NOT_INITIALIZED:
		default:
			_stprintf(msg, _T("A problem occurred in the hack prevention feature.(%x)"), nRet);
			DxGlobalStage::GetInstance().CloseGame(msg);
			break;
		}
		// this is where the trick started! HEHE		
		bInitialize = TRUE;
		DxGlobalStage::GetInstance().CloseGame(msg);
		return FALSE;
	}

	return TRUE;
}
