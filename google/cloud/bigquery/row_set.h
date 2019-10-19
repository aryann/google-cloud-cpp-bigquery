// Copyright 2019 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef GOOGLE_CLOUD_BIGQUERY_ROW_SET_H_
#define GOOGLE_CLOUD_BIGQUERY_ROW_SET_H_

#include "google/cloud/bigquery/connection.h"
#include "google/cloud/bigquery/connection_options.h"
#include "google/cloud/bigquery/read_result.h"
#include "google/cloud/bigquery/read_stream.h"
#include "google/cloud/bigquery/row.h"
#include "google/cloud/bigquery/version.h"
#include "google/cloud/status_or.h"
#include <memory>

namespace google {
namespace cloud {
namespace bigquery {
inline namespace BIGQUERY_CLIENT_NS {
template <typename RowType>
class RowSet {
 public:
  using value_type = StatusOr<RowType>;
  class iterator {
   public:
    using iterator_category = std::input_iterator_tag;
    using value_type = RowSet::value_type;
    using difference_type = std::ptrdiff_t;
    using pointer = value_type*;
    using reference = value_type&;

    reference operator*() { return curr_; }
    pointer operator->() { return &curr_; }

    iterator& operator++() { return *this; }

    iterator operator++(int) { return {}; }

    friend bool operator==(iterator const&, iterator const&) { return {}; }

    friend bool operator!=(iterator const& a, iterator const& b) {
      return !(a == b);
    }

   private:
    StatusOr<RowType> curr_;
  };

  iterator begin() { return {}; }

  iterator end() { return {}; }
};

}  // namespace BIGQUERY_CLIENT_NS
}  // namespace bigquery
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_BIGQUERY_ROW_SET_H_
