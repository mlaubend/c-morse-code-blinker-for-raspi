#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include "LinuxFile.h"
#include "LinuxGPIOExporter.h"
#include "LinuxGPIO.h"

bool on = true;
bool off = false;

void dot(LinuxGPIO*);
void dash(LinuxGPIO*);
void pause(LinuxGPIO*);

int main(int argc, char *argv[])
{
  //instantiate gpio17 and set up variables and pointers                        
  LinuxGPIO gpio17(17);
  LinuxGPIO* gpio17ptr;
  gpio17ptr = &gpio17;
  gpio17.SetDirection(true);
  bool isOn = true;
  int MAX_CHAR = 512;
  size_t size;
  char BUFFER[MAX_CHAR];

  // while loop to gather input                                                 
  while(isOn)
    {
      printf("input: ");
      fgets(BUFFER, MAX_CHAR, stdin);

      //count how many characters are in the input                              
      int count = 0;
      for (count; count < MAX_CHAR; count++)
        {
          char first = BUFFER[count];
          if(first == '\0')
            break;
        }

      //convert each character into morse and blink the LED                     
      int i = 0;
      for(i; i < count; i++)
        {
          char ptr = BUFFER[i];
          printf("%c\n", ptr);
          switch(ptr)
            {
            case ' ':
              {
                sleep(1);
                printf("break\n\n");
		break;
              }

            case 'a':
              {
                dot(gpio17ptr);
                dash(gpio17ptr);
                pause(gpio17ptr);
                break;
              }

            case 'b':
              {
                dash(gpio17ptr);
                dot(gpio17ptr);
                dot(gpio17ptr);
		dot(gpio17ptr);
                pause(gpio17ptr);
                break;
              }

	    case 'c':
              {
                dash(gpio17ptr);
                dot(gpio17ptr);
                dash(gpio17ptr);
		dot(gpio17ptr);
                pause(gpio17ptr);
                break;
              }

            case 'd':
              {
                dash(gpio17ptr);
                dot(gpio17ptr);
                dot(gpio17ptr);
        	pause(gpio17ptr);
                break;
              }

            case 'e':
              {
                dot(gpio17ptr);
        	pause(gpio17ptr);
                break;
              }

            case 'f':
              {
                dot(gpio17ptr);
                dot(gpio17ptr);
                dash(gpio17ptr);
        	dot(gpio17ptr);
                pause(gpio17ptr);
                break;
              }

            case 'g':
	      {
                dash(gpio17ptr);
                dash(gpio17ptr);
                dot(gpio17ptr);
                pause(gpio17ptr);
                break;
              }

            case 'h':
              {
                dot(gpio17ptr);
                dot(gpio17ptr);
                dot(gpio17ptr);
                dot(gpio17ptr);
                pause(gpio17ptr);
        	break;
              }

            case 'i':
              {
                dot(gpio17ptr);
                dot(gpio17ptr);
        	pause(gpio17ptr);
                break;
              }

            case 'j':
              {
                dot(gpio17ptr);
                dash(gpio17ptr);
                dash(gpio17ptr);
        	dash(gpio17ptr);
                pause(gpio17ptr);
                break;
              }

            case 'k':
              {
                dash(gpio17ptr);
        	dot(gpio17ptr);
                dash(gpio17ptr);
                pause(gpio17ptr);
        	break;
              }

            case'l':
              {
                dot(gpio17ptr);
        	dash(gpio17ptr);
                dot(gpio17ptr);
                dot(gpio17ptr);
                pause(gpio17ptr);
		break;
              }

            case 'm':
              {
                dash(gpio17ptr);
                dash(gpio17ptr);
                pause(gpio17ptr);
                break;
              }

            case 'n':
              {
                dash(gpio17ptr);
                dot(gpio17ptr);
                pause(gpio17ptr);
                break;
	      }

            case 'o':
              {
                dash(gpio17ptr);
                dash(gpio17ptr);
                dash(gpio17ptr);
        	pause(gpio17ptr);
                break;
              }

            case 'p':
              {
                dot(gpio17ptr);
                dash(gpio17ptr);
                dash(gpio17ptr);
        	dot(gpio17ptr);
                pause(gpio17ptr);
                break;
              }

            case 'q':
              {
                dash(gpio17ptr);
        	dash(gpio17ptr);
                dot(gpio17ptr);
                dash(gpio17ptr);
                pause(gpio17ptr);
		break;
              }

            case 'r':
              {
        	dot(gpio17ptr);
                dash(gpio17ptr);
                dot(gpio17ptr);
                pause(gpio17ptr);
		break;
              }

            case 's':
              {
                dot(gpio17ptr);
                dot(gpio17ptr);
                dot(gpio17ptr);
                pause(gpio17ptr);
                break;
              }

            case 't':
              {
                dash(gpio17ptr);
                pause(gpio17ptr);
                break;
	      }

            case 'u':
              {
                dot(gpio17ptr);
                dot(gpio17ptr);
                dash(gpio17ptr);
        	pause(gpio17ptr);
                break;
              }

            case 'v':
              {
                dot(gpio17ptr);
                dot(gpio17ptr);
                dot(gpio17ptr);
        	dash(gpio17ptr);
                pause(gpio17ptr);
                break;
              }

            case 'w':
              {
                dot(gpio17ptr);
        	dash(gpio17ptr);
                dash(gpio17ptr);
                pause(gpio17ptr);
                break;
              }

            case 'x':
              {
                dash(gpio17ptr);
                dot(gpio17ptr);
                dot(gpio17ptr);
        	dash(gpio17ptr);
                pause(gpio17ptr);
                break;
              }

            case 'y':
              {
                dash(gpio17ptr);
                dot(gpio17ptr);
                dash(gpio17ptr);
                dash(gpio17ptr);
                pause(gpio17ptr);
		break;
              }

            case 'z':
              {
                dash(gpio17ptr);
                dash(gpio17ptr);
	        dot(gpio17ptr);
                dot(gpio17ptr);
		pause(gpio17ptr);
                break;
              }

            case '0':
              {
                dash(gpio17ptr);
        	dash(gpio17ptr);
                dash(gpio17ptr);
                dash(gpio17ptr);
        	dash(gpio17ptr);
                pause(gpio17ptr);
                break;
              }

            case '1':
              {
                dot(gpio17ptr);
                dash(gpio17ptr);
                dash(gpio17ptr);
		dash(gpio17ptr);
                dash(gpio17ptr);
                pause(gpio17ptr);
                break;
              }

            case '2':
              {
                dot(gpio17ptr);
                dot(gpio17ptr);
		dash(gpio17ptr);
                dash(gpio17ptr);
                dash(gpio17ptr);
        	pause(gpio17ptr);
                break;
              }

            case '3':
              {
                dot(gpio17ptr);
                dot(gpio17ptr);
                dot(gpio17ptr);
        	dash(gpio17ptr);
                dash(gpio17ptr);
                pause(gpio17ptr);
                break;
              }

            case '4':
              {
                dot(gpio17ptr);
                dot(gpio17ptr);
        	dot(gpio17ptr);
                dot(gpio17ptr);
                dash(gpio17ptr);
        	pause(gpio17ptr);
                break;
              }

            case '5':
              {
                dot(gpio17ptr);
                dot(gpio17ptr);
	        dot(gpio17ptr);
                dot(gpio17ptr);
                dot(gpio17ptr);
                pause(gpio17ptr);
                break;
              }

            case '6':
              {
                dash(gpio17ptr);
                dot(gpio17ptr);
        	dot(gpio17ptr);
                dot(gpio17ptr);
                dot(gpio17ptr);
        	pause(gpio17ptr);
                break;
              }

            case '7':
              {
                dash(gpio17ptr);
                dash(gpio17ptr);
        	dot(gpio17ptr);
                dot(gpio17ptr);
                dot(gpio17ptr);
                pause(gpio17ptr);
                break;
	      }

            case '8':
              {
                dash(gpio17ptr);
                dash(gpio17ptr);
        	dash(gpio17ptr);
                dot(gpio17ptr);
                dot(gpio17ptr);
        	pause(gpio17ptr);
                break;
              }

            case '9':
              {
                dash(gpio17ptr);
                dash(gpio17ptr);
        	dash(gpio17ptr);
                dash(gpio17ptr);
                dot(gpio17ptr);
                pause(gpio17ptr);
                break;
              }
            }//end switch                                                       
        }//end for                                                              
    }//end while                                                                
}//end main                                                                     

//function call to blink the LED as a "dot"                                     
void dot(LinuxGPIO* gpio17ptr)
{
  struct timespec tim, tim2, pause, pause2;
  tim.tv_sec = 0;
  tim.tv_nsec = 300000000L; //change this to increase/decrease dot length       

  (*gpio17ptr).SetValue(on);
  nanosleep(&tim, &tim2);
  printf("dot\n");
  (*gpio17ptr).SetValue(off);
  nanosleep(&tim, &tim2);
}

//function call to blnk the LED as a "dash"                                     
void dash(LinuxGPIO* gpio17ptr)
{

  struct timespec pause, pause2, tim, tim2;
  pause.tv_sec = 0;
  tim.tv_sec = 0;
  tim.tv_nsec = 600000000L; //change this to increase/decrease dash length      
  pause.tv_nsec = 300000000L; //pause length between letters                    

  (*gpio17ptr).SetValue(on);
  nanosleep(&tim, &tim2);
  printf("dash\n");
  (*gpio17ptr).SetValue(off);
  nanosleep(&pause, &pause2);
}

//pause length between letters                                                  
void pause(LinuxGPIO* gpio17ptr)
{
  struct timespec pause, pause2;
  pause.tv_sec = 0;
  pause.tv_nsec = 500000000L;
  nanosleep(&pause, &pause2);
}

