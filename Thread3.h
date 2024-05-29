//---------------------------------------------------------------------------

#ifndef Thread3H
#define Thread3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class Thread3 : public TThread
{
private:
protected:
	void __fastcall Execute();
public:
	__fastcall Thread3(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
