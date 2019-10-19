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

#ifndef BIGQUERY_CONNECTION_H_
#define BIGQUERY_CONNECTION_H_

#include "google/cloud/bigquery/read_stream.h"
#include "google/cloud/bigquery/row.h"
#include "google/cloud/bigquery/version.h"
#include "google/cloud/status_or.h"
#include <vector>

namespace google {
namespace cloud {
namespace bigquery {
inline namespace BIGQUERY_CLIENT_NS {
class Connection {
 public:
  virtual ~Connection() = default;

  virtual StatusOr<std::vector<ReadStream>> ParallelRead(
      std::string parent_project_id, std::string table,
      std::vector<std::string> columns = {}) = 0;
};

}  // namespace BIGQUERY_CLIENT_NS
}  // namespace bigquery
}  // namespace cloud
}  // namespace google

#endif  // BIGQUERY_CONNECTION_H_
