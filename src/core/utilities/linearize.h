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

size_t linearize(const Legion::DomainPoint& lo,
                 const Legion::DomainPoint& hi,
                 const Legion::DomainPoint& point);

Legion::DomainPoint delinearize(const Legion::DomainPoint& lo,
                                const Legion::DomainPoint& hi,
                                size_t idx);

}  // namespace legate
