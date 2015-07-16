//
//  getos.cpp
//  updatetool
//
//  Created by Lucas on 7/16/15.
//  Copyright © 2015 ItsLucas. All rights reserved.
//

#include "getos.hpp"
int getTargetOS()
{
#ifdef WIN32
    return oswin;
#endif
#ifdef linux
    return oslin;
#endif
    return osdarwin;
}