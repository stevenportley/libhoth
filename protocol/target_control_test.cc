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

#include "target_control.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "test/libhoth_device_mock.h"

using ::testing::_;
using ::testing::DoAll;
using ::testing::Return;

TEST_F(LibHothTest, targetcontrol_test) {
  struct ec_response_target_control targetcontrol_exp = {
      .status = EC_TARGET_CONTROL_STATUS_ENABLED,
  };

  EXPECT_CALL(mock_, send(_,
                          UsesCommand(EC_CMD_BOARD_SPECIFIC_BASE +
                                      EC_PRV_CMD_HOTH_TARGET_CONTROL),
                          _))
      .WillOnce(Return(LIBHOTH_OK));

  EXPECT_CALL(mock_, receive)
      .WillOnce(DoAll(CopyResp(&targetcontrol_exp, sizeof(targetcontrol_exp)),
                      Return(LIBHOTH_OK)));

  struct ec_response_target_control targetcontrol;
  EXPECT_EQ(libhoth_target_control_perform_action(
                &hoth_dev_, EC_TARGET_CONTROL_I2C_MUX,
                EC_TARGET_CONTROL_ACTION_GET_STATUS, &targetcontrol),
            LIBHOTH_OK);

  EXPECT_EQ(targetcontrol.status, targetcontrol_exp.status);
}
