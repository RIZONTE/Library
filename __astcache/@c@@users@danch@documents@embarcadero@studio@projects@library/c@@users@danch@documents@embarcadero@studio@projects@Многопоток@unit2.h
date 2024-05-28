//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "Unit3.h"
//---------------------------------------------------------------------------
class Thread2 : public TThread
{
private:
    DWORD processTime;
	__int64 ProgressId;
    bool AnalyseSeparate;
	AnalyseThread *AnalyseThreadObject;
protected:
	void __fastcall Execute();
	void __fastcall UpdateLabel();
	void __fastcall UpdateProgress();

public:
	__fastcall Thread2(bool analyseSeparate, bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
