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

#ifndef BIGQUERY_INTERNAL_ADMIN_CONNECTION_H_
#define BIGQUERY_INTERNAL_ADMIN_CONNECTION_H_

#include "google/cloud/bigquery/admin_connection.h"
#include "google/cloud/bigquery/internal/bigquery_stub.h"
#include "google/cloud/bigquery/version.h"
#include "google/cloud/status.h"
#include <memory>

namespace google {
namespace cloud {
namespace bigquery {
inline namespace BIGQUERY_CLIENT_NS {
namespace internal {

class AdminConnectionImpl : public AdminConnection {
 public:
  Status CreateDataset(std::string const& project_id,
                       std::string const& dataset_id) override;

 private:
  friend std::shared_ptr<AdminConnectionImpl> MakeAdminConnection(
      std::shared_ptr<BigQueryStub> bigquery_stub);
  AdminConnectionImpl(std::shared_ptr<BigQueryStub> bigquery_stub);

  std::shared_ptr<BigQueryStub> bigquery_stub_;
};

std::shared_ptr<AdminConnectionImpl> MakeAdminConnection(
    std::shared_ptr<BigQueryStub> bigquery_stub);

}  // namespace internal
}  // namespace BIGQUERY_CLIENT_NS
}  // namespace bigquery
}  // namespace cloud
}  // namespace google

#endif  // BIGQUERY_INTERNAL_ADMIN_CONNECTION_H_
