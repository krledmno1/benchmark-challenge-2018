## timescales

`timescales` is a benchmark generator for Metric Temporal Logic (MTL) monitoring tools originally developed for the tool [reelay](https://github.com/doganulus/reelay). It generates a past MTL formula (in the standard YAML format) and an input trace (in the standard CSV format) that satisfies the formula at every time points. A set of predefined properties and challenges is available through the interface. Please see the help below.

The purpose of these benchmarks is to measure the performance and scalability of MTL monitoring with respect to large timing bounds in the specification over some typical and extreme properties. Ideally, the performance of real-time monitoring tools should be robust against changes in the base time unit since different (parts of) systems use different time scales up to orders of magnitude. This fact leads to large timing bounds in specifications that we want to check their performance in monitoring.

## use

The package `timescales` includes a Makefile to demonstrate the generation of benchmarks. The command `make small` generates a benchmark suite of supported properties with small timing bounds over short traces. On the other hand, the command `make large` generates three benchmarks for each property with increasingly larger time bounds over traces with a length of 1 million. The large suite has a size of 400MB and is not included in the distribution. The customization for the benchmark generation can be done easily using the underlying benchmark generator `reelay-benchgen`.

## help

The Python script `reelay-benchgen` is the benchmark generator of `timescales`. The full interface of the benchmark generator is as follows:

    usage: reelay_benchgen [-h] [-d N] [-l N] [-u N] [--min-recur N]
                           [--max-recur N] [--name STRING] [--limit-stutter N]
                           [--failing-end] [--output-dir DIR]
                           property
     
    reelay-benchgen is a benchmark generator for metric temporal logic properties
     
    positional arguments:
      property            Supported properties are below:
                              absence_after_q                   UBOUND
                              absence_before_r                  UBOUND
                              absence_between_q_and_r    LBOUND UBOUND
     
                              always_after_q                    UBOUND
                              always_before_r                   UBOUND
                              always_between_q_and_r     LBOUND UBOUND
     
                              recurrence_globally               UBOUND
                              recurrence_between_q_and_r        UBOUND MIN_RECUR MAX_RECUR
     
                              response_globally          LBOUND UBOUND
                              response_between_q_and_r   LBOUND UBOUND MIN_RECUR MAX_RECUR
     
                              challenge_pandq            LBOUND UBOUND
                              challenge_delay            LBOUND UBOUND
     
    optional arguments:
      -h, --help          show this help message and exit
      -d N, --duration N  define the approximate duration for the trace
      -l N, --lbound N    define the lower bound for the property if available for the property
      -u N, --ubound N    define the upper bound for the property if available for the property
      --min-recur N       define the minimum number of recurrence in the trace if available for the property
      --max-recur N       define the maximum number of recurrence in the trace if available for the property
      --name STRING       define the name of property (default: MySpec)
      --limit-stutter N   define the maximum amount of stuttering in the trace (default: 0 -- No limit)
      --failing-end       append a sequence to the trace to makes the spec fail (default: True)
      --output-dir DIR    use existing DIR as the directory to write output files in