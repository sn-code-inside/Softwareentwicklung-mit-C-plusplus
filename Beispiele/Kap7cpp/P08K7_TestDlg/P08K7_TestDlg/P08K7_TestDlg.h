
// P08K7_TestDlg.h: Hauptheaderdatei für die PROJECT_NAME-Anwendung
//

#pragma once

#ifndef __AFXWIN_H__
	#error "'pch.h' vor dieser Datei für PCH einschließen"
#endif

#include "resource.h"		// Hauptsymbole


// CP08K7TestDlgApp:
// Siehe P08K7_TestDlg.cpp für die Implementierung dieser Klasse
//

class CP08K7TestDlgApp : public CWinApp
{
public:
	CP08K7TestDlgApp();

// Überschreibungen
public:
	virtual BOOL InitInstance();

// Implementierung

	DECLARE_MESSAGE_MAP()
};

extern CP08K7TestDlgApp theApp;
