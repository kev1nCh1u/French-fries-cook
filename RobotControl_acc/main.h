#ifndef MAIN_H
#define MAIN_H

#include "Arduino.h"
#include <SPI.h>
#include "AccelStepper.h"
#include <MultiStepper.h>

#define X_PUL_PIN   A0
#define X_DIR_PIN   A1
#define X_ENA_PIN   38
#define X_HOM_PIN   37

#define Y_PUL_PIN   A6
#define Y_DIR_PIN   A7
#define Y_ENA_PIN   A2
#define Y_HOM_PIN   22

#define Z_PUL_PIN   46
#define Z_DIR_PIN   48
#define Z_ENA_PIN   A8
#define Z_HOM_PIN   47

#define E_PUL_PIN   26
#define E_DIR_PIN   28
#define E_ENA_PIN   24
#define E_HOM_PIN   25

#define T_PUL_PIN   36
#define T_DIR_PIN   34
#define T_ENA_PIN   30
#define T_HOM_PIN   35

pinMode(X_PUL_PIN,OUTPUT);
pinMode(X_DIR_PIN,OUTPUT);
pinMode(X_ENA_PIN,OUTPUT);
pinMode(X_HOM_PIN,INPUT_PULLUP);

pinMode(Y_PUL_PIN,OUTPUT);
pinMode(Y_DIR_PIN,OUTPUT);
pinMode(Y_ENA_PIN,OUTPUT);
pinMode(Y_HOM_PIN,INPUT_PULLUP);

pinMode(Z_PUL_PIN,OUTPUT);
pinMode(Z_DIR_PIN,OUTPUT);
pinMode(Z_ENA_PIN,OUTPUT);
pinMode(Z_HOM_PIN,INPUT_PULLUP);

pinMode(E_PUL_PIN,OUTPUT);
pinMode(E_DIR_PIN,OUTPUT);
pinMode(E_ENA_PIN,OUTPUT);
pinMode(E_HOM_PIN,INPUT_PULLUP);

pinMode(T_PUL_PIN,OUTPUT);
pinMode(T_DIR_PIN,OUTPUT);
pinMode(T_ENA_PIN,OUTPUT);
pinMode(T_HOM_PIN,INPUT_PULLUP);


#endif
