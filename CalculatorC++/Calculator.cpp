

#include<iostream>
#include<cmath>
#include<stdio.h>
#include<cstdlib>
#include<map>
#include<stack>

using namespace std;
int expression_value(string str)
{
    map<char,int>priority;
    priority['^']=3;v
    priority['*']=2,priority['/']=2;
    priority['+']=1,priority['-']=1;

    stack<char>op_stack;
    stack<int>val_stack;

    int val=0;
    for(int i=0;str[i];i++)
    {
        if(str[i]>='0'&&str[i]<='9')
          val=val*10+str[i]-'0';
        elsev
        {
            if(op_stack.empty()) // first operator
            {
                val_stack.push(val);
                op_stack.push(str[i]);
            }
            else if(priority[op_stack.top()] < priority[str[i]]) // current operator is more prior then previous operator. so push it to stack.
            {
                val_stack.push(val);
                op_stack.push(str[i]);
            }
            else // current operator is less prior then previous operator. so calculate previous operators resultant value
            {
                int num1,num2;
                num1=val_stack.top(); val_stack.pop();
                num2=val;
                if(op_stack.top()=='+')
                  //val_stack.push(addition(num1, num2));
                  val_stack.push(num1 + num2);
                else if(op_stack.top()=='-')
                  //val_stack.push(subtraction(num1, num2));
                  val_stack.push(num1 - num2);
                else if(op_stack.top()=='*')
                  //val_stack.push(multiplication(num1, num2));
                  val_stack.push(num1 * num2);
                else if(op_stack.top()=='/')
                  //val_stack.push(division(num1, num2));
                  val_stack.push(num1 / num2);
                else
                  //val_stack.push(exponential(num1, num2));
                  val_stack.push(pow(num1 , num2));
                op_stack.pop(); // as operator's value calculation done, pop it from the stack
                op_stack.push(str[i]); // push the new operator
            }
            val=0;
        }
    }
    val_stack.push(val); // last value

    // calculate remaining operators value
    while(!op_stack.empty())
    {
        int num1,num2;
        num2=val_stack.top(); val_stack.pop();
        num1=val_stack.top(); val_stack.pop();
        if(op_stack.top()=='+')
            //val_stack.push(addition(num1, num2));
            val_stack.push(num1 + num2);
        else if(op_stack.top()=='-')
            //val_stack.push(subtraction(num1, num2));
            val_stack.push(num1 - num2);
        else if(op_stack.top()=='*')
            //val_stack.push(multiplication(num1, num2));
            val_stack.push(num1 * num2);
        else if(op_stack.top()=='/')
            //val_stack.push(division(num1, num2));
            val_stack.push(num1 / num2);
        else
            //val_stack.push(exponential(num1, num2));
            val_stack.push(pow(num1 , num2));
        op_stack.pop();
    }
    return val_stack.top();
}


