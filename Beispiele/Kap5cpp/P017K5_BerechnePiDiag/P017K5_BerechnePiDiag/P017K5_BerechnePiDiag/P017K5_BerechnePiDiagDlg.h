// P017K5_BerechnePiDiagDlg.h: Headerdatei
#pragma once
class CP017K5BerechnePiDiagDlg : public CDialogEx
{
public:
	CP017K5BerechnePiDiagDlg(CWnd* pParent = nullptr);  // Standardkonstruktor
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_P017K5_BERECHNEPIDIAG_DIALOG };
#endif
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung
protected:
	HICON m_hIcon;
	virtual BOOL OnInitDialog();                        // Generierte Funktionen 
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam); // für die Meldungstabellen
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	DECLARE_MESSAGE_MAP()
public:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButtonExit();				// (6)
	afx_msg void OnBnClickedButtonCreateCircle();		// (1)
	afx_msg void OnBnChangeEditAnzp();					// (2) Auswertung erfolgz in OnBnClickedStartPoints 
	afx_msg void OnBnClickedStartPoints();				// (3) und (5)
private:
	BOOL bCircleCreated_;								//TRUE: Kreis gezeichnet
	int iAnzPoints_;									//Anzahl der Punkte
	CDC* dc_;											//DC 
	int createRandomNumber(int* iInCircle, int* iInRect);
	HBRUSH setBrushColor(CDC* dc, int iColor);
	HPEN setPenColor(CDC* dc, int iColor);
	void mathKoord2dcKoord(int* iX, int* iY);
	void drawPoint(int *iX, int *iY, int *iColor);
	void showPi(double dPi);							// (4)
	void showAktAnzP(int iAnzP);	      				// (5)
	void logPiVals(FILE* fpPiProt, int iNmbIdxP, double dPi); 
	void wctoc(char* cDst, wchar_t* wcSrc);
	afx_msg void OnEnChangeEditPi();
	afx_msg void OnEnChangeEditCurrAnzP();
public:
	CEdit editObjAnzP_;									//Für Eingabe der Anzahl der gewünschten Punkte
	CEdit editAnzPI_;									//Für Ausgabe der akt. Pi-Zahl
	CEdit editAktAnzP_;									//Für Ausgabe der akt. Anz. der Punkte
	int iSize_;											//Size des Quadrates/Radius des Kreises
};
