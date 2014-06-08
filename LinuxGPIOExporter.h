#ifndef LINUXGPIOEXPORTER
#define LINUXGPIOEXPORTER

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>

class LinuxGPIOExporter
{
 protected:
  int m_Number;

 public:
  LinuxGPIOExporter(int);
  ~LinuxGPIOExporter();
};

#endif

