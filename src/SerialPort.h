/*
 * SerialPort.h
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#if !defined(SerialPort_h)
#define SerialPort_h

#include "CommPort.h"

#include <stddef.h>

#if defined(ARDUINO_SAM_ZERO)
#define Serport SerialUSB
//String brd = "SAM_ZERO";
#elif defined(ARDUINO_SAMD_MKR1000)
#define Serport Serial
//String brd = "SAMD_MKR1000";
#else
#define Serport Serial
//String brd = "OTHER";
#endif

class SerialPort : public CommPort {
public:
  SerialPort();

  // Waits for the serial port to become ready.
  bool Connect();

  // Reads a byte from the communications device. Returns the character
  // read or -1 if no character was available.
  virtual int ReadByte();

  // Writes a block of data to the communications device.
  virtual void Write(const void *data, size_t len);
};

#endif // SerialPort_h

