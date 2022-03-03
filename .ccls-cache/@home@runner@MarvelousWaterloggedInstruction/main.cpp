#include <iostream>
#include "Job.h"
#include "QLCV.h"

using namespace std;
 
int main() {
  QLCV qlcv;
  cout << "Chương trình quản lý công việc\n";
  qlcv.loadFile();
  int chucNang;
  do
  {
    qlcv.inMenu();
    cout << "Mời bạn chọn chức năng: ";
    cin >> chucNang;
    cin.ignore();
    cout << "-----" << endl;
    
    switch (chucNang)
    {
    case 1:
      qlcv.inCongViec();
      break;
    case 2:
      qlcv.themCongViec();
      break;
    case 3:
      qlcv.capNhatCongViec();
      break;
    case 4:
      qlcv.capNhatTrangThai();
      break;
    case 5:
      qlcv.locTrangThai();
      break;
    case 6:
      cout << "Chương trình kết thúc. Cảm ơn bạn đã sử dụng chương trình!\n";
      break;
    default:
      cout << "Chức năng chưa hỗ trợ. Vui lòng chọn lại.\n";
      break;
    }
  } while (chucNang != 6);
  return 0;
}