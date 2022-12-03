#include "USB_Interface.h"


USB_Interface::USB_Interface()
{
    device_selected = false;
    FT_Status      = FT_OK;
}

bool USB_Interface::Get_Status()
{
    DWORD RxBytes,TxBytes;
    DWORD EventDWord;

    FT_GetStatus(FT_Handle,&RxBytes,&TxBytes,&EventDWord);
    if (EventDWord & FT_EVENT_MODEM_STATUS) return true;
    else                                    return false;
}

bool USB_Interface::DeviceInfo()
{
    FT_Status = FT_GetDeviceInfo( FT_Handle, &ftDevice, &deviceID, SerialNumber, Description, NULL );
    if (FT_Status == FT_OK) return true;
    else return false;
}

DWORD USB_Interface::DeviceDetail(int Number)
{
     DWORD numDevs;
// create the device information list
     FT_Status = FT_CreateDeviceInfoList(&numDevs);
     return numDevs;
}

void USB_Interface::Select_Device(const char* serial_number)
{
     memcpy(SerialNumber,serial_number,16);
     device_selected = true;
}


int  USB_Interface::Number_Of_Device()
{
     unsigned long numDevs=0;
     FT_Status=FT_ListDevices(&numDevs,NULL,FT_LIST_NUMBER_ONLY);
     return numDevs;
}

int  USB_Interface::num_bytes_received()
{
    unsigned long BytesReceived = 0;
    FT_Status = FT_GetQueueStatus(FT_Handle,&BytesReceived);
    return BytesReceived;
}


bool USB_Interface::Open_Device()
{
    if(device_selected == false){
        FT_Status=FT_Open(0, &FT_Handle);
        if(FT_Status!=FT_OK)
            return false;
        FT_SetLatencyTimer(FT_Handle,0x02);
        return true;
    }
    else{
        FT_Status=FT_OpenEx(SerialNumber,FT_OPEN_BY_SERIAL_NUMBER,&FT_Handle);
        if(FT_Status!=FT_OK)
            return false;
        FT_SetLatencyTimer(FT_Handle,0x02);
        return true;
    }
    return false;
}

bool USB_Interface::Close_Device()
{
     FT_Status=FT_Close(FT_Handle);
     if(FT_Status!=FT_OK)  return false;
     return true;
}

/* TODO : Reset_Device */
bool USB_Interface::Reset_Device(int sleep)
{
     Close_Device();
     Sleep(sleep);
     Open_Device();
     if(FT_Status!=FT_OK)  return false;
     return true;
}

unsigned long USB_Interface::send_to_FT(unsigned char* TxBuffer, int BufferSize)
{
    unsigned long BytesWritten = 0;
    FT_Status = FT_Write(FT_Handle, TxBuffer, BufferSize, &BytesWritten);
    if(FT_Status != FT_OK){
        Error = "Error when transferring to FT";
        return -1;
    }
    return BytesWritten;
}

unsigned long USB_Interface::receive_from_FT(unsigned char* RxBuffer, int BufferSize)
{
    unsigned long BytesReceived = 0;
    FT_Status = FT_Read(FT_Handle, RxBuffer, BufferSize, &BytesReceived);
    if(FT_Status != FT_OK){
        Error = "Error when receiving from FT";
        return -1;
    }

    return BytesReceived;
}
void  USB_Interface::SetTimeouts(int TxTimeout, int RxTimeout)
{
     FT_SetTimeouts(FT_Handle, RxTimeout, TxTimeout);
}
UCHAR  USB_Interface::GetBitMode()
{
     UCHAR BitMode;
     if(FT_GetBitMode(FT_Handle, &BitMode) !=FT_OK) return 0;

     return BitMode;
}

/*UCHAR  USB_Interface::SetBitMode()
{
     UCHAR BitMode;
     if(FT_GetBitMode(FT_Handle, &BitMode) !=FT_OK) return 0;

     return BitMode;
}  */

/* TODO : ~USB_Interface */
USB_Interface::~USB_Interface()
{
     Close_Device();
}


int USB_Interface::GetDeviceInfoList(FT_STATUS *ftStatus, FT_DEVICE_LIST_INFO_NODE *devInfo){
    DWORD numDevs;
    // create the device information list
    *ftStatus = FT_CreateDeviceInfoList(&numDevs);
    if (*ftStatus == FT_OK) {
        printf("Number of devices is %d\n",numDevs);
    }
    if (numDevs > 0) {
        // allocate storage for list based on numDevs
        devInfo =
                (FT_DEVICE_LIST_INFO_NODE*)malloc(sizeof(FT_DEVICE_LIST_INFO_NODE)*numDevs);
        // get the device information list
        *ftStatus = FT_GetDeviceInfoList(devInfo,&numDevs);
    }
    return static_cast<int>(numDevs);
}


int USB_Interface::USB_Send_Data_Protocol(unsigned int ServiceType, unsigned int* Addr, unsigned int* Data, int size)
{
    unsigned long tx_buffer_size = HEADER_KEY_SYMBOL_NUMBER
                                    + LENGTH_OF_PACKET_SIZE
                                    + SERVICE_TYPE_SIZE
                                    + size * ADDRESS_SIZE
                                    + size * DATA_SIZE
                                    + TRAILER_KEY_SYMBOL_NUMBER;

    unsigned long length_of_packet = tx_buffer_size - HEADER_KEY_SYMBOL_NUMBER;

    if(tx_buffer_size > MAX_LENGTH_OF_PACKET){
        Error = "Packet size exceeded!";
        return -1;
    }

    BYTE* TxBuffer = new BYTE [tx_buffer_size];

    // Заполняем  TxBuffer
    //1. Спец. символ в начале посылки
    for(int i=0; i<HEADER_KEY_SYMBOL_NUMBER; i++)
        TxBuffer[i] = HEADER_KEY_SYMBOL;
    //2. Длина посылки
    TxBuffer[LENGTH_POSITION]    = (BYTE) length_of_packet;     // LSB
    TxBuffer[LENGTH_POSITION +1] = (BYTE)(length_of_packet>>8); // MSB
    //3. Команда
    TxBuffer[SERVICE_TYPE_POSITION] =    (BYTE) ServiceType;      // LSB
    TxBuffer[SERVICE_TYPE_POSITION +1] = (BYTE)(ServiceType>>8);  // MSB
    //4. Адрес и данные
    for(int i=0; i<size; i++) //Указываем число слов данных отправляемых по USB
    {
        TxBuffer[ADDRESS_POSITION+i*4]    = (BYTE) Addr[i];     // адрес ресурса
        TxBuffer[ADDRESS_POSITION+i*4 +1] = (BYTE)(Addr[i]>>8); // внутри блока
        TxBuffer[DATA_POSITION+i*4]       = (BYTE) Data[i];     // данные
        TxBuffer[DATA_POSITION+i*4 +1]    = (BYTE)(Data[i]>>8); // для этого адреса
    }
    //5. Спец. символ конца посылки
    for(int i=ADDRESS_POSITION+size*4; i<tx_buffer_size; i++)
        TxBuffer[i] = TRAILER_KEY_SYMBOL;

    //отправляем данные по USB
    unsigned long BytesWritten = send_to_FT(TxBuffer,tx_buffer_size);

    raw_data_size = BytesWritten;
    raw_data = new BYTE[raw_data_size];
    for(int i=0; i<raw_data_size;i++)
        raw_data[i] = TxBuffer[i];

    // Проверка, что кол-во отправленных байт равно размеру посылки
    if(tx_buffer_size != BytesWritten){
        Error = "The size of the sent packet is not equal to the set size!";
        return  -1;
    }
    delete[] TxBuffer;

    return BytesWritten;
}

int USB_Interface::USB_Recive_Data_Protocol(BYTE *RxBuffer, int size)
{
    int BytesReceived;

    // Пороверяем сколько байт доступно на чтение
    BytesReceived = num_bytes_received();

    if(BytesReceived == size){ // Принято столько сколько ожидалось
        receive_from_FT(RxBuffer,BytesReceived);
        return BytesReceived;
    }
    else{ // Принято меньше или больше чем ожидалось
        RxBuffer = new BYTE[BytesReceived]; // пересоздаем буффер под необходимый размер
        receive_from_FT(RxBuffer,BytesReceived);
        return BytesReceived;
    }
}

int USB_Interface::read(unsigned int *addres_array, int size, unsigned int *data_array)
{
    unsigned long rx_buffer_size = HEADER_KEY_SYMBOL_NUMBER
                                    + LENGTH_OF_PACKET_SIZE
                                    + SERVICE_TYPE_SIZE
                                    + size * ADDRESS_SIZE
                                    + size * DATA_SIZE
                                    + TRAILER_KEY_SYMBOL_NUMBER;

    int BytesWritten = USB_Send_Data_Protocol(SERVICE_TYPE_READ, addres_array, addres_array, size);
    if(BytesWritten < 0)
        return -1;

    int timer = 0;
    bool timeout_flag = false;
    bool package_received = false;
    int num_bytes = -1;

    while( !(package_received | timeout_flag)){
        if(num_bytes_received() > num_bytes)
            num_bytes = num_bytes_received();
        else package_received = true;

        if(timer >= RESPONSE_TIME)
            timeout_flag = true;
        Sleep(1);
        timer++;
    }

    // Не дождались ответа
    if(timeout_flag & !package_received){
        Error = "Timeout exceeded!";
        return -1;
    }

    BYTE* RxBuffer = new BYTE [rx_buffer_size];
    int BytesRead = USB_Recive_Data_Protocol(RxBuffer, rx_buffer_size);

    raw_data_size = BytesRead;
    raw_data = new BYTE[raw_data_size];
    for(int i=0; i<raw_data_size;i++)
        raw_data[i] = RxBuffer[i];

    // Кол-во принятых байт не равно кол-ву отправленных
    if(BytesRead != BytesWritten){
        Error = "The number of bytes received is not equal to the number of bytes sent!";
        return -2;
    }

    unsigned int length_of_received_package = 0;
    length_of_received_package = ((RxBuffer[HEADER_KEY_SYMBOL_NUMBER+1]<<8) & 0xFF00)
            | (RxBuffer[HEADER_KEY_SYMBOL_NUMBER] & 0x00FF);

    // Проверка на соответствие длины посылки
    if(length_of_received_package != (BytesWritten-HEADER_KEY_SYMBOL_NUMBER)){
        Error = "The length of the received package is incorrect!";
        return -3;
    }

    // Проверка на соответствие команды
    unsigned int service_Type_of_received_package = 0;
    service_Type_of_received_package = ((RxBuffer[HEADER_KEY_SYMBOL_NUMBER+3]<<8) & 0xFF00)
            | ((RxBuffer[HEADER_KEY_SYMBOL_NUMBER+2]) & 0x00FF);

    if(service_Type_of_received_package != SERVICE_TYPE_READ){
        Error = "Service Type is not equal to sent!";
        return -4;
    }

    unsigned int data_received_size = BytesRead
            - HEADER_KEY_SYMBOL_NUMBER
            - LENGTH_OF_PACKET_SIZE
            - SERVICE_TYPE_SIZE
            - TRAILER_KEY_SYMBOL_NUMBER;

    // Кол-во пришедших данных больше чем отправленных
    if(data_received_size/4 != size){
        Error = "The length of the received package is incorrect!";
        return -5;
    }

    unsigned int *addr_array = new unsigned int[size];
    for(int i=0; i<size; i++){
        addr_array[i] = ((RxBuffer[ADDRESS_POSITION+(i*4)+1]<<8) & 0xFF00)
                | ((RxBuffer[ADDRESS_POSITION+(i*4)]) & 0x00FF);

        data_array[i] = ((RxBuffer[DATA_POSITION+(i*4)+1]<<8) & 0xFF00)
                | ((RxBuffer[DATA_POSITION+(i*4)]) & 0x00FF);
    }

    return BytesRead;
}

int USB_Interface::write(unsigned int *Addr, int size, unsigned int *Data)
{

    int BytesWritten = USB_Send_Data_Protocol(SERVICE_TYPE_WRITE, Addr, Data, size);
    if(BytesWritten < 0)
        return -1;

    unsigned long rx_buffer_size = HEADER_KEY_SYMBOL_NUMBER
            + LENGTH_OF_PACKET_SIZE
            + SERVICE_TYPE_SIZE
            + size * ADDRESS_SIZE
            + size * DATA_SIZE
            + TRAILER_KEY_SYMBOL_NUMBER;

    int timer = 0;
    bool timeout_flag = false;
    bool package_received = false;
    int num_bytes = -1;

    while( !(package_received | timeout_flag)){
        if(num_bytes_received() > num_bytes)
            num_bytes = num_bytes_received();
        else package_received = true;

        if(timer >= RESPONSE_TIME)
            timeout_flag = true;
        Sleep(1);
        timer++;
    }

    // Не дождались ответа
    if(timeout_flag & !package_received){
         Error = "Timeout exceeded!";
        return -1;
    }

    BYTE* RxBuffer = new BYTE [rx_buffer_size];
    int BytesRead = USB_Recive_Data_Protocol(RxBuffer, rx_buffer_size);

    // Кол-во принятых байт не равно кол-ву отправленных
    if(BytesRead != BytesWritten){
        Error = "The number of bytes received is not equal to the number of bytes sent!";
        return -2;
    }

    unsigned int length_of_received_package = 0;
    length_of_received_package = ((RxBuffer[HEADER_KEY_SYMBOL_NUMBER+1]<<8) & 0xFF00)
            | (RxBuffer[HEADER_KEY_SYMBOL_NUMBER] & 0x00FF);

    // Проверка на соответствие длины посылки
    if(length_of_received_package != (BytesWritten-HEADER_KEY_SYMBOL_NUMBER)){
        Error = "The length of the received package is incorrect!";
        return -3;
    }
    // Проверка на соответствие команды
    unsigned int service_Type_of_received_package = 0;
    service_Type_of_received_package = ((RxBuffer[HEADER_KEY_SYMBOL_NUMBER+3]<<8) & 0xFF00)
            | ((RxBuffer[HEADER_KEY_SYMBOL_NUMBER+2]) & 0x00FF);

    if(service_Type_of_received_package != SERVICE_TYPE_WRITE){
        Error = "Service Type is not equal to sent!";
        return -4;
    }

    unsigned int data_received_size = BytesRead
                                        - HEADER_KEY_SYMBOL_NUMBER
                                        - LENGTH_OF_PACKET_SIZE
                                        - SERVICE_TYPE_SIZE
                                        - TRAILER_KEY_SYMBOL_NUMBER;

    // Кол-во пришедших данных больше чем отправленных
    if(data_received_size/4 != size){
        Error = "The length of the received package is incorrect!";
        return -5;
    }

    return BytesWritten;
}
