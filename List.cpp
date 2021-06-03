//---------------------------------------------------------------------------

#pragma hdrstop

#include "List.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void Stack::AddOperand(char operand)
{
	Operand* newSign = new Operand;

	newSign->sign = operand;;

	if(head == nullptr)
	{
	   head = newSign;
	   head->next = nullptr;
	} else
	{
	   Operand* temp = head;
	   head = newSign;
	   head->next = temp;
	}
}

char Stack::ExtractOperand()
{
	char operand = head->sign;
	Operand* temp = head;
	head = head->next;

	delete temp;

	return operand;
}

char Stack::ReadLastElement()
{
	char operand = head->sign;
    return operand;
}
