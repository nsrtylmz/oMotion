

#include "SPI.h"

uint8_t spi_write(uint8_t addr,uint8_t data)
 {
  uint8_t tx_buf[2];


  tx_buf[0] = addr;
  tx_buf[1] = data;
  NRF_SPIM0->TXD.MAXCNT = sizeof(tx_buf);
  NRF_SPIM0->TXD.PTR = (uint32_t)&tx_buf[0];

    NRF_SPIM0->EVENTS_ENDTX = 0;
    NRF_SPIM0->EVENTS_ENDRX = 0;
    NRF_SPIM0->EVENTS_END = 0;

  NRF_SPIM0->TASKS_START = 1;
  while(NRF_SPIM0->EVENTS_ENDTX == 0);
  //while(NRF_SPIM0->EVENTS_ENDRX == 0);
  //while(NRF_SPIM0->EVENTS_END == 0);
  NRF_SPIM0->TASKS_STOP = 1;
  while (NRF_SPIM0->EVENTS_STOPPED == 0);

 }

 uint8_t spi_read(uint8_t addr)
 {
  static uint8_t tx_buf[2];
  static uint8_t rx_buf[2];
  addr = addr | 0x80;

  tx_buf[0] = addr;
  tx_buf[1] = 0x00;

  NRF_SPIM0->TXD.MAXCNT = 2;
  NRF_SPIM0->TXD.PTR = (uint32_t)&tx_buf[0];

  NRF_SPIM0->RXD.MAXCNT = 2;
  NRF_SPIM0->RXD.PTR = (uint32_t)&rx_buf[0];

    NRF_SPIM0->EVENTS_ENDTX = 0;
    NRF_SPIM0->EVENTS_ENDRX = 0;
    NRF_SPIM0->EVENTS_END = 0;

  
  NRF_SPIM0->TASKS_START = 1;
  while(NRF_SPIM0->EVENTS_ENDTX == 0);
  while(NRF_SPIM0->EVENTS_ENDRX == 0);
  while(NRF_SPIM0->EVENTS_END == 0);
  NRF_SPIM0->TASKS_STOP = 1;
  while (NRF_SPIM0->EVENTS_STOPPED == 0);

  return rx_buf[1];

 }

uint8_t * bmx_spi_read_acc()
 {
  uint8_t addr=0x02;
  static uint8_t tx_buf[7];
  static uint8_t rx_buf[7];
  addr = addr | 0x80;


  tx_buf[0] = 0x82;
  tx_buf[1] = 0x00;
  tx_buf[2] = 0x00;
  tx_buf[3] = 0x00;
  tx_buf[4] = 0x00;
  tx_buf[5] = 0x00;
  tx_buf[6] = 0x00;

  NRF_SPIM0->TXD.MAXCNT = 7;
  NRF_SPIM0->TXD.PTR = (uint32_t)&tx_buf[0];

  NRF_SPIM0->RXD.MAXCNT = 7;
  NRF_SPIM0->RXD.PTR = (uint32_t)&rx_buf[0];

    NRF_SPIM0->EVENTS_ENDTX = 0;
    NRF_SPIM0->EVENTS_ENDRX = 0;
    NRF_SPIM0->EVENTS_END = 0;

  NRF_SPIM0->TASKS_START = 1;
  while(NRF_SPIM0->EVENTS_ENDTX == 0);
  while(NRF_SPIM0->EVENTS_ENDRX == 0);
  while(NRF_SPIM0->EVENTS_END == 0);
  NRF_SPIM0->TASKS_STOP = 1;
  while (NRF_SPIM0->EVENTS_STOPPED == 0);


  uint8_t txnum = NRF_SPIM0->TXD.AMOUNT;
  uint8_t rxnum = NRF_SPIM0->RXD.AMOUNT;

  return rx_buf;

 }


uint8_t * bmx_spi_read_gyro()
 {
  uint8_t addr=0x02;
  static uint8_t tx_buf[7];
  static uint8_t rx_buf[7];
  addr = addr | 0x80;


  tx_buf[0] = 0x82;
  tx_buf[1] = 0x00;
  tx_buf[2] = 0x00;
  tx_buf[3] = 0x00;
  tx_buf[4] = 0x00;
  tx_buf[5] = 0x00;
  tx_buf[6] = 0x00;

  NRF_SPIM0->TXD.MAXCNT = 7;
  NRF_SPIM0->TXD.PTR = (uint32_t)&tx_buf[0];

  NRF_SPIM0->RXD.MAXCNT = 7;
  NRF_SPIM0->RXD.PTR = (uint32_t)&rx_buf[0];

    NRF_SPIM0->EVENTS_ENDTX = 0;
    NRF_SPIM0->EVENTS_ENDRX = 0;
    NRF_SPIM0->EVENTS_END = 0;

  NRF_SPIM0->TASKS_START = 1;
  while(NRF_SPIM0->EVENTS_ENDTX == 0);
  while(NRF_SPIM0->EVENTS_ENDRX == 0);
  while(NRF_SPIM0->EVENTS_END == 0);
  NRF_SPIM0->TASKS_STOP = 1;
  while (NRF_SPIM0->EVENTS_STOPPED == 0);


  uint8_t txnum = NRF_SPIM0->TXD.AMOUNT;
  uint8_t rxnum = NRF_SPIM0->RXD.AMOUNT;

  return rx_buf;

 }

uint8_t * bmx_spi_read_mag()
 {
  uint8_t addr=0x42;
  static uint8_t tx_buf[7];
  static uint8_t rx_buf[7];
  addr = addr | 0x80;


  tx_buf[0] = 0xC2;
  tx_buf[1] = 0x00;
  tx_buf[2] = 0x00;
  tx_buf[3] = 0x00;
  tx_buf[4] = 0x00;
  tx_buf[5] = 0x00;
  tx_buf[6] = 0x00;

  NRF_SPIM0->TXD.MAXCNT = 7;
  NRF_SPIM0->TXD.PTR = (uint32_t)&tx_buf[0];

  NRF_SPIM0->RXD.MAXCNT = 7;
  NRF_SPIM0->RXD.PTR = (uint32_t)&rx_buf[0];

    NRF_SPIM0->EVENTS_ENDTX = 0;
    NRF_SPIM0->EVENTS_ENDRX = 0;
    NRF_SPIM0->EVENTS_END = 0;

  NRF_SPIM0->TASKS_START = 1;
  while(NRF_SPIM0->EVENTS_ENDTX == 0);
  while(NRF_SPIM0->EVENTS_ENDRX == 0);
  while(NRF_SPIM0->EVENTS_END == 0);
  NRF_SPIM0->TASKS_STOP = 1;
  while (NRF_SPIM0->EVENTS_STOPPED == 0);


  uint8_t txnum = NRF_SPIM0->TXD.AMOUNT;
  uint8_t rxnum = NRF_SPIM0->RXD.AMOUNT;

  return rx_buf;

 }

void initialize_spi(void)
 {

  pin_set(bmx_cs1);
  pin_set(bmx_cs2);
  pin_set(bmx_cs3);
  NRF_SPIM0->PSEL.SCK  = bmx_sck;
  NRF_SPIM0->PSEL.MOSI = bmx_mosi;
  NRF_SPIM0->PSEL.MISO = bmx_miso1;

  NRF_SPIM0->CONFIG = 0x00;
  NRF_SPIM0->FREQUENCY = SPIM_FREQUENCY_FREQUENCY_K500 << SPIM_FREQUENCY_FREQUENCY_Pos;
  NRF_SPIM0-> ENABLE = SPIM_ENABLE_ENABLE_Enabled << SPIM_ENABLE_ENABLE_Pos;
  //NRF_SPIM0->ENABLE = SPIM_ENABLE_ENABLE_Disabled << SPIM_ENABLE_ENABLE_Pos;

  }

  void select_bmx_acc(void)
  {
  NRF_SPIM0->PSEL.MISO = bmx_miso1;
  }

  void select_bmx_gyro(void)
  {
  NRF_SPIM0->PSEL.MISO = bmx_miso2;
  }

