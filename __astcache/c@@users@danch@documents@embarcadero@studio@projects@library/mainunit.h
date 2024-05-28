//---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "VirtualTrees.AncestorVCL.hpp"
#include "VirtualTrees.BaseAncestorVCL.hpp"
#include "VirtualTrees.BaseTree.hpp"
#include "VirtualTrees.hpp"
#include <Vcl.ComCtrls.hpp>

#include "Book.h"
#include "Thread1.h"
#include "TThread2.h"
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TVirtualStringTree *LibraryStringTree;
	TButton *FillTable;
	TButton *GetBooks;
	TButton *InspectBooks;
	TProgressBar *ProgressBar1;
	TProgressBar *ProgressBar2;
	TButton *InspectWithHelp;
	TButton *PlaceTheBook;
	TLabel *NumOfBookGet;
	TProgressBar *ProgressBar3;
	void __fastcall LibraryStringTreeGetText(TBaseVirtualTree *Sender, PVirtualNode Node,
          TColumnIndex Column, TVSTTextType TextType, UnicodeString &CellText);
	void __fastcall FillTableClick(TObject *Sender);
	void __fastcall GetBooksClick(TObject *Sender);

private:	// User declarations
	BookContainer3 Container;
	Iterator<PtrBook> *it;
public:		// User declarations
	void AddBookToContainer();
	__fastcall TMainForm(TComponent* Owner);
	Thread1 *th;
    TThread2 *th2;
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
typedef struct
{
	ULONGLONG Id;
	int Year;
	int Pages;
	int Condition;
	UnicodeString Specific;
    UnicodeString Type;
} NodeStruct;
#endif
