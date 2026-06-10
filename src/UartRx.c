#include "UartRx.h"

void UartRx_Init(UartRx* uart) {
  uart->counter = 0b0;
  uart->RX = 0b1;
  uart->state = RX_IDLE;
  uart->shifRegister = 0b0;
}

void UartRx_Tick(UartRx* uart) {
  switch (uart->state) {
    case RX_IDLE:
      if (uart->RX != 0b1) {
        uart->state = RX_DATA;
      }
      break;
    case RX_DATA:
      uart->shifRegister >>= 0b1;
      uart->shifRegister |= (uart->RX << 7u);
      uart->counter += 0b1;

      if (uart->counter == 8) {
        uart->state = RX_STOP;
      }
      break;
    case RX_STOP:
      uart->state = RX_IDLE;
      uart->counter = 0b0;
      break;
  }
}