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

#ifndef GOOGLE_CLOUD_BIGQUERY_READ_STREAM_H_
#define GOOGLE_CLOUD_BIGQUERY_READ_STREAM_H_

#include "google/cloud/bigquery/version.h"
#include "google/cloud/status_or.h"

namespace google {
namespace cloud {
namespace bigquery {
inline namespace BIGQUERY_CLIENT_NS {
class ReadStream {};

// Serializes an instance of `ReadStream` for transmission to another process.
StatusOr<std::string> SerializeReadStream(ReadStream const& /*read_stream*/);

// Deserializes the provided string to a `ReadStream`, if able.
StatusOr<ReadStream> DeserializeReadStream(
    std::string /*serialized_read_stream*/);

}  // namespace BIGQUERY_CLIENT_NS
}  // namespace bigquery
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_BIGQUERY_READ_STREAM_H_