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

#ifndef GOOGLE_CLOUD_BIGQUERY_TESTING_MOCK_BIGQUERY_STUB_H_
#define GOOGLE_CLOUD_BIGQUERY_TESTING_MOCK_BIGQUERY_STUB_H_

#include "google/cloud/bigquery/internal/bigquery_stub.h"
#include "google/cloud/bigquery/version.h"
#include "google/cloud/status.h"
#include <gmock/gmock.h>

namespace google {
namespace cloud {
namespace bigquery_testing {
inline namespace BIGQUERY_CLIENT_NS {
class MockBigueryStub : public google::cloud::bigquery::internal::BigQueryStub {
 public:
  MOCK_METHOD2(CreateDataset, Status(std::string const& project_id,
                                     std::string const& dataset_id));
};

}  // namespace BIGQUERY_CLIENT_NS
}  // namespace bigquery_testing
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_BIGQUERY_TESTING_MOCK_BIGQUERY_STUB_H_
