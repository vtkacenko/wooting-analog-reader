#pragma once

#ifdef WOOTINGANALOGREADER_EXPORTS  
#define WOOTINGANALOGREADER_API __declspec(dllexport)   
#else  
#define WOOTINGANALOGREADER_API __declspec(dllimport)   
#endif

#include "wooting-scan-codes.h"

typedef void(*void_cb)(void);

typedef struct wooting_full_buffer {
	unsigned char scan_code;
	unsigned char analog_value;
} wooting_full_buffer;

/** @brief Check if keyboard connected.

This function offers a quick check if the keyboard is connected. This doesn't open the keyboard or influences reading.

It is recommended to poll this function at the start of your application before starting reading.

@ingroup API

@returns
This function returns 0 on success and -1 on error.
*/
WOOTINGANALOGREADER_API int wooting_kbd_connected(void);

/** @brief Set callback for when a keyboard disconnect.

The callback will be called when a Wooting keyboard disconnects. Right now this will only trigger after a failed read.

@ingroup API

@returns
None.
*/
WOOTINGANALOGREADER_API void wooting_set_disconnected_cb(void_cb cb);

/** @brief Get the analog value of a single key.

This function returns an analog value of a single key. A SCAN_CODES enumaration is used as argument. These can be found
in ScanCodes.h or on the Wooting developer portal. Scan codes are used to prevent ambiguity between keyboard layouts.

It is not necesarry to initialize the keyboard before reading, but if the keyboard is not connected this function will return 0.

@ingroup API
@param key Scan code of the key that will be read

@returns
This function returns the analog value of the key from 0 - 255
*/
WOOTINGANALOGREADER_API unsigned char wooting_read_analog(SCAN_CODES key);

/** @brief Get the full analog buffer.

This function can be used to get a buffer of all the keys that are pressed up to a maximum of 16 keys. This can be used for easier access
to the keys that are currently pressed.

It is not necesarry to initialize the keyboard before reading, but if the keyboard is not connected this function will return 0.

@ingroup API
@param data A buffer to put the read data into. Expects an array of wooting_full_buffer.
@param items Amount of items in the array of the data buffer

@returns
This function returns items written and -1 on error.
*/
WOOTINGANALOGREADER_API int wooting_read_full_buffer(wooting_full_buffer data[], unsigned int items);