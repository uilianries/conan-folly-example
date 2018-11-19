#include <cstdlib>
#include <utility>
#include <iostream>
#include <folly/Format.h>
#include <folly/futures/Future.h>
#include <folly/executors/ThreadedExecutor.h>
#include <folly/FBString.h>

static void print_uri(const folly::fbstring& value) {
    const auto authority = folly::format("Callback Future: {}", value);
    std::cout << authority << std::endl;
}

int main() {
    folly::ThreadedExecutor executor;
    folly::Promise<std::string> promise;
    folly::Future<std::string> future = promise.getSemiFuture().via(&executor);
    folly::Future<folly::Unit> unit = std::move(future).thenValue(print_uri);
    promise.setValue("Hello World!");
    std::move(unit).get();
    return EXIT_SUCCESS;
}
