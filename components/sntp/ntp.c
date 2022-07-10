#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_system.h"
#include "esp_log.h"
#include "esp_netif.h"
#include "esp_event.h"

#include "lwip/apps/sntp.h"

static const char *TAG = "sntp_component";
static const char *servers[] = {"0.pool.ntp.org", "1.pool.ntp.org", "2.pool.ntp.org", "3.pool.ntp.org"};

static void initialize_sntp(){
    ESP_LOGI(TAG, "Initializing SNTP");
    sntp_setoperatingmode(SNTP_OPMODE_POLL);

    const int server_count = sizeof(servers) / sizeof(char*);
    for(int i = 0; i < server_count; i++){
        sntp_setservername(i, servers[i]);
    }

    sntp_init();
}

void sntp_task(void *arg){
    initialize_sntp();

    time_t now;
    struct tm timeinfo;
    char str_time[32];
    
    setenv("TZ", "BRST+3BRDT+3,M10.3.0,M2.3.0", 1);
    tzset();

    for(;;){
        time(&now);
        localtime_r(&now, &timeinfo);

        if(timeinfo.tm_year < (2016 - 1900)){
            ESP_LOGE(TAG, "The current date/time error");
        }else{
            strftime(str_time, sizeof(str_time), "%c", &timeinfo);
            ESP_LOGI(TAG, "The current date/time in Brazil is: %s", str_time);
        }
        ESP_LOGI(TAG, "Free heap size: %d\n", esp_get_free_heap_size());
        vTaskDelay(1000 / portTICK_RATE_MS);
    }
}
