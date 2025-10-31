#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

// Enable overrides
#define USE_CONFIG_OVERRIDE

// === Zigbee-Bridge Fixes ===
#ifdef USE_ZIGBEE_ZNP
#undef USE_ZIGBEE_ZNP
#endif
#ifndef USE_ZIGBEE_EZSP
#define USE_ZIGBEE_EZSP
#endif
#ifndef USE_TCP_BRIDGE
#define USE_TCP_BRIDGE
#endif

// === Optional: Berry deaktivieren ===
#ifdef USE_BERRY
#undef USE_BERRY
#endif

#endif // _USER_CONFIG_OVERRIDE_H_
