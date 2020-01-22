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

#include "google/cloud/bigquery/internal/admin_connection_impl.h"
#include "google/cloud/bigquery/internal/bigquery_stub.h"
#include "google/cloud/bigquery/version.h"
#include "google/cloud/status.h"
#include <memory>

namespace google {
namespace cloud {
namespace bigquery {
inline namespace BIGQUERY_CLIENT_NS {
namespace internal {

using ::google::cloud::Status;

AdminConnectionImpl::AdminConnectionImpl(
    std::shared_ptr<BigQueryStub> bigquery_stub)
    : bigquery_stub_(bigquery_stub) {}

Status AdminConnectionImpl::CreateDataset(std::string const& project_id,
                                          std::string const& dataset_id) {
  return bigquery_stub_->CreateDataset(project_id, dataset_id);
}

std::shared_ptr<AdminConnectionImpl> MakeAdminConnection(
    std::shared_ptr<BigQueryStub> bigquery_stub) {
  return std::shared_ptr<AdminConnectionImpl>(
      new AdminConnectionImpl(std::move(bigquery_stub)));
}

}  // namespace internal
}  // namespace BIGQUERY_CLIENT_NS
}  // namespace bigquery
}  // namespace cloud
}  // namespace google
