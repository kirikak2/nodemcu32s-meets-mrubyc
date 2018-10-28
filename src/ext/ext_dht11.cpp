/*
    ext_dht11.cpp
    Wrapper library DHT11 for mruby/c
    Copyright (c) 2018, Toshio Maki ALl rights reserved.
*/

#include "Arduino.h"
#include "mrubyc_for_ESP32_Arduino.h"
#include "ext.h"
#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHTTYPE DHT11
DHT *dht = NULL;

static void class_dht_new(mrb_vm *vm, mrb_value *v, int argc) {
    int dhtpin;
    if(argc == 1) {
        if(GET_TT_ARG(1) == MRBC_TT_FIXNUM) {
            dhtpin = GET_INT_ARG(1);
            dht = new DHT(dhtpin, DHTTYPE);
            Serial.printf("DHT pin=%d type=%d\n", dhtpin, DHTTYPE);
        }
    } else {
        return;
    }
}

static void class_dht_read_humidity(mrb_vm *vm, mrb_value *v, int argc) {
    if(dht != NULL) {
        float h = dht->readHumidity();
        if(!isnan(h)) {
            Serial.printf("DHT.humidity = %f", h);
            SET_FLOAT_RETURN(h);
        } else {
            SET_NIL_RETURN();
        }
    }
}

static void class_dht_read_temperature(mrb_vm *vm, mrb_value *v, int argc) {
    if(dht != NULL) {
        float t = dht->readTemperature();
        if(!isnan(t)) {
            Serial.printf("DHT.temperature = %f", t);
            SET_FLOAT_RETURN(t);
        } else {
            SET_NIL_RETURN();
        }
    }
}

static void class_dht_compute_heat_index(mrb_vm *vm, mrb_value *v, int argc) {
    if(dht != NULL) {
        float h = dht->readHumidity();
        float t = dht->readTemperature();
        if(!isnan(h) && !isnan(t)) {
            float heatIndex = dht->computeHeatIndex(h, t, false);
            Serial.printf("DHT.heat_index = %f", heatIndex);
            SET_FLOAT_RETURN(heatIndex);
        } else {
            SET_NIL_RETURN();
        }
    }
}

void define_dht_class() {
    mrb_class *class_dht;
    class_dht = mrbc_define_class(0, "Dht", mrbc_class_object);
    mrbc_define_method(0, class_dht, "initialize", class_dht_new);
    mrbc_define_method(0, class_dht, "humidity", class_dht_read_humidity);
    mrbc_define_method(0, class_dht, "temperature", class_dht_read_temperature);
    mrbc_define_method(0, class_dht, "heat_index", class_dht_compute_heat_index);
}