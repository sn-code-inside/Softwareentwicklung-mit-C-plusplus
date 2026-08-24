
// P017K5_BerechnePiDiagDlg.h: Headerdatei
//

#pragma once


// CP017K5BerechnePiDiagDlg-Dialogfeld
class CP017K5BerechnePiDiagDlg : public CDialogEx
{
// Konstruktion
public:
	CP017K5BerechnePiDiagDlg(CWnd* pParent = nullptr);	// Standardkonstruktor

// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_P017K5_BERECHNEPIDIAG_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterstützung


// Implementierung
protected:
	HICON m_hIcon;

	// Generierte Funktionen für die Meldungstabellen
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//void CreateImageExample();
	void CreatePointExample();
	void setBrushColor(CDC* dc, int iColor);
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButtonExit();
	afx_msg void OnBnClickedButtonCreateCircle();

private:
	BOOL bCircleCreated_;
	int iAnzPoints_;
	//CEdit editObj;
public:
	afx_msg void OnEnChangeEditAnzp();
	afx_msg void OnBnClickedStartPoints();
	CEdit editObj_;
};
