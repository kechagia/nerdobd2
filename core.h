// TODO: check whether terminal/socket includes can be in the file that needs them only
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <math.h>

// include common defines
#include "common.h"
#include "config.h"

// serial protocol
#include "kw1281.h"

// we need sqlite3 access
#include "sqlite.h"

// the http server
#include "httpd.h"

// gps
#include "gps.h"

// the engine data struct
typedef struct obd_data_t
{
    float rpm;
    float injection_time;
    float oil_pressure;
    float speed;

    // consumption (will be calculated)
    float consumption_per_h;
    float consumption_per_100km;
    
    float duration_consumption;
    float duration_speed;
    
    float temp_engine;
    float temp_air_intake;
    float voltage;
} obd_data_t;

void handle_data(char *, float, float);
