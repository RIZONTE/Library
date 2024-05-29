//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "Unit3.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall AnalyseThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall AnalyseThread::AnalyseThread(bool CreateSuspended)
	: TThread(CreateSuspended)
{
	FreeOnTerminate = true;

	DataReadyEvent = new TEvent(NULL, true, false, "", false);
	DataCopiedEvent = new TEvent(NULL, true, false, "", false);
	ComletedEvent = new TEvent(NULL, true, false, "", false);
}
//---------------------------------------------------------------------------
void __fastcall AnalyseThread::Execute()
{
	ComletedEvent->SetEvent();
	while(!Terminated)
	{
        //Ждать готовности буфера с данными
		if(DataReadyEvent->WaitFor(2000) == wrSignaled)
		{
			//Скопировать данные об объекте в локальный буфер
			Sleep(1);
            DataCopiedEvent->ResetEvent();
			DataCopiedEvent->SetEvent();

            ComletedEvent->ResetEvent();
			//Выполнить обработку данных
			Sleep(70);
            ComletedEvent->SetEvent();
        }

	}


	delete DataReadyEvent;
	delete DataCopiedEvent;
	delete ComletedEvent;
}
//---------------------------------------------------------------------------
