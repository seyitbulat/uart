#include "UartRx.h"
#include "UartTx.h"
#include <stdio.h>

int main() {
  UartRx reciever;
  UartTx transmitter;

  UartRx_Init(&reciever);
  UartTx_Init(&transmitter);

  UartTx_Send(&transmitter, 'A');

  for (int clock = 0; clock < 15; ++clock) {
    reciever.RX = transmitter.TX;
    UartTx_Tick(&transmitter);
    UartRx_Tick(&reciever);
  }
  printf("%c\n", reciever.shifRegister);
  return 0;
}