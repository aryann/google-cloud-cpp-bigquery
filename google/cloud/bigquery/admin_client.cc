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

#include "google/cloud/bigquery/admin_client.h"
#include "google/cloud/bigquery/admin_connection.h"
#include "google/cloud/bigquery/connection_options.h"
#include "google/cloud/bigquery/internal/admin_connection_impl.h"
#include "google/cloud/bigquery/internal/bigquery_stub.h"
#include "google/cloud/bigquery/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace bigquery {
inline namespace BIGQUERY_CLIENT_NS {
using ::google::cloud::Status;

	 Status AdminClient::CreateDataset(std::string const& project_id, std::string const& dataset_id) {
	   return {};
	 }

std::shared_ptr<AdminConnection> MakeAdminConnection(ConnectionOptions const& options) {
  std::shared_ptr<internal::BigQueryStub> stub =
      internal::MakeDefaultBigQueryStub(options);
  return internal::MakeAdminConnection(std::move(stub));
}

}  // namespace BIGQUERY_CLIENT_NS
}  // namespace bigquery
}  // namespace cloud
}  // namespace google
