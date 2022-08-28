#include <iostream>
#include "regex.h"
#include "htable.h"
#include "eval.h"

using namespace std;

string varCheck(string exp)
{
    string varKey="none";
    string a,b;
    int i=0;
    for (i=0;i<exp.length();++i)
    {
        if (isalpha(exp[i]) && isdigit(exp[i+1]))
        {
           a=exp[i];
           b=exp[i+1];
           varKey=a+b;
        }
    }
    return varKey;
}

int main(int argc, char *argv[])
{
			//header
	cout<<"+-----------------------------------------------------------+"<<endl;
	cout<<"|               Computer Science and Engineering            |"<<endl;
	cout<<"|               CSCE 2110 - Project 2: Calculator           |"<<endl;
	cout<<"|                         Group 7                           |"<<endl;
	cout<<"+-----------------------------------------------------------+"<<endl;
		// end of header

    string str="";
    string var[5];
    HashMap hash;
    string key;
    int value;

    while (str!="quit")
    {

        cout<<"Enter command you want to operate / quit to exit: ";
        getline(cin, str);

        while (!createMatches(str) && !deleteMatches(str) && 
            !printMatches(str) && !makeExpression(str) && str!="quit")
        {
            cout<<"Invalid statement.\nEnter again: ";
            getline(cin,str);
        }

        if (createMatches(str)==1)
        {
            //var[0]=str.substr(7,2).c_str(); //get var by using substr

            if (hash.Match(decodeSt(str))) //get var by regex
            {
                cout<<"Variable is already existed.\n";
            }
            else
                hash.Insert(decodeSt(str),0);

        }

        else if (deleteMatches(str)==1)
        {
            //var[1]=str.substr(7,2).c_str();
            hash.Delete(decodeSt(str));

        }

        else if (printMatches(str)==1)
        {
            //var[2]=str.substr(6,2).c_str();
            //print out the result of that variable
            hash.Search(decodeSt(str));

        }

        else if (makeExpression(str)==1)
        {
            int myvar;
            string tempVar;
            tempVar=decodeVar(str); //get variable
            //var[3]=str.substr(0,2).c_str(); //get variable
            var[4]=str.substr(4,str.length()-1); //get expression string
  
            //check if the variable is valid
            if (hash.Match(tempVar))
            {
                //if expression contain variable, check if that variable exists
                myvar=hash.getValue(varCheck(var[4]));
                if (myvar == 0) //variable in expression not exist
                    {
                        //if the variable in the expression does not exist,
                        //the program will be exited, all the data entered prior that will be lost,
                        //make sure you entered an already existed one
                        cout<<"Variable "<<varCheck(var[4])<< " does not exist.\n";
                        return 1;
                    }
                else if (myvar == -1) //no variable in the expression, execute normally
                    {
                        hash.Update(tempVar,eval(var[4])); 
                    }
                else //with existed variable
                    {
                        //if the variable is positive, execute normally
                        if (myvar>=0)
                        {
                            //replace the value of that variable to evaluate
                            var[4].replace(var[4].find(varCheck(var[4])), 2, to_string(myvar));
                            hash.Update(tempVar,eval(var[4])); 
                        }
                        //if variable is negative, change to positive and add ~ to parse to command
                        else
                        {
                            myvar=(-1)*myvar;
                            var[4].replace(var[4].find(varCheck(var[4])), 2, "~"+to_string(myvar));
                            hash.Update(tempVar,eval(var[4])); 
                        }
                    }
            }
            else
            {
                cout<<"Variable "<<var[4]<<" does not exist.\n";
            }

        }
    }

    return 0;
}
