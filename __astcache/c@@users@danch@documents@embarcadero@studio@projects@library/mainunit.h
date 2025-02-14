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
#include "Thread2.h"
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TVirtualStringTree *LibraryStringTree;
	TButton *GetBooks;
	TButton *InspectBooks;
	TProgressBar *ProgressBar1;
	TProgressBar *ProgressBar2;
	TButton *RepairBooks;
	TLabel *NumOfBookGet;
	TProgressBar *ProgressBar3;
	TLabel *BooksToRepair;
	TLabel *ProgBar1Label;
	TLabel *ProgBar2Label;
	TLabel *ProgBar3Label;
	void __fastcall LibraryStringTreeGetText(TBaseVirtualTree *Sender, PVirtualNode Node,
          TColumnIndex Column, TVSTTextType TextType, UnicodeString &CellText);
	void __fastcall GetBooksClick(TObject *Sender);
	void __fastcall InspectBooksClick(TObject *Sender);
	void __fastcall RepairBooksClick(TObject *Sender);

private:	// User declarations
	BookContainer2 Container;
	Iterator<PtrBook> *it;
public:		// User declarations
	void AddBookToContainer();
	Iterator<PtrBook> * GetIterator();
	__fastcall TMainForm(TComponent* Owner);
	Thread2 *th;
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
void FillStringTree(TVirtualStringTree *stringTree, Iterator<PtrBook> *it);
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
//---------------------------------------------------------------------------
#endif
