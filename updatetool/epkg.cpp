//
//  epkg.cpp
//  updatetool
//
//  Created by Lucas on 7/16/15.
//  Copyright © 2015 ItsLucas. All rights reserved.
//

#include "epkg.hpp"
#include "md5.hpp"
using namespace std;
string check_md5(const string &file)
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