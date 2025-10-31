#pragma once
// Wrapper: nutzt Original-Header, wenn vorhanden; sonst minimale Stubs.

#if __has_include("spi_flash_mmap.h")
  #include_next "spi_flash_mmap.h"
#else
  #include <stdint.h>
  #include <esp_spi_flash.h>   // liefert Basis-Types/ESPres

  // IDF-kompatible Typen/Defines (Minimalumfang)
  typedef uint32_t spi_flash_mmap_handle_t;
  #ifndef SPI_FLASH_MMAP_DATA
    #define SPI_FLASH_MMAP_DATA 0
  #endif
  #ifndef SPI_FLASH_MMAP_INST
    #define SPI_FLASH_MMAP_INST 1
  #endif

  static inline int spi_flash_mmap(uint32_t /*src_addr*/, uint32_t /*size*/,
                                   int /*memory*/, const void** out_ptr,
                                   spi_flash_mmap_handle_t* out_handle) {
    if (out_ptr)     *out_ptr = nullptr;
    if (out_handle)  *out_handle = 0;
    return 0; // ESP_OK
  }
  static inline void spi_flash_munmap(spi_flash_mmap_handle_t /*handle*/) {}
#endif
