#include "stdafx.h"
#include "cSquareMatrix.h"
#include <iostream>
using namespace std;
cSquareMatrix::cSquareMatrix(int *iM, unsigned int uiForm)
{
    //cout << ">>Konstruktor\n";
    iM_ = new int[uiForm*uiForm*sizeof (int)];
    memcpy (iM_, iM, uiForm*uiForm*sizeof (int));
    uiForm_ = uiForm;
}
cSquareMatrix::cSquareMatrix (void) 
{
    //cout << ">>(Default-)Konstruktor\n";
    iM_ = NULL;
}
cSquareMatrix::~cSquareMatrix(void)
{
    //cout << ">>~Destruktor\n";
    delete [] iM_;
}
cSquareMatrix cSquareMatrix::operator * (cSquareMatrix& iMIn)
{
    int *iMRes = new int[uiForm_*uiForm_*sizeof (int)];
    memcpy (iMRes, iMIn.iM_, uiForm_*uiForm_*sizeof (int));
    for (int i=0; i<(int)(uiForm_*uiForm_); i++)
        iMRes[i] *= iM_[i];
    cSquareMatrix *SqrM = new cSquareMatrix(iMRes, uiForm_);            
    delete []iMRes;                                  
    return *SqrM;       
}
int *cSquareMatrix::getMatrix (void)
{
    return iM_;
}