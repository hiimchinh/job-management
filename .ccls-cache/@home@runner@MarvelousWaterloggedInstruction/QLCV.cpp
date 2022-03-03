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