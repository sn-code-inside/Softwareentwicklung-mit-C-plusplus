
// P017K5_BerechnePiDiag.h: Hauptheaderdatei für die PROJECT_NAME-Anwendung
//

#pragma once

#ifndef __AFXWIN_H__
	#error "'pch.h' vor dieser Datei für PCH einschließen"
#endif

#include "resource.h"		// Hauptsymbole


// CP017K5BerechnePiDiagApp:
// Siehe P017K5_BerechnePiDiag.cpp für die Implementierung dieser Klasse
//

class CP017K5BerechnePiDiagApp : public CWinApp
{
public:
	CP017K5BerechnePiDiagApp();

// Überschreibungen
public:
	virtual BOOL InitInstance();

// Implementierung

	DECLARE_MESSAGE_MAP()
};

extern CP017K5BerechnePiDiagApp theApp;
