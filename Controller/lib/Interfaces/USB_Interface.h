
#include "FTDI_Drv/ftd2xx.h"
#include <iostream>
#include <string>

#define MAX_LENGTH_OF_PACKET        1024     // Максимальный размер отравляемой посылки
#define RESPONSE_TIME               10       // Время ожидания ответа (миллисекундах)

#define HEADER_KEY_SYMBOL           0x55
#define TRAILER_KEY_SYMBOL          0xAA
#define HEADER_KEY_SYMBOL_NUMBER    12
#define TRAILER_KEY_SYMBOL_NUMBER   8
#define ERROR_SYMBOL                0xEE

#define LENGTH_OF_PACKET_SIZE   2
#define LENGTH_POSITION         HEADER_KEY_SYMBOL_NUMBER

#define SERVICE_TYPE_SIZE       2
#define SERVICE_TYPE_POSITION   LENGTH_POSITION + LENGTH_OF_PACKET_SIZE

#define ADDRESS_SIZE            2
#define ADDRESS_POSITION        SERVICE_TYPE_POSITION + SERVICE_TYPE_SIZE
#define DATA_SIZE               2
#define DATA_POSITION           ADDRESS_POSITION + ADDRESS_SIZE

#define SERVICE_TYPE_WRITE      0xCDAB
#define SERVICE_TYPE_READ       0xABCD


#pragma once
class USB_Interface
{
     unsigned long  NumOfWritten;
     unsigned long  NumOfRead;

public:
     std::string Error;
     FT_HANDLE FT_Handle;
     FT_STATUS FT_Status;
     FT_DEVICE ftDevice;
     DWORD deviceID;
     char SerialNumber[16];
     char Description[64];
     bool device_selected;  //1- устройство выбрано 0-не выбрано
     BYTE* raw_data;        // Массив сырах принятых данных
     int raw_data_size;

     USB_Interface();
     bool Get_Status();
     DWORD DeviceDetail(int);
     bool DeviceInfo();
     void Select_Device(const char *serial_number);
     int  Number_Of_Device();
     int  num_bytes_received();
     bool Open_Device();
     bool Close_Device();
     bool Reset_Device(int sleep);
     unsigned long send_to_FT(unsigned char* TxBuffer, int BufferSize);
     unsigned long receive_from_FT(unsigned char* Dest, int Size);
     void  SetTimeouts(int, int);
     UCHAR  GetBitMode();
     ~USB_Interface();

     // Методы пользователя
     int GetDeviceInfoList(FT_STATUS* ftStatus,FT_DEVICE_LIST_INFO_NODE *devInfo); // Выдает список подлюченных устройств
     int USB_Send_Data_Protocol(unsigned int ServiceType, unsigned int* Addr, unsigned int *Data, int size);
     int USB_Recive_Data_Protocol(BYTE *RxBuffer, int size);
     int read(unsigned int* addres_array, int size, unsigned int* data_array);
     int write(unsigned int* Addr, int size, unsigned int* Data);
};






 
