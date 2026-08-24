#pragma once
class cSquareMatrix
{
public:
    cSquareMatrix(int *iM, unsigned int uiForm);
    cSquareMatrix (void);
    cSquareMatrix operator * (cSquareMatrix& iMIn);
    ~cSquareMatrix(void);
    int *getMatrix (void);
private: 
    int *iM_;
    unsigned int uiForm_;
};
