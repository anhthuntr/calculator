#include "eval.h"

using namespace std;
int isOperand(char x)
{
    if(x == '+' || x=='-'|| x=='*' || x=='/')
        return 0;
    return 1;
}

int isMinus(char x)
{
    if (x=='~')
        return 1;
    return 0;
}

int eval(string key)
{
    queue<int> isVal; //to store integer values
    queue<char> isOp; //to store operator
    queue<char> isNeg;
    int i,x,y,z;
    int newVal;
    bool flag=false;
    i=0;
    while (key[i]!='\0')
    {
        if (isMinus(key[i]))
        {
            isNeg.push(key[i++]);
            flag=true;
        }

        //current token is a number with more than 1 digits, push it
        else if (isdigit(key[i])) 
        {
            int value = 0;
            while (isdigit(key[i]))
                {
                    value = value * 10 + key[i++] - '0';
                }
            
            while (flag)
            {
                value=(-1)*value;
                flag=false;
            }
            isVal.push(value);
        }
        
        //current token is an operator and op queue is empty
        else if(!isOperand(key[i]) && isOp.empty())
            {
                //push operator into queue
                isOp.push(key[i++]);
                
            }
        
        
        //current token is operator and operator queue is not empty
        else if(!isOperand(key[i]) && !isOp.empty() )
        {
            
                    x=isVal.front();
                    isVal.pop();
                    
                    y=isOp.front();
                    isOp.pop();
                    
                    z=isVal.front();
                    isVal.pop();
                    
                    if(y == '+')
                        isVal.push(z+x);
                    else if(y == '-')
                        isVal.push(x-z);
                    else if(y == '*')
                        isVal.push(x*z);
                    else if(y == '/')
                        isVal.push(x/z);
                
        }
    }
    
    //only negate number
    while (isOp.empty() && flag==1)
    {
        newVal=isVal.front();
        isVal.pop();
        newVal=(-1)*newVal;
        isVal.push(newVal);
        flag=false;
    }
    //last operator
    while(!isOp.empty() )
    {
           
            x = isVal.front();
            isVal.pop();
    
            y = isOp.front();
            isOp.pop();
    
            z = isVal.front();
            isVal.pop();
            
            if(y == '+')
                isVal.push(z+x);
            else if(y == '-')
                isVal.push(x-z);
            else if(y == '*')
                isVal.push(x*z);
            else if(y == '/')
                isVal.push(x/z);

            
    }

    return isVal.front();
}