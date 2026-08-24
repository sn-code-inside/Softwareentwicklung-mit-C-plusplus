
// P002KD_FileViewDlg.h: Headerdatei
//

#pragma once
void setFileName(CString);
CString getFileName(void);

static CString FName_;

// CP002KDFileViewDlg-Dialogfeld
class CP002KDFileViewDlg : public CDialogEx
{
// Konstruktion
public:
	CP002KDFileViewDlg(CWnd* pParent = nullptr);	// Standardkonstruktor

// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_P002KD_FILEVIEW_DIALOG };
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
	afx_msg void OnBnClickedButtonOpenfile();
	void writeFileDataToEditControl();

private:
	CString strFNameAndPath_;      //Name und Pfad des zu öffnenden Files
public:
	afx_msg void OnBnClickedButtonSavefile();
	afx_msg void OnBnClickedButtonExit();
};


//=== Klasse cFileUtil ===========================================
class cFileUtil
{
public:
	cFileUtil(void);				//Standard-Konstruktor
	cFileUtil(CString fileName);	//Konstruktor

	void readFile(void);			//File lesen
	~cFileUtil(void);	            //Destruktor
	void saveFile(CString);         //Speichern des Files
	char* getFileData(void) { return strFileData_; }

private:
	CString strFNameAndPath_;		//Name und Pfad des zu öffnenden Files
	CFile file_;                    //File-Handle
	char* strFileData_;             //Speicher des Files
	unsigned long long ullFLen_;    //Länge des Files
};
//=== Klasse cFileUtil ========================================end