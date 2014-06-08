#ifndef LINUXGPIO
#define LINUXGPIO

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include "LinuxGPIOExporter.h"

class LinuxGPIO: public LinuxGPIOExporter
{
 public:
  LinuxGPIO(int);
  void SetValue(bool);
  void SetDirection(bool);
};

#endif

