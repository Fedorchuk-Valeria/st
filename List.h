//---------------------------------------------------------------------------

#ifndef ListH
#define ListH
//---------------------------------------------------------------------------
#endif

#include "Node.h"


class Stack
{
  private:
	Operand* head;

  public:
	Stack()
	{
		head = nullptr;

	}

	void AddOperand(char operand);

	char ExtractOperand();

	char ReadLastElement();

};
