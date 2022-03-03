#ifndef _QLCV_
#define _QLCV_
#include <iostream>
#include "Job.h"
using namespace std;

class QLCV
{
  private:
    int n = 0;
    Job jobs[500];

  public:
    QLCV()
    {
    }
    void inMenu();
    void inCongViec();
    void themCongViec();
    void capNhatCongViec();
    void capNhatTrangThai();
    void locTrangThai();
    void loadFile();
    void saveFile();
};
#endif