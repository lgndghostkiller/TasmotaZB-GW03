#pragma once
// Robuster Wrapper für unterschiedliche Arduino-ESP32/IDF Layouts.
// Versucht zuerst das echte Header-File, fällt sonst auf Stubs zurück.

#if defined(__has_include)
  #if __has_include(<spi_flash_mmap.h>)
    // Original vorhanden (IDF-Komponente spi_flash)
    #include <spi_flash_mmap.h>
  #else
    // Fallback: Minimal-Stubs
    #include <stdint.h>
    #if __has_include(<esp_spi_flash.h>)
      #include <esp_spi_flash.h>
    #endif

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
      if (out_ptr)    *out_ptr = nullptr;
      if (out_handle) *out_handle = 0;
      return 0; // ESP_OK
    }
    static inline void spi_flash_munmap(spi_flash_mmap_handle_t /*handle*/) {}
  #endif
#else
  // Sehr alte Compiler: direkter Versuch, sonst Stubs
  #include <spi_flash_mmap.h>
#endif
