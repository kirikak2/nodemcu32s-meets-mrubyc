/*
  ext.h
  Header file of extension methods
  
  Copyright (c) 2018, katsuhiko kageyama All rights reserved.
*/

#ifndef __EXT_H_
#define __EXT_H_

#include "value.h"

#define RECV_BUFF_SIZE 1024

bool mrbc_trans_cppbool_value(mrbc_vtype tt);

void define_arduino_class();
void define_serial_class();
void define_oled_class();
void define_dht_class();
#endif