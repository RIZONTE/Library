//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    DWORD startTime = GetTickCount();
	__int64 NumberOfObjects = 100;
	for(__int64 i=0; i<NumberOfObjects; i++)
	{
		// xntybt объекта
		Sleep(30);

		//Обработатка объекта
		Sleep(70);

		ProgressBar1->Position  = i;
	}

	DWORD endTime = GetTickCount();
	DWORD processTime = endTime - startTime;

	UnicodeString timeStr = UnicodeString(processTime);
    Label1->Caption = timeStr;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	th = new Thread2(false, true);
	th->Resume();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	th = new Thread2(true, true);
	th->Resume();
}
//---------------------------------------------------------------------------

