#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include "LinuxFile.h"

LinuxFile::LinuxFile(const char *pFile, int flags)
    {
      m_Handle = open(pFile, flags);
    }

LinuxFile::~LinuxFile()
    {
      if (m_Handle != -1)
        close(m_Handle);
    }

size_t LinuxFile::Write(const void *pBuffer, size_t size)
  {
    return write(m_Handle, pBuffer, size);
  }

size_t LinuxFile::Read(void *pBuffer, size_t size)
  {
    return read(m_Handle, pBuffer, size);
  }

size_t LinuxFile::Write(const char *pText)
  {
    return Write(pText, strlen(pText));
  }

size_t LinuxFile::Write(int number)
  {
    char szNum[32];
    snprintf(szNum, sizeof(szNum), "%d", number);
    return Write(szNum);
  }

