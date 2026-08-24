
// P002KD_FileView.h: Hauptheaderdatei für die PROJECT_NAME-Anwendung
//

#pragma once

#ifndef __AFXWIN_H__
	#error "'pch.h' vor dieser Datei für PCH einschließen"
#endif

#include "resource.h"		// Hauptsymbole


// CP002KDFileViewApp:
// Siehe P002KD_FileView.cpp für die Implementierung dieser Klasse
//

class CP002KDFileViewApp : public CWinApp
{
public:
	CP002KDFileViewApp();

// Überschreibungen
public:
	virtual BOOL InitInstance();

// Implementierung

	DECLARE_MESSAGE_MAP()
};

extern CP002KDFileViewApp theApp;
