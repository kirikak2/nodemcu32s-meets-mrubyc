/*
  ext.cpp

  Defining extension methods for ESP32
  
  Copyright (c) 2018, katsuhiko kageyama All rights reserved.

*/

#include "mrubyc_for_ESP32_Arduino.h"
#include "ext.h"

bool mrbc_trans_cppbool_value(mrbc_vtype tt)
{
  if (tt == MRBC_TT_TRUE)
  {
    return true;
  }
  return false;
}

void mrbc_define_methods()
{
  define_arduino_class();
  define_serial_class();
  define_oled_class();
  define_dht_class();
}