#include <cstdlib>
#include <utility>
#include <iostream>
#include <folly/Format.h>
#include <folly/futures/Future.h>
#include <folly/executors/ThreadedExecutor.h>
#include <folly/FBString.h>

static void print(const folly::fbstring& value) {
    const auto formatted = folly::format("Callback Future: {}", value);
    std::cout << formatted << std::endl;
}

int main() {
    folly::ThreadedExecutor executor;
    folly::Promise<folly::fbstring> promise;
    folly::Future<folly::fbstring> future = promise.getSemiFuture().via(&executor);
    folly::Future<folly::Unit> unit = std::move(future).thenValue(print);
    promise.setValue("Hello World!");
    std::move(unit).get();
    return EXIT_SUCCESS;
}
