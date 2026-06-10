#pragma once
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { TX_IDLE, TX_START, TX_DATA, TX_STOP } TxState;

typedef struct {
  uint8_t TX;
  TxState state;
  uint8_t shiftRegister;
  uint8_t counter;
} UartTx;

void UartTx_Init(UartTx* uart);
void UartTx_Tick(UartTx* uart);
void UartTx_Send(UartTx* uart, uint8_t data);

#ifdef __cplusplus
}
#endif