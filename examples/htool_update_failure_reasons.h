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

#ifndef THIRD_PARTY_LIBHOTH_LIBHOTH_EXAMPLES_HTOOL_UPDATE_FAILURE_REASONS_H_
#define THIRD_PARTY_LIBHOTH_LIBHOTH_EXAMPLES_HTOOL_UPDATE_FAILURE_REASONS_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum firmware_update_failure_reason {
  FIRMWARE_UPDATE_SUCCESS = 0,  // HOTH_SUCCESS
  FIRMWARE_UPDATE_NO_HEADER_FOUND = 1,
  FIRMWARE_UPDATE_INVALID_HEADER_SIZE = 2,
  FIRMWARE_UPDATE_INVALID_DESCRIPTOR = 3,
  FIRMWARE_UPDATE_DELIVERY_MECHANISM_MISMATCH = 4,
  FIRMWARE_UPDATE_INVALID_REGION = 5,
  FIRMWARE_UPDATE_VERIFY_BAD_HEADER = 6,
  FIRMWARE_UPDATE_VERIFY_HASH_IMAGE_FAILED = 7,
  FIRMWARE_UPDATE_VERIFY_HASH_FUSE_MAP_FAILED = 8,
  FIRMWARE_UPDATE_VERIFY_HASH_INFO_MAP_FAILED = 9,
  FIRMWARE_UPDATE_VERIFY_SIGNATURE_FAILED = 10,
  FIRMWARE_UPDATE_HASH_IMAGE_FIPS_FAILED = 11,
  FIRMWARE_UPDATE_VERIFY_FIPS_FAILED = 12,
  FIRMWARE_UPDATE_EXTERNAL_AB_HEADER_MISMATCH = 13,
  FIRMWARE_UPDATE_VERSIONS_EQUAL = 14,
  FIRMWARE_UPDATE_FIRST_VERSION_NEWER = 15,
  FIRMWARE_UPDATE_MAUV_UPDATE_NOT_ALLOWED = 16,
  FIRMWARE_UPDATE_EVEN_ODD_ROLLBACK_NOT_ALLOWED = 17,
  FIRMWARE_UPDATE_EVEN_ODD_ROLLBACK_PAYLOAD_TOO_OLD = 18,
  FIRMWARE_UPDATE_MIRROR_VERIFY_FAILED = 19,
  FIRMWARE_UPDATE_MIRROR_RW_FAILED = 20,
  FIRMWARE_UPDATE_MIRROR_RO_FAILED = 21,
  FIRMWARE_UPDATE_VERSION_MATCHES_DENYLIST = 22,
  FIRMWARE_UPDATE_INVALID_DESCRIPTOR_VERSION = 23,
  FIRMWARE_UPDATE_INVALID_RW_KEY_TRANSITION = 24,
  FIRMWARE_UPDATE_ERROR_MAX = 25,
};

// List of common failure codes for payload update.
enum payload_update_failure_reason {
  PAYLOAD_UPDATE_SUCCESS = 0,
  PAYLOAD_UPDATE_VALIDATE_RUNTIME_FAILURE = 1,
  PAYLOAD_UPDATE_VALIDATE_UNSUPPORTED_DESCRIPTOR = 2,
  PAYLOAD_UPDATE_VALIDATE_INVALID_DESCRIPTOR = 3,
  PAYLOAD_UPDATE_VALIDATE_INVALID_IMAGE_FAMILY = 4,
  PAYLOAD_UPDATE_VALIDATE_IMAGE_TYPE_DISALLOWED = 5,
  PAYLOAD_UPDATE_VALIDATE_DENYLISTED_VERSION = 6,
  PAYLOAD_UPDATE_VALIDATE_UNTRUSTED_KEY = 7,
  PAYLOAD_UPDATE_VALIDATE_INVALID_SIGNATURE = 8,
  PAYLOAD_UPDATE_VALIDATE_INVALID_HASH = 9,
  PAYLOAD_UPDATE_VALIDATE_PENDING = 10,
  PAYLOAD_UPDATE_VALIDATE_INVALID_SESSION_ID = 11,
  PAYLOAD_UPDATE_VALIDATE_FINGERPRINT_NOT_FOUND = 12,
  PAYLOAD_UPDATE_VALIDATE_UNSUPPORTED_FINGERPRINT_HASH_TYPE = 13,
  PAYLOAD_UPDATE_VALIDATE_MISSING_BOOT_HASH = 14,
  PAYLOAD_UPDATE_VALIDATE_UNEXPECTED_SKIP_BOOT_VALIDATION_REGION = 15,
  PAYLOAD_UPDATE_VALIDATE_MULTIPLE_DESCRIPTORS_FOUND = 16,
  PAYLOAD_UPDATE_VALIDATE_RESERVED_8 = 17,
  PAYLOAD_UPDATE_VALIDATE_RESERVED_9 = 18,
  PAYLOAD_UPDATE_VALIDATE_RESERVED_10 = 19,
  PAYLOAD_UPDATE_VALIDATE_RESERVED_11 = 20,
  PAYLOAD_UPDATE_ERASE_FAILED = 21,
  PAYLOAD_UPDATE_WRITE_FAILED = 22,
  PAYLOAD_UPDATE_READ_FAILED = 23,
  PAYLOAD_UPDATE_INVALID_PARAMS = 24,
  PAYLOAD_UPDATE_INVALID_STAGING_OFFSET = 25,
  PAYLOAD_UPDATE_INVALID_STAGING_SIZE = 26,
  PAYLOAD_UPDATE_FILTER_CALLBACK_FAILED = 27,
  PAYLOAD_UPDATE_ABORT_PENDING_UPDATE_FAILED = 28,
  PAYLOAD_UPDATE_BAD_PACKET_HEADER = 29,
  PAYLOAD_UPDATE_FPGA_UPDATE_HEADER_FAILED = 30,
  PAYLOAD_UPDATE_REGIONS_NOT_COMPATIBLE_FOR_MIGRATION = 31,
  PAYLOAD_UPDATE_MAUV_DOES_NOT_ALLOW_UPDATE = 32,
  PAYLOAD_UPDATE_STAGING_AREA_INVALID = 33,
  PAYLOAD_UPDATE_SET_ACTIVE_HALF_FAILED = 34,
  PAYLOAD_UPDATE_CALLBACK_FAILED = 35,
  PAYLOAD_UPDATE_SET_PENDING_MIGRATION_FAILED = 36,
  PAYLOAD_UPDATE_CONFIRM_INVALID_TIMEOUT = 37,
  PAYLOAD_UPDATE_CONFIRM_NOT_ENABLED = 38,
  PAYLOAD_UPDATE_CONFIRM_NO_UPDATE_PAYLOAD = 39,
  PAYLOAD_UPDATE_CONFIRM_NO_PENDING_PAYLOAD = 40,
  PAYLOAD_UPDATE_CONFIRM_GNVRAM_ERROR = 41,
  PAYLOAD_UPDATE_CONFIRM_REVERT_PAYLOAD = 42,
  PAYLOAD_UPDATE_CONFIRM_NOT_SUPPORTED = 43,
  PAYLOAD_UPDATE_GNVRAM_READ_ERROR = 44,
  PAYLOAD_UPDATE_GNVRAM_WRITE_ERROR = 45,
  PAYLOAD_UPDATE_ERROR_MAX = 46,
};

#ifdef __cplusplus
}
#endif

#endif  // THIRD_PARTY_LIBHOTH_LIBHOTH_EXAMPLES_HTOOL_UPDATE_FAILURE_REASONS_H_
