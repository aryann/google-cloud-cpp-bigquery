// Copyright 2020 Google LLC
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

#ifndef GOOGLE_CLOUD_BIGQUERY_ADMIN_CLIENT_H_
#define GOOGLE_CLOUD_BIGQUERY_ADMIN_CLIENT_H_

#include "google/cloud/bigquery/admin_connection.h"
#include "google/cloud/bigquery/connection.h"
#include "google/cloud/bigquery/connection_options.h"
#include <memory>

namespace google {
namespace cloud {
namespace bigquery {
inline namespace BIGQUERY_CLIENT_NS {
class AdminClient {
 public:
  explicit AdminClient(std::shared_ptr<AdminConnection> conn) : conn_(std::move(conn)) {}

  AdminClient() = delete;

  // AdminClient is copyable and movable.
  AdminClient(AdminClient const&) = default;
  AdminClient& operator=(AdminClient const&) = default;
  AdminClient(AdminClient&&) = default;
  AdminClient& operator=(AdminClient&&) = default;

  friend bool operator==(AdminClient const& a, AdminClient const& b) {
    return a.conn_ == b.conn_;
  }

  friend bool operator!=(AdminClient const& a, AdminClient const& b) { return !(a == b); }

  Status CreateDataset(std::string const& project_id,
		       std::string const& dataset_id);

 private:
  std::shared_ptr<AdminConnection> conn_;
};

std::shared_ptr<AdminConnection> MakeAdminConnection(ConnectionOptions const& options);

}  // namespace BIGQUERY_CLIENT_NS
}  // namespace bigquery
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_BIGQUERY_ADMIN_CLIENT_H_
