//
//  epkg.cpp
//  updatetool
//
//  Created by Lucas on 7/16/15.
//  Copyright © 2015 ItsLucas. All rights reserved.
//

#include "epkg.hpp"
#include "md5.hpp"
#include "getos.hpp"
#include "StringBuilder.cpp"
using namespace std;
string cal_md5(const string &file)
{
    ifstream in(file.c_str(), ios::binary);
    if (!in)
        return "";
    
    MD5 md5;
    std::streamsize length;
    char buffer[1024];
    while (!in.eof()) {
        in.read(buffer, 1024);
        length = in.gcount();
        if (length > 0)
            md5.update(buffer, length);
    }
    in.close();
    return md5.toString();
}
void seal_epkg(string directory,string epkg_name)
{
    StringBuilder<char> *sb = new StringBuilder<char>();
    if(getTargetOS()==oswin)
    {
        string a = "7za.exe a ";
        sb->Append(a);
        sb->Append(epkg_name);
        string b = " ";
        sb->Append(directory);
        string result = sb->ToString();
        system(result.c_str());
    }
    else if(getTargetOS()==osdarwin||getTargetOS()==oslin)
    {
        
        string a = "7za a ";
        sb->Append(a);
        sb->Append(epkg_name);
        string b = " ";
        sb->Append(directory);
        string result = sb->ToString();
        system(result.c_str());
    }
}
void open_epkg(string epkg_path)
{
    StringBuilder<char> *sb = new StringBuilder<char>();
    if(getTargetOS()==oswin)
    {
        string a = "7za.exe x ";
        sb->Append(a);
        sb->Append(epkg_path);
        string result = sb->ToString();
        system(result.c_str());
}
    else if(getTargetOS()==osdarwin||getTargetOS()==oslin)
    {
        string a = "7za.exe x ";
        sb->Append(a);
        sb->Append(epkg_path);
        string result = sb->ToString();
        system(result.c_str());
    }
}
