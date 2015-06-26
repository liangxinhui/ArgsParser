/* 
 * File:   ArgsParser.h
 * Author: liangxh
 *
 * Created on 2015年6月26日, 上午9:16
 */

#ifndef ARGSPARSER_H
#define	ARGSPARSER_H

#include <map>
#include <string>
class ArgsParser
{
public:
    ArgsParser(){}
    ArgsParser(int argc, char** argv)
    {
        Parse(argc, argv);
    }
    void Parse(int argc, char** argv)
    {
        m_mapArgs.clear();
        char cOption = 0;
        char cOptionNext = 0;
        for(int i=1; i<argc; ++i)
        {
            if(ItemType_Option == CheckItemType(argv[i], cOption))
            {
                if(i+1<argc && (ItemType_Value == CheckItemType(argv[i+1], cOptionNext)))
                {                 
                    m_mapArgs[cOption] = argv[i+1];
                    ++i;
                }
                else
                {
                    m_mapArgs[cOption] = "";                        
                }
            }
        }        
        return;
    }
    
    std::string GetOption(char cOption)
    {
        std::map<char,std::string>::iterator it = m_mapArgs.find(cOption);
        if(it == m_mapArgs.end())
        {
            return "";
        }
        return it->second;
    }
    
    bool HaveOption(char cOption)
    {
        std::map<char,std::string>::iterator it = m_mapArgs.find(cOption);
        return (it != m_mapArgs.end());
    }
    
private:
    enum ItemType
    {
        ItemType_Option, // eg: -a  -b ... -z  -A -B ... -Z
        ItemType_Value,  // eg: somestring 123456 ...
        ItemType_Invalid // eg: -1 -? -ab -asomestring ...
    };    
    ItemType CheckItemType(const char* pRawString , char &cOption)
    {
        cOption = 0;
        if(pRawString[0] == '-')
        {         
            if(pRawString[2]=='\0')
            {
                if((pRawString[1] >= 'a' && pRawString[1] <= 'z') || (pRawString[1] >= 'A' && pRawString[1] <= 'Z'))
                {
                    cOption = pRawString[1];
                    return ItemType_Option;
                }  
            }
            return ItemType_Invalid;                
        }
        return ItemType_Value;
    }
private:
    std::map<char,std::string> m_mapArgs;
};

#endif	/* ARGSPARSER_H */

