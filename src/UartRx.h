#pragma once
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { RX_IDLE, RX_DATA, RX_STOP } RxState;

typedef struct {
  uint8_t RX;
  RxState state;
  uint8_t shifRegister;
  uint8_t counter;
} UartRx;

void UartRx_Init(UartRx* uart);
void UartRx_Tick(UartRx* uart);
void UartRx_Read(UartRx* uart);

#ifdef __cplusplus
}
#endif