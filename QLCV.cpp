#include <iostream>
#include "QLCV.h"
#include "Job.h"
#include <fstream>
using namespace std;

void QLCV::inMenu()
{
  cout << "1. Hiển thị danh sách công việc\n";
  cout << "2. Thêm công việc\n";
  cout << "3. Sửa công việc\n";
  cout << "4. Chuyển trạng thái công việc\n";
  cout << "5. Lọc theo trạng thái công việc\n";
  cout << "6. Kết thúc chương trình\n";
}

void QLCV::inCongViec()
{
  for (int i = 0; i < n; i++)
  {
    jobs[i].print();
    cout << "------" << endl;
  }
  cout << "Tổng số công việc hiện tại: " << n << endl;
}

void QLCV::themCongViec()
{
  cout << "Mời bạn nhập nội dung công việc: ";
  string content;
  getline(cin, content);
  cout << "Mời bạn nhập tiêu đề công việc: ";
  string title;
  getline(cin, title);
  cout << "Mời bạn chọn trạng thái của công việc này: ";
  string status;
  getline(cin, status);
  Job job(content, title, status);
  jobs[n] = job;
  n++;
  this->saveFile();
}

void QLCV::capNhatCongViec()
{
  cout << "Mời bạn nhập id công việc bạn muốn cập nhật: ";
  int pos = -1;
  string id, content, title, status;
  cin >> id;
  cin.ignore();
  for (int i = 0; i < n; i++) {
    if (id == jobs[i].getId()) {
      pos = i;
      break;
    }
  }
  if (pos == -1) {
    cout << "Không tìm thấy công việc có id là: " << id << endl;
  } else {
    cout << "Mời bạn nhập nội dung công việc: ";
    getline(cin, content);
    cout << "Mời bạn nhập tiêu đề công việc: ";
    getline(cin, title);
    cout << "Mời bạn nhập trạng thái công việc: ";
    getline(cin, status);
    jobs[pos].setContent(content);
    jobs[pos].setTitle(title);
    jobs[pos].setStatus(status);
    this->saveFile();
  }
}

void QLCV::capNhatTrangThai()
{
  cout << "Mời bạn nhập id công việc bạn muốn cập nhật trạng thái: ";
  string id, status;
  int pos = -1;
  cin >> id;
  cin.ignore();
  for (int i = 0; i < n; i++) {
    if (jobs[i].getId() == id) {
      pos = i;
      break;
    }
  }
  if (pos == -1) {
    cout << "Không tìm thấy công việc có id là: " << id << endl;
  } else {
    cout << "Mời bạn chọn trạng thái bạn muốn cập nhật: ";
    getline(cin, status);
    jobs[pos].setStatus(status);
    this->saveFile();
    cout << "Cập nhật trạng thái thành công!" << endl; 
  }
}

void QLCV::locTrangThai()
{
  cout << "Mời bạn nhập tên trạng thái muốn lọc: ";
  string tuKhoa;
  getline(cin, tuKhoa);
  int soCongViec = 0;
  for (int i = 0; i < n; i++)
  {
    bool timThay = jobs[i].kiemTraTrungTrangThai(tuKhoa);
    if (timThay)
    {
      soCongViec++;
      jobs[i].print();
      cout << "-----\n";
    }
  }
  cout << "Số công việc tìm thấy là: " << soCongViec << endl;
}

void QLCV::loadFile()
{
  fstream file("data.txt", ios::in);
  file >> n;
  file.ignore();
  for (int i = 0; i < n; i++)
  {
    string content, title, status;
    getline(file, content);
    getline(file, title);
    getline(file, status);
    jobs[i] = Job(content, title, status);
  }
}

void QLCV::saveFile()
{
  fstream file("data.txt", ios::out);
  file << n << endl;
  for (int i = 0; i < n; i++)
  {
    Job job = jobs[i];
    file << job.getContent() << endl;
    file << job.getTitle() << endl;
    file << job.getStatus() << endl;
  }
  file.close();
}