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

int main(int argc, char* argv[]) {
  bigquery::ConnectionOptions options;
  bigquery::Client client(bigquery::MakeConnection(options));
  google::cloud::StatusOr<std::string> res = client.CreateSession(
      "aryann-bigquery", "bigquery-public-data:samples.shakespeare");

  if (res.ok()) {
    std::cout << "Session name: " << res.value() << "\n";
    return EXIT_SUCCESS;
  } else {
    std::cerr << "Session creation failed with error: " << res.status() << "\n";
    return EXIT_FAILURE;
  }
}