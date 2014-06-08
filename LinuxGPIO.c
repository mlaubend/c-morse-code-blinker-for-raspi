#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include "LinuxGPIO.h"
#include "LinuxGPIOExporter.h"
#include "LinuxFile.h"

LinuxGPIO::LinuxGPIO(int number): LinuxGPIOExporter(number)
{
}

void LinuxGPIO::SetValue(bool value)
  {
    char szFN[128];
    snprintf(szFN, sizeof(szFN),
             "/sys/class/gpio/gpio%d/value", m_Number);
    LinuxFile(szFN).Write(value ? "1" : "0");
  }

void LinuxGPIO::SetDirection(bool isOutput)
  {
    char szFN[128];
    snprintf(szFN, sizeof(szFN),
             "/sys/class/gpio/gpio%d/direction", m_Number);
    LinuxFile(szFN).Write(isOutput ? "out" : "in");
  }

