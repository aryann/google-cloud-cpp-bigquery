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

#ifndef BIGQUERY_INTERNAL_CONNECTION_H_
#define BIGQUERY_INTERNAL_CONNECTION_H_

#include <memory>

#include "google/cloud/bigquery/connection.h"
#include "google/cloud/bigquery/internal/bigquerystorage_stub.h"
#include "google/cloud/bigquery/version.h"
#include "google/cloud/status_or.h"

namespace bigquery {
inline namespace BIGQUERY_CLIENT_NS {
namespace internal {

// An implementation of the Connection interface that sents requests
// to a read stub. This class acts as the point of entry for all
// client operations. This class should never contain
// transport-related logic (e.g., any gRPC-specific code).
class ConnectionImpl : public Connection {
 public:
  google::cloud::StatusOr<std::string> CreateSession(
      std::string parent_project_id, std::string table) override;

 private:
  friend std::shared_ptr<ConnectionImpl> MakeConnection(
      std::shared_ptr<BigQueryStorageStub> read_stub);
  ConnectionImpl(std::shared_ptr<BigQueryStorageStub> read_stub);

  std::shared_ptr<BigQueryStorageStub> read_stub_;
};

std::shared_ptr<ConnectionImpl> MakeConnection(
    std::shared_ptr<BigQueryStorageStub> read_stub);

}  // namespace internal
}  // namespace BIGQUERY_CLIENT_NS
}  // namespace bigquery

#endif  // BIGQUERY_INTERNAL_CONNECTION_H_