
#include "HShield.h"
#include "HSUpChk.h"
#include "BasicWnd.h"

//add this code on the last line.
// stop process
BOOL CBasicWnd::HS_StopService()
{
	int nRet = HS_ERR_OK;

	nRet = _AhnHS_StopService();
	if (nRet != HS_ERR_OK)
	{
		return FALSE;
	}
	return TRUE;
}

BOOL CBasicWnd::HS_UnInit()
{
	int nRet = HS_ERR_OK;

	nRet = _AhnHS_Uninitialize();

	if (nRet != HS_ERR_OK)
	{
		return FALSE;
	}
	return TRUE;
}
