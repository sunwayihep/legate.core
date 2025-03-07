/* Copyright 2021 NVIDIA Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#pragma once

#include "legion.h"

namespace legate {

template <typename VAL>
using Buffer = Legion::DeferredBuffer<VAL, 1>;

template <typename VAL>
Buffer<VAL> create_buffer(size_t size, Legion::Memory::Kind kind = Legion::Memory::Kind::NO_MEMKIND)
{
  using namespace Legion;
  if (Memory::Kind::NO_MEMKIND == kind) {
    auto proc = Processor::get_executing_processor();
    kind      = proc.kind() == Processor::Kind::TOC_PROC ? Memory::Kind::GPU_FB_MEM
                                                         : Memory::Kind::SYSTEM_MEM;
  }
  // We just avoid creating empty buffers, as they cause all sorts of headaches.
  auto hi = std::max<int64_t>(0, static_cast<int64_t>(size) - 1);
  Rect<1> bounds(0, hi);
  return Buffer<VAL>(bounds, kind);
}

}  // namespace legate
