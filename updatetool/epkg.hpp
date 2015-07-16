//
//  epkg.hpp
//  updatetool
//
//  Created by Lucas on 7/16/15.
//  Copyright © 2015 ItsLucas. All rights reserved.
//

#ifndef epkg_cpp
#define epkg_cpp


#include <iostream>
#include <cstdlib>

using namespace std;

void open_epkg(string epkg_path);
void seal_epkg(string directory);
string check_md5(string file);

#endif /* epkg_cpp */
