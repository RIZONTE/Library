//---------------------------------------------------------------------------

#ifndef TThread2H
#define TThread2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class TThread2 : public TThread
{
private:
protected:
	void __fastcall Execute();
public:
	__fastcall TThread2(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
