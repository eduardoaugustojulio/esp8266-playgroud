#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "nvs_flash.h"

#include "connection.h"
#include "ntp.h"

void app_main()
{
    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    ESP_ERROR_CHECK(set_connection_info("Casa 174", "#internet@174"));
    ESP_ERROR_CHECK(connect());

    xTaskCreate(sntp_task, "sntp_task", 2048, NULL, 10, NULL);

}
