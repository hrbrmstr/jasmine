<!-- README.md is generated from README.Rmd. Please edit that file -->
`jasmine` is a simple JSON parser

The following functions are implemented:

The following data sets are included:

### News

-   Version 0.1.0.9000 released

### Installation

``` r
devtools::install_github("hrbrmstr/jasmine")
```

### Usage

``` r
library(jasmine)

# current verison
packageVersion("jasmine")
#> [1] '0.1.0.9000'

get_keys('{ "dave" : "me", "henry" : 4, "steve" : [ "a", "b", "c" ]}')
#> [1] "dave"  "henry" "steve"
```

### Test Results

``` r
library(jasmine)
library(testthat)

date()
#> [1] "Mon Apr  4 23:12:54 2016"

test_dir("tests/")
#> testthat results ========================================================================================================
#> OK: 0 SKIPPED: 0 FAILED: 0
```

### Code of Conduct

Please note that this project is released with a [Contributor Code of Conduct](CONDUCT.md). By participating in this project you agree to abide by its terms.
