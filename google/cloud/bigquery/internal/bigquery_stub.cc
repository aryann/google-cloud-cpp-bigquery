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

#include "google/cloud/bigquery/internal/bigquery_stub.h"
#include "google/cloud/bigquery/connection_options.h"
#include "google/cloud/bigquery/version.h"
#include "google/cloud/status.h"

namespace google {
namespace cloud {
namespace bigquery {
inline namespace BIGQUERY_CLIENT_NS {
namespace internal {

namespace {

using ::google::cloud::Status;
using ::google::cloud::StatusCode;

class DefaultBigQueryStub : public BigQueryStub {
 public:
  explicit DefaultBigQueryStub() {}

  Status CreateDataset(std::string const& project_id,
                       std::string const& dataset_id) override;
};

}  // namespace

Status DefaultBigQueryStub::CreateDataset(std::string const& /*project_id*/,
                                          std::string const& /*dataset_id*/) {
  return Status(StatusCode::kUnimplemented,
                "This function is not yet implemented.");
}

std::shared_ptr<BigQueryStub> MakeDefaultBigQueryStub(
    ConnectionOptions const& /*options*/) {
  return std::make_shared<DefaultBigQueryStub>();
}

}  // namespace internal
}  // namespace BIGQUERY_CLIENT_NS
}  // namespace bigquery
}  // namespace cloud
}  // namespace google
