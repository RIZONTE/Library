﻿//---------------------------------------------------------------------------

#include <System.hpp>

#include "MainUnit.h"
#include "Book.h"

#pragma hdrstop

#include "Thread2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall Thread2::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------
__fastcall Thread2::Thread2(bool CreateSuspended, bool getting, bool inspecting, bool repair, Iterator<PtrBook> *it)
	: TThread(CreateSuspended)
{
	FreeOnTerminate = true;

    NumOfBadConditionBook = 0;
	It = it;
	RepairBooks = repair;
	getingBooks = getting;
	inspectingBooks = inspecting;
}
//---------------------------------------------------------------------------
void __fastcall Thread2::Execute()
{
	if(getingBooks)
	{
		srand(time(0));
		randomQuantity = rand()%90;
		ratio = 100.0/randomQuantity;
		Synchronize(&UpdateProgBar1Label);
		for( progress = 0; progress<randomQuantity ; progress++)
		{
			Synchronize(&AddBookToCont);
			Sleep(70);
			Synchronize(&UpdateProgressBar1);
		}
		Synchronize(&CompleteGetBooks);
	}
	else if(inspectingBooks)
	{
		//Декоратор, который пропускает только те книги, у которых состояние ниже 50
		It = new ConditionDecorator(It, 0, 50);
		//Обновляем надпись, начало "осмотра"
		Synchronize(&UpdateProgBar2LabelStart);		
		for(It->First(); !It->IsDone(); It->Next())
		{   //Тут "осмотр"
			NumOfBadConditionBook++;
		}
		//Имитация прогресса
		ratio = 100.0/NumOfBadConditionBook;
		for( progress = 0; progress<NumOfBadConditionBook ; progress++)
		{
			Sleep(70);
			Synchronize(&UpdateProgressBar2);
		}
		//Обновшяем надпись, конец "осмотра"
		Synchronize(&UpdateTableAfterInspect);
	}
	else if(RepairBooks)
	{
		//Декоратор, который пропускает только те книги, у которых состояние ниже 50
		It = new ConditionDecorator(It, 0, 50);
		Synchronize(&UpdateProgBar3LabelStart);
		for(It->First(); !It->IsDone(); It->Next())
		{   //Тут "реставрация"
			It->GetCurrent()->Repair();
			NumOfBadConditionBook++;
		}
		//Имитация прогресса
		ratio = 100.0/NumOfBadConditionBook;
		for( progress = 0; progress<NumOfBadConditionBook ; progress++)
		{
			Sleep(100);
			Synchronize(&UpdateProgressBar3);
		}
		//Обновшяем надпись, конец "осмотра"
		Synchronize(&UpdateTableAfterRepair);
    }
}
//---------------------------------------------------------------------------
void __fastcall Thread2::AddBookToCont()
{

	MainForm->AddBookToContainer();
}
//---------------------------------------------------------------------------
void __fastcall Thread2::UpdateProgressBar1()
{
	MainForm->ProgressBar1->Position = progress*ratio;
}
void __fastcall Thread2::UpdateProgressBar2()
{
	MainForm->ProgressBar2->Position = progress*ratio;
}
void __fastcall Thread2::UpdateProgressBar3()
{
	MainForm->ProgressBar3->Position = progress*ratio;
}

void __fastcall Thread2::UpdateProgBar1Label()
{
	MainForm->ProgBar1Label->Caption = UnicodeString("Несем книги...");
}
void __fastcall Thread2::CompleteGetBooks()
{
	MainForm->ProgressBar1->Position = 100;
	MainForm->NumOfBookGet->Caption += UnicodeString(randomQuantity);
	MainForm->ProgBar1Label->Caption = UnicodeString("Готово");
	MainForm->InspectBooks->Enabled = true;
}
void __fastcall Thread2::UpdateTableAfterInspect()
{
	MainForm->ProgBar2Label->Caption = UnicodeString("Закончили");
	MainForm->ProgressBar2->Position = 100;
	MainForm->BooksToRepair->Caption += UnicodeString(NumOfBadConditionBook);
	FillStringTree(MainForm->LibraryStringTree, MainForm->GetIterator());
	MainForm->RepairBooks->Enabled = true;
}
void __fastcall Thread2::UpdateTableAfterRepair()
{
	MainForm->ProgBar3Label->Caption = UnicodeString("Отреставрировали");
	MainForm->ProgressBar3->Position = 100;
	FillStringTree(MainForm->LibraryStringTree, MainForm->GetIterator());
}
void __fastcall Thread2::UpdateProgBar2LabelStart()
{
	MainForm->ProgBar2Label->Caption = UnicodeString("Осматриваем...");
}
void __fastcall Thread2::UpdateProgBar3LabelStart()
{
	MainForm->ProgBar3Label->Caption = UnicodeString("Реставрируем...");
}
