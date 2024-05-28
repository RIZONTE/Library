//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "Unit2.h"
#include "Unit3.h"
#include "Unit1.h"
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

__fastcall Thread2::Thread2(bool analyseSeparate, bool CreateSuspended)
	: TThread(CreateSuspended)
{
	FreeOnTerminate = true;
	AnalyseSeparate = analyseSeparate;
	AnalyseThreadObject = new AnalyseThread(false);
}
//---------------------------------------------------------------------------
void __fastcall Thread2::Execute()
{
    DWORD startTime = GetTickCount();
	__int64 NumberOfObjects = 100;
	for(ProgressId = 0; ProgressId<NumberOfObjects; ProgressId++)
	{
		// Чтение объекта
		Sleep(30);

		if(AnalyseSeparate)
		{
			Sleep(1);
			AnalyseThreadObject->DataReadyEvent->SetEvent();
			while(AnalyseThreadObject->DataCopiedEvent->WaitFor(2000) != wrSignaled)
			{ }
			AnalyseThreadObject->DataCopiedEvent->ResetEvent();
		}
		else
		{
            //Обработатка объекта
			Sleep(70);
        }

		Synchronize(&UpdateProgress);
	}

	DWORD endTime = GetTickCount();
	processTime = endTime - startTime;

	Synchronize(&UpdateLabel);

	//AnalyseThreadObject->Terminate();
	//AnalyseThreadObject->WaitFor();
}
//---------------------------------------------------------------------------
void __fastcall Thread2::UpdateLabel()
{
	   UnicodeString timeStr = UnicodeString(processTime);
	   Form1->Label1->Caption = timeStr;
}
void __fastcall Thread2::UpdateProgress()
{
	   Form1->ProgressBar1->Position  = ProgressId;
}
