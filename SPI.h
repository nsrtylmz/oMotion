
#include <nrf.h>
//#include <stdio.h>
//#include <stdlib.h>
#include "PINS.h"

uint8_t spi_write(uint8_t addr,uint8_t data);
uint8_t spi_read(uint8_t addr);
uint8_t * bmx_spi_read_acc();
uint8_t * bmx_spi_read_gyro();
uint8_t * bmx_spi_read_mag();
void initialize_spi(void);
void select_bmx_acc(void);
void select_bmx_gyro(void);
