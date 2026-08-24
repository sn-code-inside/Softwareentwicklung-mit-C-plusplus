
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

const COLORREF rgbRed = 0x000000FF;
const COLORREF rgbYellow = 0x0000FFFF;
const COLORREF rgbGreen = 0x0000FF00;
const COLORREF rgbBlue = 0x00FF0000;
const COLORREF rgbBlack = 0x00000000;
const COLORREF rgbWhite = 0x00FFFFFF;

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


// CP017K5BerechnePiDiagDlg-Dialogfeld



CP017K5BerechnePiDiagDlg::CP017K5BerechnePiDiagDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_P017K5_BERECHNEPIDIAG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	bCircleCreated_ = FALSE;
}

void CP017K5BerechnePiDiagDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_AnzP, editObj_);
}

BEGIN_MESSAGE_MAP(CP017K5BerechnePiDiagDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CP017K5BerechnePiDiagDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON_Exit, &CP017K5BerechnePiDiagDlg::OnBnClickedButtonExit)
	ON_BN_CLICKED(IDC_BUTTON_CreateCircle, &CP017K5BerechnePiDiagDlg::OnBnClickedButtonCreateCircle)
	ON_EN_CHANGE(IDC_EDIT_AnzP, &CP017K5BerechnePiDiagDlg::OnEnChangeEditAnzp)
	ON_BN_CLICKED(IDC_BUTTON_StartPoints, &CP017K5BerechnePiDiagDlg::OnBnClickedStartPoints)
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

void CP017K5BerechnePiDiagDlg::CreatePointExample()
{
	CDC* dc = GetDC();

	RECT rect;
	rect.left = 10;
	rect.right = 400;
	rect.top = 10;
	rect.bottom = 400;

	setBrushColor(dc, rgbRed);
	dc->Rectangle(&rect);

	setBrushColor(dc, rgbYellow);
	dc->Ellipse(&rect);

	bCircleCreated_ = TRUE;
}

void CP017K5BerechnePiDiagDlg::setBrushColor(CDC* dc, int iColor)
{
	dc->SelectObject(GetStockObject(DC_BRUSH));
	int iCol = dc->SetDCBrushColor(iColor);
}
void CP017K5BerechnePiDiagDlg::OnBnClickedCancel()
{
	// TODO: Fügen Sie hier Ihren Handlercode für Benachrichtigungen des Steuerelements ein.
	CDialogEx::OnCancel();
}


void CP017K5BerechnePiDiagDlg::OnBnClickedButtonExit()
{
	// TODO: Fügen Sie hier Ihren Handlercode für Benachrichtigungen des Steuerelements ein.
	CDialogEx::OnCancel();
}


void CP017K5BerechnePiDiagDlg::OnBnClickedButtonCreateCircle()
{
	// TODO: Fügen Sie hier Ihren Handlercode für Benachrichtigungen des Steuerelements ein.
	CreatePointExample();
}


void CP017K5BerechnePiDiagDlg::OnEnChangeEditAnzp()
{
	if (FALSE == bCircleCreated_)
	{
		CString strText("No circle created");
		CString strKind("Error");
		MessageBox (strText, strKind, MB_ICONWARNING);
	}
	else
	{
		iAnzPoints_ = 0;
	}
}


void CP017K5BerechnePiDiagDlg::OnBnClickedStartPoints()
{
	// TODO: Fügen Sie hier Ihren Handlercode für Benachrichtigungen des Steuerelements ein.
	if (FALSE == bCircleCreated_)
	{
		CString strText("No circle created");
		CString strKind("Error");
		MessageBox(strText, strKind, MB_ICONWARNING);
	}
	else
	{
		int nLineCount = editObj_.GetLineCount();
		CString str, strLine;
		int len = editObj_.LineLength(editObj_.LineIndex(0));
		editObj_.GetLine(0, str.GetBuffer(len), len);
		char cStr[32] = { 0 };
		strcpy_s(cStr, CT2A(str));
		cStr[len] = 0;

		iAnzPoints_ = atoi(cStr);
	}
}

void createRandomNumber(int* iX, int *iY)
{
	srand((unsigned int)time(NULL));
	*iX = rand();
	srand((unsigned int)time(NULL));
	*iY = rand();
}