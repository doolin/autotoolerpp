# Autotooler++

Template for a small c++ project built with GNU autotools.

## Usage

This tiny project template has two main uses:

1. Starting point for a major, top level application.
2. Branch for a c++ implementation within another project.

In the first case, `git clone` as usual, or fork into your
own top level repo.

In the second case, clone this repo into a desired subdirectory,
then remove the `.git` directory from the clone, then add
the c++ directory to your main project. One use case for this
is when implementing an algorithm in c++ (or c) for wrapping
with script driver.

## TODO

* Add in c++ spec
  * port changes back from tfidf
  * clean up the compiler warnings on unused params.
  * create examples for every case, use disambiguator for examples.
