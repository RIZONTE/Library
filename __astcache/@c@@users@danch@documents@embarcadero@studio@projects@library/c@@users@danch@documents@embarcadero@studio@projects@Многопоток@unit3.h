//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class AnalyseThread : public TThread
{
private:
protected:
	void __fastcall Execute();
public:
	__fastcall AnalyseThread(bool CreateSuspended);

    // События необходимые для ревлизации анализа
	TEvent *DataReadyEvent;
	TEvent *DataCopiedEvent;
	TEvent *ComletedEvent;
};
//---------------------------------------------------------------------------
#endif
