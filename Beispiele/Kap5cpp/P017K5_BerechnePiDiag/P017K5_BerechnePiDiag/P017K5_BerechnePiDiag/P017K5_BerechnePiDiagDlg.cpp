
// P017K5_BerechnePiDiagDlg.cpp: Implementierungsdatei
//

#include "pch.h"
#include "framework.h"
#include "P017K5_BerechnePiDiag.h"
#include "P017K5_BerechnePiDiagDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//Farbdefinitionen für Ellipse und Quadrat
const COLORREF rgbRed = 0x000000FF;
const COLORREF rgbYellow = 0x0000FFFF;
const COLORREF rgbLigthYellow = 0xCBFFFF;
const COLORREF rgbGreen = 0x0000FF00;
const COLORREF rgbBlue = 0x00FF0000;
const COLORREF rgbLightBlue = 0xFFFCD3;
const COLORREF rgbBlack = 0x00000000;
const COLORREF rgbWhite = 0x00FFFFFF;

//Grenzen des Quadrates 
#define LeftSide    10
#define RightSide  310
#define TopSide     10
#define BottomSide 310

#define LOGPI_FILE "LOGPI.csv"

// CAboutDlg-Dialogfeld für Anwendungsbefehl "Info"

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung

// Implementierung
protected:
	DECLARE_MESSAGE_MAP()
public:
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)

END_MESSAGE_MAP()


CP017K5BerechnePiDiagDlg::CP017K5BerechnePiDiagDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_P017K5_BERECHNEPIDIAG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	bCircleCreated_ = FALSE;

	CString strPILF(LOGPI_FILE);
	BOOL bOk = DeleteFile(strPILF);

	iSize_ = (BottomSide - TopSide +1) / 2;

	dc_ = NULL;
}

void CP017K5BerechnePiDiagDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_AnzP, editObjAnzP_);
	DDX_Control(pDX, IDC_EDIT_PI, editAnzPI_);
	DDX_Control(pDX, IDC_EDIT_CurrAnzP, editAktAnzP_);
}

BEGIN_MESSAGE_MAP(CP017K5BerechnePiDiagDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CP017K5BerechnePiDiagDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON_Exit, &CP017K5BerechnePiDiagDlg::OnBnClickedButtonExit)
	ON_BN_CLICKED(IDC_BUTTON_CreateCircle, &CP017K5BerechnePiDiagDlg::OnBnClickedButtonCreateCircle)
	ON_EN_CHANGE(IDC_EDIT_AnzP, &CP017K5BerechnePiDiagDlg::OnBnChangeEditAnzp)
	ON_BN_CLICKED(IDC_BUTTON_StartPoints, &CP017K5BerechnePiDiagDlg::OnBnClickedStartPoints)
	ON_EN_CHANGE(IDC_EDIT_PI, &CP017K5BerechnePiDiagDlg::OnEnChangeEditPi)
	ON_EN_CHANGE(IDC_EDIT_CurrAnzP, &CP017K5BerechnePiDiagDlg::OnEnChangeEditCurrAnzP)
END_MESSAGE_MAP()


// CP017K5BerechnePiDiagDlg-Meldungshandler

BOOL CP017K5BerechnePiDiagDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Hinzufügen des Menübefehls "Info..." zum Systemmenü.

	// IDM_ABOUTBOX muss sich im Bereich der Systembefehle befinden.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Symbol für dieses Dialogfeld festlegen.  Wird automatisch erledigt
	//  wenn das Hauptfenster der Anwendung kein Dialogfeld ist
	SetIcon(m_hIcon, TRUE);			// Großes Symbol verwenden
	SetIcon(m_hIcon, FALSE);		// Kleines Symbol verwenden

	// TODO: Hier zusätzliche Initialisierung einfügen

	return TRUE;  // TRUE zurückgeben, wenn der Fokus nicht auf ein Steuerelement gesetzt wird
}

void CP017K5BerechnePiDiagDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Wenn Sie dem Dialogfeld eine Schaltfläche "Minimieren" hinzufügen, benötigen Sie
//  den nachstehenden Code, um das Symbol zu zeichnen.  Für MFC-Anwendungen, die das 
//  Dokument/Ansicht-Modell verwenden, wird dies automatisch ausgeführt.

void CP017K5BerechnePiDiagDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Gerätekontext zum Zeichnen

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Symbol in Clientrechteck zentrieren
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Symbol zeichnen
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Die System ruft diese Funktion auf, um den Cursor abzufragen, der angezeigt wird, während der Benutzer
//  das minimierte Fenster mit der Maus zieht.
HCURSOR CP017K5BerechnePiDiagDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Exit-Button betätigt
void CP017K5BerechnePiDiagDlg::OnBnClickedCancel()
{
	CDialogEx::OnCancel();
}

// Auf "Schließen" (rechts oben im Dialog) gedrückt
void CP017K5BerechnePiDiagDlg::OnBnClickedButtonExit()
{
	CDialogEx::OnCancel();
}

// DC wird gezeichnet (Kreis und Quadrat)
void CP017K5BerechnePiDiagDlg::OnBnClickedButtonCreateCircle()
{
	if (dc_ == NULL)
		dc_ = GetDC();

	RECT rect;

	rect.left = LeftSide;
	rect.right = RightSide;
	rect.top = TopSide;
	rect.bottom = BottomSide;

	HBRUSH oldBrush = setBrushColor(dc_, rgbLigthYellow);
	dc_->Rectangle(&rect);
	dc_->SelectObject(oldBrush);

	oldBrush = setBrushColor(dc_, rgbLightBlue);
	dc_->Ellipse(&rect);
	dc_->SelectObject(oldBrush);

	bCircleCreated_ = TRUE;

	CString strPI("        ");
	editAnzPI_.SetWindowTextW(strPI);
	editAktAnzP_.SetWindowTextW(strPI);

	srand((unsigned int)time(NULL));
}

//Falls der DC nicht gezeichnet ist, kann auch keine Anzahl der Punkte eingegeben werden
void CP017K5BerechnePiDiagDlg::OnBnChangeEditAnzp()
{
	if (FALSE == bCircleCreated_)
	{
		CString strText("No circle created");
		CString strKind("Error");
		MessageBox(strText, strKind, MB_ICONWARNING);
	}
	else
		iAnzPoints_ = 0;
}

//Falls der DC nicht gezeichnet ist und AnzPoints defineirt ist, werden Zufallszahlen ermittelt und Punkte gesetzt
//Parallel wird ein Protokoll ("LOGPI.csv") geschrieben: (int PunkteNummer; (double) Pi-Wert
void CP017K5BerechnePiDiagDlg::OnBnClickedStartPoints()
{
	if (FALSE == bCircleCreated_)
	{
		CString strText("No circle created");
		CString strKind("Error");
		MessageBox(strText, strKind, MB_ICONWARNING);
	}
	else
	{
		CString str;
		int len = editObjAnzP_.LineLength(editObjAnzP_.LineIndex(0));
		editObjAnzP_.GetLine(0, str.GetBuffer(len), len);

		char cStr[32] = { 0 };
		wchar_t* strWC = str.GetBuffer(len);
		strWC[len] = 0;
		wctoc(cStr, strWC);
		iAnzPoints_ = atoi(cStr);
		if (0 == iAnzPoints_)
		{
			CString strText("No point count defined");
			CString strKind("Error");
			MessageBox(strText, strKind, MB_ICONWARNING);
			return;
		}

		int iInCircle = 0;
		int iInRect = 0;
		int iInAll = iInCircle + iInRect;

		FILE* fpPiProt = NULL;
		int err = fopen_s(&fpPiProt, LOGPI_FILE, "wb");
		double dPi = .0;

		int iNmbIdxP = 0;
		while (iAnzPoints_)
		{
			int iNoDraw = createRandomNumber(&iInCircle, &iInRect);
			if (iNoDraw)
				continue;

			iInAll = iInCircle + iInRect;
			if (iInAll)
				dPi = 4.0 * (double)iInCircle / (double)iInAll;
			else
				continue; // dPi = .0;
			showPi(dPi);

			showAktAnzP(iAnzPoints_);

			logPiVals(fpPiProt, iNmbIdxP, dPi);
			iAnzPoints_--;
			iNmbIdxP++;
		} //while (iAnzPoints_)

		iInAll = iInCircle + iInRect;
		dPi = 4.0 * (double)iInCircle / (double)iInAll;

		showPi(dPi);
		showAktAnzP(iAnzPoints_);

		logPiVals(fpPiProt, iNmbIdxP, dPi);
		if (fpPiProt)
			fclose(fpPiProt);

		CString strReady("Fertig");
		CString strHint("Hinweis");
		MessageBox(strReady, strHint, 0);
	}
}

//Kreiert Zufallszahlen und zeichnet die Punkte 
int CP017K5BerechnePiDiagDlg::createRandomNumber(int* iInCircle, int* iInRect)
{
	int iMaxRadius = iSize_;

	int iX, iY, iColor;
	int iNoDraw = 0;

	iX = rand();
	iX = iX & 0xFF;
	if (iX > iMaxRadius)
		iNoDraw = 1;

	iY = rand();
	iY = iY & 0xFF;
	if (iY > iMaxRadius)
		iNoDraw = 1;

	if (1 == iNoDraw)
		return iNoDraw;

	double iRadius = sqrt((iX) * (iX)+(iY) * (iY));
	if (iRadius <= iMaxRadius)
	{
		iColor = rgbBlue;			//Punkt liegt im Kreis und Quadrat
		(*iInCircle)++;
	}
	else
	{
		iColor = rgbRed;			//Punkt liegt nur im Quadrat
		(*iInRect)++;
	}

	mathKoord2dcKoord(&iX, &iY);
	drawPoint(&iX, &iY, &iColor);
	return iNoDraw;
}

//Setzt die FüllFarbe
HBRUSH CP017K5BerechnePiDiagDlg::setBrushColor(CDC* dc, int iColor)
{
	HBRUSH oldBrush = (HBRUSH)dc->SelectObject(GetStockObject(DC_BRUSH));
	int iCol = dc->SetDCBrushColor(iColor);
	return oldBrush;
}

//Setzt die LinienFarbe
HPEN CP017K5BerechnePiDiagDlg::setPenColor(CDC* dc, int iColor)
{
	HPEN hPen = (HPEN)dc->SelectObject(GetStockObject(DC_PEN));
	int iCol = dc->SetDCPenColor(iColor);
	return hPen;
}

//Wandelt die math. Koordienaten in die DC-Koordinaten um
void CP017K5BerechnePiDiagDlg::mathKoord2dcKoord(int* iX, int* iY)
{
	int iSize = iSize_;
	*iX = (*iX) + LeftSide + iSize;
	*iY = TopSide + iSize - (*iY);
}

//Zeichnet einen 2x2 Punkt. 
void CP017K5BerechnePiDiagDlg::drawPoint(int *iX, int *iY, int *iColor)
{
	RECT rect;

	rect.left = *iX - 1;
	rect.right = *iX + 1;
	rect.top = *iY - 1;
	rect.bottom = *iY + 1;

	HBRUSH oldBrush = 0;
	HPEN hPen = 0;

	oldBrush = setBrushColor(dc_, *iColor);
	hPen = setPenColor(dc_, *iColor);

	dc_->Rectangle(&rect);

	dc_->SelectObject(hPen);
	dc_->SelectObject(oldBrush);
}

//Zeigt den aktuellen PI-Wert
void CP017K5BerechnePiDiagDlg::showPi(double dPi)
{
	char cPI[32] = { 0 };
	sprintf_s(cPI, 32, "%.5f", dPi);
	CString strPI(cPI);
	editAnzPI_.SetWindowTextW(strPI);
	UpdateWindow();
}

//Zeigt den aktuellen Punkte-Wert
void CP017K5BerechnePiDiagDlg::showAktAnzP(int iAnzP)
{
	char cAnzP[32] = { 0 };
	sprintf_s(cAnzP, 32, "%d", iAnzP);
	CString strAnzP(cAnzP);
	editAktAnzP_.SetWindowTextW(strAnzP);
	UpdateWindow();
}

//Loggt die aktuellen Punkte- und Pi-Werte im csv-Format
void CP017K5BerechnePiDiagDlg::logPiVals(FILE* fpPiProt, int iNmbIdxP, double dPi)
{
	double dPI=3.1415926535;
	if (fpPiProt)
	{
		char cPI[64] = { 0 };
		sprintf_s(cPI, 64, "%d; %.5f; %.5f\n", iNmbIdxP, dPi, dPI);
		int i = 0;
		while (cPI[i])
		{
			if (cPI[i] == '.')
				cPI[i] = ',';
			i++;
		}
		fwrite(cPI, strlen(cPI), sizeof(char), fpPiProt);
	}
}

//wandet einen wchar_t-String in einen char-String um
void CP017K5BerechnePiDiagDlg::wctoc(char * cDst, wchar_t *wcSrc)
{
	int i = 0;
	while (wcSrc[i])
	{
		cDst[i] = (char)wcSrc[i];
		i++;
	}
}
//Nicht genutzt
void CP017K5BerechnePiDiagDlg::OnEnChangeEditPi()
{
}
//Nicht genutzt
void CP017K5BerechnePiDiagDlg::OnEnChangeEditCurrAnzP()
{
}
