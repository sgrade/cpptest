# logmon README

## About

HTTP log monitoring console program. 

Reads a CSV-encoded HTTP access log from standard input in the format in sample_csv.txt. If the format is different, the program will crush. No special handlers for format checking were developed to keep logmon simple. 

For every 10 seconds of log lines, logmon displays stats about the traffic during those 10s. 

Whenever total traffic for the past 2 minutes exceeds a certain number on average, logmon prints an alert.

Whenever the total traffic drops again below that value on average for the past 2 minutes, logmon prints another message that the alert is recovered.

## Design

logmon follows [twelve-factor app](https://12factor.net/logs) recommendations for logs. It considers input logs as a stream and writes its event stream, unbuffered, to stdout. 

logmon can be easily modified to read from any stream, e.g. file. This is done in the alert tester (testing.cpp).

ProcessLog method of an existing logmon object can be called several times. The subsequent calls will continue working on the existing data (will not clear the previous batch of data). This is intentional. This is used in the alert tester (testing.cpp) to test alert logic. This can also be used to allow logmon (in the future) to work with rotated logs. 

For efficiency, logmon only keeps data to for the current windows: 
- stats: hits per section for 10 seconds + empirical delay (max 10 seconds). The delay is to deal with out-of-order log entries.
- alerting: count of requests for 120 seconds 

Variable types (e.g. int, long, etc.) are chosen to balance between (memory) efficiency and risk of overflow. Efficiency is preferred, where it seems reasonable. 

## How to run
### Usage
```
logmon [THRESHOLD] [no-stats] < input_data.txt
```

### Default parameters 
Default alert threshold is 10 requests per second on average for the last 2 minutes (120 seconds). 

Stats is printed for every 10 seconds of logs. 

### Examples

```
./logmon < sample_csv.txt
```

#### Custom threshold for alert
```
./logmon 12 < sample_csv.txt
```

#### Suppress 10-sec statistics (show only alerts)
```
./logmon no-stats < sample_csv.txt
```

#### Custom threshold for alert and suppress 10-sec statistics
```
./logmon 12 no-stats < sample_csv.txt
```

#### Getting help
```
./logmon -h
./logmon --help
./logmon help
```

## How to test alerts

Input parameters and test logic is embedded in tester. To test, run the precompiled tester.

```
./tester
```

## Build from source and test

### Build with CMake

```
mkdir build
cd build
cmake ..
make
```

### Test with CTest

Build with CMake. Then

```
cd build
cp ../alert_test* ./
ctest
```

Check Testing directory for details

## C++ version

C++ 20

```
cpp --version
cpp (Debian 10.2.1-6) 10.2.1 20210110
```

## Tested on

```
uname -a
Linux 42c9a83e9bc9 5.10.104-linuxkit #1 SMP Thu Mar 17 17:08:06 UTC 2022 x86_64 GNU/Linux
```

```
lsb_release -a
No LSB modules are available.
Distributor ID: Debian
Description:    Debian GNU/Linux 11 (bullseye)
Release:        11
```
