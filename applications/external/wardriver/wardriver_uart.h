#include "wardriver.h"

#define UART_CH_ESP \
    (CFW_SETTINGS()->uart_esp_channel == UARTDefault ? FuriHalUartIdUSART1 : FuriHalUartIdLPUART1)

#define UART_CH_GPS \
    (CFW_SETTINGS()->uart_nmea_channel == UARTDefault ? FuriHalUartIdUSART1 : FuriHalUartIdLPUART1)

#define WORKER_ALL_RX_EVENTS (WorkerEvtStop | WorkerEvtRxDone)

typedef enum {
    WorkerEvtStop = (1 << 0),
    WorkerEvtRxDone = (1 << 1),
} WorkerEvtFlags;

void wardriver_uart_init(Context* ctx);
void wardriver_uart_deinit(Context* ctx);
