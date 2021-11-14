#include <iostream>
#include <string>
#include <time.h>
#include <math.h>
using namespace std;
//creating a template to make stacks for validation of infix
class stack
{
public:
    int top = -1;
    char stackArr[100] = {'a'};

    char Pop()
    {
        char element;
        if (!isEmpty())
        {
            element = stackArr[top];
            stackArr[top--] = 'a';
        }
        return element;
    }
    bool isEmpty()
    {
        return top < 0;
    }
    void Push(char element)
    {
        if (top < 100)
        {
            stackArr[++top] = element;
        }
    }
};
// this method is used to determine the precedence of operators which can be later used to convert the infix to postfix
int findingPrecedence(char oper)
{
    if (oper == '^')
    {
        return 1;
    }
    else if (oper == '*' || oper == '/')
    {
        return 2;
    }
    else if (oper == '-' || oper == '+')
    {
        return 3;
    }
    else
        return 0;
}
//the actual method to validate the infix operation in which the infix will be passed as a parameter
void validation(string str)
{
    //checking if the parenthesis are alright
    stack chars;
    for (char i : str)
    {
        if (i == '(')
        {
            chars.Push('(');
        }
        else if (i == ')')
        {
            if (chars.isEmpty())
            {
                chars.Push('(');
            }
            else
            {
                chars.Pop();
            }
        }
    }
    //checking if the operators are alright
    bool operatorValid;
    for (int j; j < str.length(); j++)
    {
        if ((str[j] == '+' || str[j] == '-' || str[j] == '*' || str[j] == '/' || str[j] == '^') && (isdigit((int)str[j - 1]) && isdigit((int)str[j + 1])))
        {
            operatorValid = true;
        }
        else
            operatorValid = false;
    }
}
//the function that converts a valid infix expression into postfix
void convertToPostfix(string str)
{
    validation(str);

    stack goodStack;
    string outputString = "";
    for (char i : str)
    { //traversing through the given expression
        if (isdigit((int)i))
        { //if number is a digit it is appended to the output as such
            outputString = outputString + i;
        }
        else if (i == '(')
        { //if the number is  a opening brace, it is pushed to the end of the stack
            goodStack.Push(i);
        }
        else if (i == ')')
        { //if closing brace is encountered then all the operators are popped and appended to the output unless the opening brace is encountered
            char j;
            while (j != '(')
            {
                j = goodStack.Pop();
                if (j != '(')
                    outputString = outputString + j;
            }
        }
        else if (i == '+' || i == '-' || i == '*' || i == '/' || i == '^')
        { //if operator is encountered then the stck is checked for higher or equal precedence operators so they can be popped and added to the end of the output
            for (char myChar : goodStack.stackArr)
            {
                if ((myChar == '+' || myChar == '-' || myChar == '*' || myChar == '/' || myChar == '^') && findingPrecedence(myChar) <= findingPrecedence(i))
                {
                    char thisChar = goodStack.Pop();
                    outputString = outputString + thisChar;
                }
            }
            goodStack.Push(i);
        }
    } //after all the traversing is complete, the stack is checked for any operators. if any operators are found they are added to the end of the output
    while (!goodStack.isEmpty())
    {
        char toPop = goodStack.Pop();
        if (toPop != '(' && toPop != ')')
            outputString = outputString + toPop;
    }
    cout << outputString << endl;
}
int main()
{
    string theInfix;

    cout << "Please enter the infix: ";
    cin >> theInfix;
    convertToPostfix(theInfix);
}