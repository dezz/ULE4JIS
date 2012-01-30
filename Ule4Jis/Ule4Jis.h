// Ule4Jis.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです。
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'stdafx.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// Ule4JisApp:
// このクラスの実装については、Ule4Jis.cpp を参照してください。
//

class Ule4JisApp : public CWinApp
{
public:
	Ule4JisApp();

// オーバーライド
	public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern Ule4JisApp theApp;