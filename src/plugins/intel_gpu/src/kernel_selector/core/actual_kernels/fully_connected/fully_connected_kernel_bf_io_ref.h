﻿// Copyright (C) 2018-2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include <vector>

#include "fully_connected_kernel_base.h"

namespace kernel_selector {

class FullyConnected_bf_io_ref : public FullyConnectedKernelBase {
public:
    using Parent = FullyConnectedKernelBase;
    FullyConnected_bf_io_ref() : FullyConnectedKernelBase("fully_connected_gpu_bf_io_ref") {}

    KernelsData GetKernelsData(const Params& params, const optional_params& options) const override;
    KernelsPriority GetKernelsPriority(const Params& params, const optional_params& options) const override;
    ParamsKey GetSupportedKey() const override;

protected:
    std::vector<FusedOpType> GetSupportedFusedOps() const override {
        return { FusedOpType::ACTIVATION };
    }
    JitConstants GetJitConstants(const fully_connected_params& params, const DispatchData& dispatchData) const override;
};
}  // namespace kernel_selector