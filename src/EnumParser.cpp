/*
 * EnumParser.cpp
 *
 *  Created on: 2014-8-6
 *      Author: jianmink
 */


#include "EnumParser.h"
#include <ctype.h>

bool parseFqdn(std::string fqdn, std::string& zone, std::string& dn)
{
    const char* s=fqdn.c_str();
    int len=fqdn.length();


    if(s[0]=='-' || s[len-1]=='-')
    {
        //illegal format
        return false;
    }

    char c_dn[64+1];
    c_dn[64]=0;
    int j=63;
    int p=0;
    int c_dn_len=0;


    const char delim='.';
    int dist=0;
    for(int i=0; i<len; i++)
    {
        const char c=s[i];

        if(c==delim)
        {
            if(i==0){
                return false;
            }

            if(s[i-1]==delim)
                return false;

            if(dist==1){
                c_dn[j--]=s[i-1];
                c_dn_len++;
                dist=0;
            }

            if(dist>1){
                p=i-dist;
                dist=0;
                break;
            }
        }
        else if(isalnum(c) || c=='-')
        {
            if(!isdigit(c))
            {
                p=i-dist;
                dist=0;
                break;
            }
            dist+=1;

        }
        else
        {
            //illegal format.
            return false;
        }
    }


    if(dist==1)
    {
        c_dn[j--]=s[len-1];
        c_dn_len+=1;
        p=len;
    }
    else if(dist>1)
    {
        p=len-dist;
    }

    if(s[p]=='-')
    {
        //illegal format
        return false;
    }

    dn=std::string(c_dn+64-c_dn_len);
    zone=std::string(s+p);

    return true;
}

