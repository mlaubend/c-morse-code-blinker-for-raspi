#ifndef LINUXFILE
#define LINUXFILE

#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>

class LinuxFile
{
 private:
  int m_Handle;

 public:
  LinuxFile(const char*, int flags = O_RDWR);
  ~LinuxFile();
  size_t Write(const void*, size_t);
  size_t Read(void*, size_t);
  size_t Write(const char*);
  size_t Write(int);
};

#endif

