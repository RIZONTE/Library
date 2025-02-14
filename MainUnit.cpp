//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VirtualTrees"
#pragma link "VirtualTrees.AncestorVCL"
#pragma link "VirtualTrees.BaseAncestorVCL"
#pragma link "VirtualTrees.BaseTree"
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
	LibraryStringTree->NodeDataSize = sizeof(NodeStruct);
	it = Container.GetIterator();
	RepairBooks->Enabled = false;
	InspectBooks->Enabled = false;
}
//---------------------------------------------------------------------------
Iterator<PtrBook>* TMainForm::GetIterator()
{
	return Container.GetIterator();
}
//---------------------------------------------------------------------------
void FillStringTree(TVirtualStringTree *stringTree, Iterator<PtrBook> *it)
{
	//������������� ���������� ����������
	stringTree->BeginUpdate();

	//�������� ������
	stringTree->Clear();

	for(it->First(); !it->IsDone(); it->Next())
	{
		//��������� ��������� ������
		PVirtualNode entryNode = stringTree->AddChild(stringTree->RootNode);

		//��������� ������ ����
		NodeStruct *nodeData = (NodeStruct*)stringTree->GetNodeData(entryNode);

		PtrBook book = it->GetCurrent();

		nodeData->Year =  book->GetYear();
		nodeData->Pages =  book->GetNumberOfPage();
		nodeData->Condition = book->GetCondition();
		nodeData->Type =  UnicodeString( PrintType(book->GetType()).c_str() );
		switch((int)book->GetType())
		{
			case 0:
				nodeData->Specific = PrintGenre(((Fiction *)book)->GetGenre());
				break;
			case 1:
				nodeData->Specific = PrintDiscipline(((Textbook *)book)->GetDisc());
				break;
			case 2:
				nodeData->Specific = PrintTheme(((Journal *)book)->GetTheme());
				break;
		}
	}

	//�������� ���������� ����������
	stringTree->EndUpdate();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::LibraryStringTreeGetText(TBaseVirtualTree *Sender, PVirtualNode Node,
          TColumnIndex Column, TVSTTextType TextType, UnicodeString &CellText)

{
    if(!Node) return;
	NodeStruct *nodeData = (NodeStruct*)Sender->GetNodeData(Node);
	switch(Column)
	{
		case 0: CellText = nodeData->Year; break;
		case 1: CellText = nodeData->Pages; break;
		case 2: CellText = nodeData->Condition; break;
		case 3: CellText = nodeData->Specific; break;
		case 4: CellText = nodeData->Type; break;
	}
}
//---------------------------------------------------------------------------
void TMainForm::AddBookToContainer()
{
	//srand(time(0));
	Container.AddBook(Book::createBook(RandomBookType()));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::GetBooksClick(TObject *Sender)
{
	th = new Thread2(true, true, false, false, it);
	th->Resume();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::InspectBooksClick(TObject *Sender)
{
	th = new Thread2(true, false, true, false, it);
	th->Resume();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::RepairBooksClick(TObject *Sender)
{
    th = new Thread2(true, false, false, true, it);
	th->Resume();
}
//---------------------------------------------------------------------------

