// Ule4JisDlg.h : ヘッダー ファイル
//

#pragma once

#include "KeyEmulator.h"

// Ule4JisDlg ダイアログ
class Ule4JisDlg : public CDialog
{
// コンストラクション
public:
	Ule4JisDlg(CWnd* pParent = NULL);	// 標準コンストラクタ

// ダイアログ データ
	enum { IDD = IDD_ULE4JP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート

private:
	// added
	enum Strategy { USonJIS, JISonUS };
	NOTIFYICONDATA notifyIconData;
	Strategy currentStrategy;

	void showTaskTrayPopupMenu();
	void changeTaskTrayIconToUS();
	void changeTaskTrayIconToJIS();

// 実装
protected:
	HICON m_hIcon;
	std::auto_ptr<KeyEmulator> keyEmulator;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL DestroyWindow();
protected:
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBnClickedHide();
};
