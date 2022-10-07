cc_library(
    name = "kratsuba",
    hdrs = [
        "kratsuba.cc",
    ],
    copts = [
        "-std=c++17",
    ],
    visibility = ["//visibility:public"]
)

cc_binary(
    name = "kratsuba_example",
    srcs = ["kratsuba_example.cc"],
        deps = [
        ":kratsuba",
    ],
)