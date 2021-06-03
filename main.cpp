//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "List.h"
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm10 *Form10;
Stack stack;
String result;
String expression;
//---------------------------------------------------------------------------
__fastcall TForm10::TForm10(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm10::RPNClick(TObject *Sender)
{
	//Label1->Caption = " ";
	result = "";
	expression = ExpressionEnter->Text;
	int i = 1, scobki = 0;
	int count = 0;
	int length = expression.Length();

	while(i <= length)
	{
		if(expression[1] == '-' && i == 1)
		{
			result += '0';
			result += ' ';
			stack.AddOperand(expression[1]);
			count++;
			i++;
		}

		if(expression[i] == '-' || expression[i] == '+' || expression[i] == '*' ||
		   expression[i] == '/' || expression[i] == '^' || expression[i] == ')' || expression[i] == '(')
		{
			if(expression[i] == '(')
			{
				scobki = 1;
            }
			if (count != 0)
			{

				switch(expression[i])
				{
					case '+':
					case '-':
					//case '*':
					//case '/':
					//case '^':
						if(stack.ReadLastElement() == '(')
						{
							scobki = 1;
							break;
						} else if(stack.ReadLastElement() == '*' || stack.ReadLastElement() == '-'  ||
								  stack.ReadLastElement() == '/' || stack.ReadLastElement() == '+' ||
								   stack.ReadLastElement() == '^')
						{
							if(scobki > 0)
							{
								//Label1->Caption += "scobki";
								while(stack.ReadLastElement() != '(')
								{
									result += stack.ExtractOperand();
									result += ' ';
									count--;
								}
							} else
							{
								while(count != 0)
								{
									result += stack.ExtractOperand();
									result += ' ';
									count--;
								}
                            }

							break;
						}
					case '*':
					case '/':
					//case '^':
						if(stack.ReadLastElement() == '(' || stack.ReadLastElement() == '+' ||
						   stack.ReadLastElement() == '-')
						{
							break;
						} else if(stack.ReadLastElement() == '/' || stack.ReadLastElement() == '*' ||
								  stack.ReadLastElement() == '^')
						{
							if(scobki > 0)
							{
								while(stack.ReadLastElement() != '(')
								{
									result += stack.ExtractOperand();
									result += ' ';
									count--;
								}
							} else
							{
								while(count != 0)
								{
									result += stack.ExtractOperand();
									result += ' ';
									count--;
								}
							}
							break;
						}
					case '^':
                        if(stack.ReadLastElement() == '(' || stack.ReadLastElement() == '+' ||
						   stack.ReadLastElement() == '-' || stack.ReadLastElement() == '/' ||
						   stack.ReadLastElement() == '*' )
						{
							break;
						} else if(stack.ReadLastElement() == '^')
						{
							if(scobki > 0)
							{
								while(stack.ReadLastElement() != '(')
								{
									result += stack.ExtractOperand();
									result += ' ';
									count--;
								}
							} else
							{
								while(count != 0)
								{
									result += stack.ExtractOperand();
									result += ' ';
									count--;
								}
                            }
							break;
						}
				}
			}
			stack.AddOperand(expression[i]);
			count++;
			//Label1->Caption += String(stack.ReadLastElement());
            //Label1->Caption += ' ';
			if(expression[i] == ')')
			{
			   stack.ExtractOperand();
			   count--;
			   scobki = 0;
			   while(stack.ReadLastElement() != '(')
			   {
				   result += stack.ExtractOperand();
				   result += ' ';
				   count--;
			   }
			   stack.ExtractOperand();
			   count--;

			}
			i++;
		} else
		{
			while(i <= length && expression[i] != '-' && expression[i] != '+' && expression[i] != '*' &&
				  expression[i] != '/' && expression[i] != '^' && expression[i] != ')')
			{
				result += expression[i];
				i++;
			}
            result += ' ';

		}
		//Label1->Caption += '\n';
		//Label1->Caption += String(result);
	}

	while(count > 0)
	{
		result += stack.ExtractOperand();
        result += ' ';
		count--;
	}

	//Label1->Caption += '\n';
	Label1->Caption = String(result);


}
//---------------------------------------------------------------------------
void __fastcall TForm10::CountUpClick(TObject *Sender)
{
	int i = 1, k, temp, temp1, l, imain = 1, minus = 0, use = 0, p;
	int indexnumber2, indexnumber1;
	String answer, newResult = result;
	char operation;
	int length = newResult.Length();
	int length1 = expression.Length();
	//String number1, number2;
	float num1 = 0, num2 = 0;
	float fractionalPart = 0;
	while(imain <= length-1)
	{
		num1 = 0;
		num2 = 0;
		fractionalPart = 0;
		String number1;
		String number2;
		//length = newResult.Length();

		while(i <= length-1 && newResult[i] != '-' && newResult[i] != '+' && newResult[i] != '*' &&
			  newResult[i] != '/' && newResult[i] != '^')
		{
			i++;
		}

		k = i-2;

		while(newResult[k] != ' ')
		{
			k--;
		}

		temp1 = temp = k-1;
		k++;
		indexnumber2 = k;
		while(k <= (i-2))
		{
			number2 += newResult[k];
			k++;
		}


		while(temp != 0 && newResult[temp] != ' ')
		{
			temp--;
		}


		temp++;
		indexnumber1 = temp;

		while(temp <= temp1)
		{
			number1 += newResult[temp];
			temp++;
		}

		k = 1;
		while(k <= number1.Length() && number1[k] != '.' &&  number1[k] != ',')
		{
			k++;
		}

		temp = 1;
		temp1 = k+1;
		k--;
		while(temp < temp1-1)
		{
			num1 += (number1[temp] - '0') * pow(10, k-1);
			k--;
			temp++;
		}

		k = number1.Length() - temp1;
		l = k;
		if(temp1 <= number1.Length())
		{
			while(temp1 <= number1.Length() && number1[temp1]!= '0')
			{
			   fractionalPart += (number1[temp1] - '0') * pow(10, k);
			   k--;
			   temp1++;
			}

			fractionalPart /= pow(10, l+1);
			num1 += round(fractionalPart*10)/10;
			num1 = round(num1*10)/10;
			fractionalPart = 0;
		}

		k = 1;
		while(k <= number2.Length() && number2[k] != '.' &&  number2[k] != ',')
		{
			k++;
		}

		temp = 1;
		temp1 = k+1;
		k--;
		while(temp < temp1-1)
		{
			num2 += (number2[temp] - '0') * pow(10, k-1);
			k--;
			temp++;
		}

		k = number2.Length() - temp1;
		l = k;
		//Label2->Caption += String(k);
		//Label2->Caption += '\n';
		if(temp1 <= number2.Length())
		{
			while(temp1 <= number2.Length() && number2[temp1]!= '0')
			{
			   fractionalPart += (number2[temp1] - '0') * pow(10, k);
			   k--;
			   temp1++;
			}

			fractionalPart /= pow(10, l+1);

			num2 += round(fractionalPart*10)/10;
			num2 = round(num2*10)/10;
			fractionalPart = 0;
		}
		result = newResult;
		//Label2->Caption += String(num1);
		//Label2->Caption += '\n';
		//Label2->Caption += String(num2);
		//Label2->Caption += '\n';
		//newResult = NULL;
		if(i < length-1)
		{
			switch(result[i])
			{
				case '+':
					  if(minus == 1 && operation == '+')
					  {
						num1 = 0-num1;
						minus = 0;

					  }
					  if(minus == 1 && operation == '-')
					  {
						num2 = 0-num2;
						minus = 0;

					  }
					  if(num1 + num2 < 0)
					  {
						minus = 1;
						operation = result[i];
						answer = FloatToStr(abs(num1 + num2));
					  } else
					  {
						answer = FloatToStr(num1 + num2);
					  }

					  k = 1;
					  while(k < indexnumber1)
					  {
						newResult[k] = result[k];
						k++;
					  }
					  if(answer.Length() > 5)
					  {
						temp = number2.Length() + number1.Length();
					  } else
					  {
						temp = answer.Length();
					  }

					  temp1 = 1;
					 temp = k + temp;
					  while(k < temp)
					  {
						newResult[k] = answer[temp1];
						k++;
						temp1++;
					  }

					  while(k < k + length - i)
					  {
						newResult[k] = result[i+1];
						k++;
						i++;
					  }
					  newResult[k] = '\0';
					  length = k-1;
					  break;
				case '-':
						  if(minus == 1 && operation == '-')
						  {
							num1 = 0 - num1;
							minus = 0;

						  }
						  if(minus == 1 && operation == '+')
						  {
							num2 = 0 - num2;
							minus = 0;

						  }
						  if(num1 - num2 < 0)
						  {
							  minus = 1;
							  operation = result[i];
							  answer = FloatToStr(abs(num1 - num2));
						  } else
						  {
							 answer = FloatToStr(num1 - num2);
						  }
					  k = 1;
					  while(k < indexnumber1)
					  {
						newResult[k] = result[k];
						k++;
					  }
					  if(answer.Length() > 5)
					  {
						temp = number2.Length() + number1.Length();
					  } else
					  {
						temp = answer.Length();
					  }

					  temp1 = 1;
					  temp = k + temp;
					  while(k < temp)
					  {
						newResult[k] = answer[temp1];
						k++;
						temp1++;
					  }

					  while(k < k + length - i)
					  {
						newResult[k] = result[i+1];
						k++;
						i++;
					  }
					  newResult[k] = '\0';
					  length = k-1;
					  break;
				case '*':
					  if(minus == 1)
					  {
						num2 = 0-num2;
						minus = 0;

					  }
					  if(num1 * num2 < 0)
					  {
						minus = 1;
						operation = result[i];
						answer = FloatToStr(abs(num1 * num2));
					  } else
					  {
						answer = FloatToStr(num1 * num2);
					  }
					  k = 1;
					  while(k < indexnumber1)
					  {
						newResult[k] = result[k];
						k++;
					  }
					  if(answer.Length() > 5)
					  {
						temp = number2.Length() + number1.Length();
					  } else
					  {
						temp = answer.Length();
					  }

					  temp1 = 1;
					  temp = k + temp;
					  while(k < temp)
					  {
						newResult[k] = answer[temp1];
						k++;
						temp1++;
					  }

					  while(k < k + length - i)
					  {
						newResult[k] = result[i+1];
						k++;
						i++;
					  }
					  newResult[k] = '\0';
					  length = k-1;
					  break;
				case '/':
					  if(minus == 1)
					  {
						num1 = 0-num1;
						minus = 0;
					  }
					  if(num1 / num2 < 0)
					  {
						minus = 1;

						operation = result[i];
						answer = FloatToStr(abs(num1 / num2));
					  } else
					  {
						answer = FloatToStr(num1 / num2);
					  }
					  k = 1;
					  while(k < indexnumber1)
					  {
						newResult[k] = result[k];
						k++;
					  }
					  if(answer.Length() > 5)
					  {
						temp = number2.Length() + number1.Length();
					  } else
					  {
						temp = answer.Length();
					  }

					  temp1 = 1;
					  temp = k + temp;
					  while(k < temp)
					  {
						newResult[k] = answer[temp1];
						k++;
						temp1++;
					  }

					  while(k < k + length - i)
					  {
						newResult[k] = result[i+1];
						k++;
						i++;
					  }
					  newResult[k] = '\0';
					  length = k-1;
					  break;
				case '^':
					  if(minus == 1)
					  {
						num2 = 0-num2;
						minus = 0;
					  }
					  answer = FloatToStr(pow(num1, num2));
					  k = 1;
					  while(k < indexnumber1)
					  {
						newResult[k] = result[k];
						k++;
					  }
					  if(answer.Length() > 5)
					  {
						temp = number2.Length() + number1.Length();
					  } else
					  {
						temp = answer.Length();
					  }

					  temp1 = 1;
					  temp = k + temp;
					  while(k < temp)
					  {
						newResult[k] = answer[temp1];
						k++;
						temp1++;
					  }

					  while(k < k + length - i)
					  {
						newResult[k] = result[i+1];
						k++;
						i++;
					  }
					  newResult[k] = '\0';
					  length = k-1;
					  break;
		   }
		  i = 1;
		  imain = i;
		} else
		{
			switch(newResult[i])
			{
			case '+': if(minus == 1)
					  {
						num1 = 0-num1;
						minus = 0;
					  }
					  answer = FloatToStr(num1 + num2);
					  newResult = answer;
					  break;
			case '-': if(minus == 1)
					  {
						num1 = 0-num1;
						minus = 0;
					  }
					  answer = FloatToStr(num1 - num2);
					  newResult = answer;
					  break;
			case '*': if(minus == 1)
					  {
						num1 = 0-num1;
						minus = 0;
					  }
					  answer = FloatToStr(num1 * num2);
					  newResult = answer;
					  break;
			case '/': if(minus == 1)
					  {
						num1 = 0-num1;
						minus = 0;
					  }
					  answer = FloatToStr(num1 / num2);
					  newResult = answer;
					  break;
			case '^': if(minus == 1)
					  {
						num2 = 0-num2;
						minus = 0;
					  }
					  answer = FloatToStr(pow(num1,num2));
					  newResult = answer;
					  break;
			}
            imain = length + 1;
		}

	  //imain = length + 1;
	  //Label2->Caption += String(answer);
	  //Label2->Caption += ' ';
	  //Label2->Caption += String(num1);
	  //Label2->Caption += ' ';
	  //Label2->Caption += String(num2);
	  //Label2->Caption += ' ';
	  Label2->Caption = String(newResult);
	  //Label2->Caption += '\n';
	}


}
//---------------------------------------------------------------------------

