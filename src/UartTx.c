#include "UartTx.h"

void UartTx_Init(UartTx* uart) {
  uart->TX = 0b1;
  uart->state = TX_IDLE;
  uart->counter = 0b0;
  uart->shiftRegister = 0b0;
}

void UartTx_Tick(UartTx* uart) {
  switch (uart->state) {
    case TX_IDLE:
      break;
    case TX_START:
      uart->TX = 0b0;
      uart->counter = 0b0;
      uart->state = TX_DATA;
      break;
    case TX_DATA:
      uint8_t mask = uart->shiftRegister & 0x01;
      uart->TX = mask;
      uart->shiftRegister >>= 0b1;
      uart->counter += 1;

      if (uart->counter == 8) {
        uart->state = TX_STOP;
      }
      break;
    case TX_STOP:
      uart->counter = 0;
      uart->shiftRegister = 0b0;
      uart->state = TX_IDLE;
      uart->TX = 0b1;
      break;
  }
}

void UartTx_Send(UartTx* uart, uint8_t data) {
  if (uart->state == TX_IDLE) {
    uart->state = TX_START;

    uart->shiftRegister = data;
  }
}