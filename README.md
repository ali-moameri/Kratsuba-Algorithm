# Kratsuba Algorithm
Kratsuba algorithm implementation using C++17 for large multiplications.

## How it works?

To multiply `a` and `b` with `n` digits we can do:

`10n · (a·c) + 10n/2 · (a·d + b·c) + b·d`

## How to run the example?

You can use bazel:
<div>
<pre><code> bazel run :kratsuba_example
</code></pre>
</div>

or g++:
<div>
<pre><code> g++ kratsuba_example.cc -o ./a.out && ./a.out
</code></pre>
</div>


## How to run tests?

You can use bazel:
<div>
<pre><code> bazel test test:test_kratsuba
</code></pre>
</div>