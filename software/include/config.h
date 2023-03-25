// ===================================================================================
// User Configurations for CH552E USB MacroPad Mini
// ===================================================================================

#pragma once

// Pin definitions
#define PIN_NEO             P14         // pin connected to NeoPixel
#define PIN_KEY3            P15         // pin connected to key 3
#define PIN_KEY2            P16         // pin connected to key 2
#define PIN_KEY1            P17         // pin connected to key 1

// NeoPixel configuration
#define NEO_GRB                         // type of pixel: NEO_GRB or NEO_RGB

// USB device descriptor
#define USB_VENDOR_ID       0x1189      // VID
#define USB_PRODUCT_ID      0x8890      // PID
#define USB_DEVICE_VERSION  0x0100      // v1.0 (BCD-format)

// USB configuration descriptor
#define USB_MAX_POWER_mA    50          // max power in mA 

// USB descriptor strings
#define MANUFACTURER_STR    'w','a','g','i','m','i','n','a','t','o','r'
#define PRODUCT_STR         'M','a','c','r','o','p','a','d'
#define SERIAL_STR          'C','H','5','5','2','x','H','I','D'
#define INTERFACE_STR       'H','I','D','-','K','e','y','b','o','a','r','d'

// HID keyboard country codes
#define HID_COUNTRY_CODE    HID_GERMAN  // keyboard country code

#define HID_NO_COUNTRY      0
#define HID_ARABIC          1
#define HID_BELGIAN         2
#define HID_CANADIAN_BI     3
#define HID_CANADIAN_FR     4
#define HID_CZECH           5
#define HID_DANISH          6
#define HID_FINNISH         7
#define HID_FRENCH          8
#define HID_GERMAN          9
#define HID_GREEK           10
#define HID_HEBREW          11
#define HID_HUNGARY         12
#define HID_INTERNATIONAL   13
#define HID_ITALIAN         14
#define HID_JAPAN           15
#define HID_KOREAN          16
#define HID_LATIN           17
#define HID_DUTCH           18
#define HID_NORWEGIAN       19
#define HID_PERSIAN         20
#define HID_POLISH          21
#define HID_PORTUGUESE      22
#define HID_RUSSIAN         23
#define HID_SLOVAKIAN       24
#define HID_SPANISH         25
#define HID_SWEDISH         26
#define HID_SWISS_FRENCH    27
#define HID_SWISS_GERMAN    28
#define HID_SWISS           29
#define HID_TAIWAN          30
#define HID_TURKISH_Q       31
#define HID_ENGLISH_UK      32
#define HID_ENGLISH_US      33
#define HID_YUGOSLAVIAN     34
#define HID_TURKISH_F       35
