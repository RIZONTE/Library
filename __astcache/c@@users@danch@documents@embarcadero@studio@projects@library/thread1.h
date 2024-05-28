//---------------------------------------------------------------------------

#ifndef Thread1H
#define Thread1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>

#include "MainUnit.h"
//---------------------------------------------------------------------------
class Thread1 : public TThread
{
private:
protected:
	void __fastcall Execute();
public:
    void __fastcall AddBookToCont();
	__fastcall Thread1(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
