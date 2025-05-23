// Copyright 2023 Google LLC
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

#ifndef _LIBHOTH_LIBHOTH_HOTH_H_
#define _LIBHOTH_LIBHOTH_HOTH_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct hoth_host_response {
  uint8_t struct_version;
  uint8_t checksum;
  uint16_t result;
  uint16_t data_len;
  uint16_t reserved;
} __attribute__((packed));

#ifdef __cplusplus
}
#endif

#endif  // _LIBHOTH_LIBHOTH_HOTH_H_
