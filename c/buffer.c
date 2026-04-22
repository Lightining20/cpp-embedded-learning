#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define BUFFER_SIZE 8

typedef enum
{
    ERR_OK = 0,
    ERR_FULL = 1,
    ERR_EMPTY = 2
} Status_t;

typedef struct
{
    uint16_t buffer[BUFFER_SIZE];
    uint8_t head;
    uint8_t tail;
    uint8_t count;
} RingBuffer_t;

void ring_init(RingBuffer_t *rb)
{
    rb->head = 0;
    rb->tail = 0;
    rb->count = 0;
}

Status_t ringPush(RingBuffer_t *rb, uint16_t data)
{
    if (rb->count == BUFFER_SIZE)
    {
        return ERR_FULL;
    }
    rb->buffer[rb->head] = data;
    rb->head = (rb->head + 1) % BUFFER_SIZE;
    rb->count++;
    return ERR_OK;
}
Status_t ringPop(RingBuffer_t *rb, uint16_t *data)
{
    if (rb->count == 0)
    {
        return ERR_EMPTY;
    }
    *data = rb->buffer[rb->tail];
    rb->tail = (rb->tail + 1) % BUFFER_SIZE;
    rb->count--;
    return ERR_OK;
}

int main(void)
{
    RingBuffer_t uart_rx; // a buffer for incoming UART bytes
    ring_init(&uart_rx);

    // Imagine bytes arriving from hardware...
    ringPush(&uart_rx, 'H');
    ringPush(&uart_rx, 'i');
    ringPush(&uart_rx, '!');

    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        printf("%c ", uart_rx.buffer[i]);
    }
    printf("\n");

    return 0;
}