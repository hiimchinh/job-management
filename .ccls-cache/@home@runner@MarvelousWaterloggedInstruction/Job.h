#ifndef _JOB_
#define _JOB_

#include <iostream>
#include <string>
using namespace std;

class Job
{
private:
  int id;
  string content, title, status;

public:
  Job() {}

  Job(string content, string title, string status)
  {
    static int _id = 1;
    id = _id++;
    this->content = content;
    this->title = title;
    this->status = status;
  }
  string getId() {
    return to_string(id);
  }
  string getContent() {
    return content;
  }
  string getTitle() {
    return title;
  }
  string getStatus() {
    return status;
  }
  void print() {
    cout << "Mã công việc: " << to_string(id) << endl;
    cout << "Nội dung công việc: " << content << endl;
    cout << "Tiêu đề công việc: " << title << endl;
    cout << "Trạng thái công việc: " << status << endl;
  }
  void setContent(string content) {
    this->content = content;
  }
  void setTitle(string title) {
    this->title = title;
  }
  void setStatus(string status) {
    this->status = status;
  }
  bool kiemTraTrungTrangThai(string status) {
    size_t found = this->status.find(status);
    return found != string::npos;
  }
};

#endif