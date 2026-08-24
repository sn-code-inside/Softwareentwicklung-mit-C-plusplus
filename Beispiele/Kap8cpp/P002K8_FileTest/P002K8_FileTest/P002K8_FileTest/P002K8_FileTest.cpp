//P002K8_FileTest.cpp
#include "stdafx.h"
#include "P002K8_fileUtil.h"
#include <iostream>
using namespace std;
int main(void) {
    cFUtils file("..\\Debug\\P002K8_FileTest.EXE");
    bool bExist = file.fileExist();
    if(bExist == 1) {
        cout << "File P002K8_FileTest.EXE vorhanden.\n";
        return 1;
    }
    else {
    cout << "File P002K8_FileTest.EXE nicht vorhanden.\n";
    return 0;
    }
 }