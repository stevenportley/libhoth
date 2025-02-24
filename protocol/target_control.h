// Copyright 2025 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _LIBHOTH_PROTOCOL_TARGET_CONTROL_H_
#define _LIBHOTH_PROTOCOL_TARGET_CONTROL_H_

#include "transports/libhoth_device.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"

/* Control miscellaneous boolean functions on target */
#define EC_PRV_CMD_HOTH_TARGET_CONTROL 0x0047

/* Options and request struct for EC_PRV_CMD_HOTH_TARGET_CONTROL */
enum ec_target_control_action {
  // Returns the current enabled/disabled status of the given function.
  EC_TARGET_CONTROL_ACTION_GET_STATUS = 0,

  // Changes the status of the given function to "Disabled". Returns the
  // previous enabled/disabled status of the given function.
  EC_TARGET_CONTROL_ACTION_DISABLE = 1,

  // Changes the status of the given function to "Enabled". Returns the previous
  // enabled/disabled status of the given function.
  EC_TARGET_CONTROL_ACTION_ENABLE = 2,
};

enum ec_target_control_function {
  EC_TARGET_CONTROL_RESERVED0 = 0,
  EC_TARGET_CONTROL_RESERVED1 = 1,
  // Allow control over GPIO for I2C Mux select (if present)
  EC_TARGET_CONTROL_I2C_MUX = 2,
  // Allow control over GPIO for Generic Mux select (if present)
  EC_TARGET_CONTROL_GENERIC_MUX = 3,
  // Allow checking whether external USB host is connected to system in which
  // RoT is present
  EC_TARGET_DETECT_EXTERNAL_USB_HOST_PRESENCE = 4,
  EC_TARGET_CONTROL_FUNCTION_MAX,
};

enum ec_target_control_status {
  EC_TARGET_CONTROL_STATUS_UNKNOWN = 0,
  EC_TARGET_CONTROL_STATUS_DISABLED = 1,
  EC_TARGET_CONTROL_STATUS_ENABLED = 2,

  // Recommended to be used for `EC_TARGET_DETECT_EXTERNAL_USB_HOST_PRESENCE`
  EC_TARGET_EXTERNAL_USB_HOST_NOT_PRESENT = EC_TARGET_CONTROL_STATUS_DISABLED,
  EC_TARGET_EXTERNAL_USB_HOST_PRESENT = EC_TARGET_CONTROL_STATUS_ENABLED,
};

struct ec_request_target_control {
  uint16_t function;  // must be ec_target_control_function
  uint16_t action;    // must be ec_target_control_action
  uint8_t args[];     // function+action specific args. Unused right now
} __attribute__((packed, aligned(4)));

struct ec_response_target_control {
  // If the action changes the target control status, returns the status prior
  // to the change requested by the host command.
  //
  // Must be ec_target_control_status
  uint16_t status;
} __attribute__((packed, aligned(4)));

int libhoth_target_control_perform_action(
    struct libhoth_device* dev, enum ec_target_control_function function,
    enum ec_target_control_action action,
    struct ec_response_target_control* response);

#ifdef __cplusplus
}
#endif

#endif
