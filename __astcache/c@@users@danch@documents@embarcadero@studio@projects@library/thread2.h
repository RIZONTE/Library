﻿//---------------------------------------------------------------------------

#ifndef Thread2H
#define Thread2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class Thread2 : public TThread
{
private:
	Iterator<PtrBook> *It;
    int NumOfBadConditionBook;
    bool RepairBooks;
	bool getingBooks;
    bool inspectingBooks;
	int randomQuantity;
	float ratio;
    float progress;
protected:
	void __fastcall Execute();
	void __fastcall AddBookToCont();
	void __fastcall UpdateProgressBar1();
	void __fastcall UpdateProgressBar2();
	void __fastcall UpdateProgressBar3();
	void __fastcall UpdateProgBar1Label();
	void __fastcall CompleteGetBooks();
	void __fastcall UpdateTableAfterInspect();
	void __fastcall UpdateTableAfterRepair();
	void __fastcall UpdateProgBar2LabelStart();
	void __fastcall UpdateProgBar3LabelStart();
public:
	__fastcall Thread2(bool CreateSuspended, bool getting, bool inspecting, bool repair, Iterator<PtrBook> *it);
};
//---------------------------------------------------------------------------
#endif
