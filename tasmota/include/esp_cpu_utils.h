#pragma once
#if defined(__has_include)
  #if __has_include(<esp_cpu_utils.h>)
    #include <esp_cpu_utils.h>
  #else
    #include <stdint.h>
    #ifdef __cplusplus
    extern "C" {
    #endif
    static inline bool esp_cpu_in_ocd_debug_mode(void) { return false; }
    static inline int  esp_cpu_get_core_id(void) { return 0; }
    #ifdef __cplusplus
    }
    #endif
  #endif
#else
  #include <esp_cpu_utils.h>
#endif
