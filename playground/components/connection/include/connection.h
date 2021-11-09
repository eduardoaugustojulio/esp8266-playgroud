#ifndef CONNECTION_H   
#define CONNECTION_H

#include "esp_err.h"
#include "tcpip_adapter.h"

esp_err_t connect();
esp_err_t disconnect();
esp_err_t set_connection_info(const char *ssid, const char *passwd);

#endif
