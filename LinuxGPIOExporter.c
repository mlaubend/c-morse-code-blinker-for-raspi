#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include "LinuxFile.h"
#include "LinuxGPIOExporter.h"


LinuxGPIOExporter::LinuxGPIOExporter(int number): m_Number(number)
  {
    LinuxFile("/sys/class/gpio/export", O_WRONLY).Write(number);
  }

LinuxGPIOExporter::~LinuxGPIOExporter()
    {
      LinuxFile("/sys/class/gpio/unexport",
                O_WRONLY).Write(m_Number);
    }
