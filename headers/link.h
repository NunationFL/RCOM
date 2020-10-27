#include "macro.h"

typedef enum flags
{
    TRANSMITTER = 0,
    RECEIVER = 1
}deviceType;

typedef struct linkLayers
{
    char port[20];                 /*Dispositivo /dev/ttySx, x = 0, 1*/
    int baudRate;                  /*Velocidade de transmissão*/
    unsigned int sequenceNumber;   /*Número de sequência da trama: 0, 1*/
    unsigned int timeout;          /*Valor do temporizador: 1 s*/
    unsigned int numTransmissions; /*Número de tentativas em caso def alha*/
    char frame[TRAMA_SIZE];               /*Trama*/
    int fd;
}linkLayer;
typedef enum states{
    START = 0,
    FLAGRCV = 1,
    ARCV = 2,
    CRCV = 3,
    BCC = 4,
    STOP = 5
}state;

int llopen(int porta,deviceType flag);
int llclose(int ll);
int llwrite(int fd, char * buffer, int length);
int llread(int fd, char * buffer);