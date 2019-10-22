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

#include "google/cloud/bigquery/client.h"
#include "google/cloud/bigquery/connection.h"
#include "google/cloud/bigquery/connection_options.h"
#include "google/cloud/bigquery/internal/connection_impl.h"
#include "google/cloud/bigquery/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace bigquery {
inline namespace BIGQUERY_CLIENT_NS {
using ::google::cloud::StatusOr;

ReadResult<Row> Client::Read(std::string /*parent_project_id*/,
                             std::string /*table*/,
                             std::vector<std::string> /*columns*/) {
  return {};
}

ReadResult<Row> Client::Read(ReadStream const& /*read_stream*/) { return {}; }

StatusOr<std::vector<ReadStream>> Client::ParallelRead(
    std::string parent_project_id, std::string table,
    std::vector<std::string> columns) {
  return conn_->ParallelRead(std::move(parent_project_id), std::move(table),
                             std::move(columns));
}

std::shared_ptr<Connection> MakeConnection(ConnectionOptions const& options) {
  std::shared_ptr<internal::BigQueryStorageStub> stub =
      internal::MakeDefaultBigQueryStorageStub(options);
  return internal::MakeConnection(std::move(stub));
}

}  // namespace BIGQUERY_CLIENT_NS
}  // namespace bigquery
}  // namespace cloud
}  // namespace google
