#include "regex.h"

bool createMatches(string str)
{
        regex reg("(^create [A-Z][0-9]$)");

        return regex_match(str,reg);
 
}

bool deleteMatches(string str)
{
    regex reg("(^delete [A-Z][0-9]$)");

    return regex_match(str,reg);
}

bool printMatches(string str)
{
    regex reg("(print [A-Z][0-9]$)");

    return regex_match(str,reg);
}

bool makeExpression(string str)
{
    regex reg("(^[A-Z][0-9]:=[^ =,(,),!,@,#,_,\\$,%,\\^,&,<,>,\\,,\\,\?,a-z][^ =,(,),!,@,#,_,\\$,%,\\^,&,<,>,\\,,\\,\?,a-z]*)");

    return regex_match(str,reg);
}

string decodeSt(string s)
{
    //std::string s =  "create A1";
    regex re("([A-Z][0-9])");    
    using reg_itr = regex_token_iterator<string::iterator>;
    string tmp;
    for (reg_itr it{s.begin(), s.end(), re, 1}, end{}; it != end;++it) {            
        tmp=*it;
    }

    return tmp;
}

string decodeVar(string s)
{
    regex re("(^[A-Z][0-9])");
    using reg_itr = regex_token_iterator<string::iterator>;
    string tmp;
    for (reg_itr it{s.begin(), s.end(), re, 1}, end{}; it != end;++it) {            
        tmp=*it;
    }

    return tmp;

}
