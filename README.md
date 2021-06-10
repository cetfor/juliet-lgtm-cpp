# What is this repo?

This repo contains a partial fork of the Juliet Test Suite for C/C++ v1.3 by NSA Center for Assured Software with a CodeQL/LGTM configuration file to enable CodeQL analysis. You can (and should) acquire the full source code which is a part of the NIST Software Assurance Reference Dataset (SARD) here: https://samate.nist.gov/SRD/testsuite.php

# What is Juliet?

It's a massive set of 64,099 C/C++ software vulnerabilities used primarily to test static analyzers.  Similar sets are avilable for C# and Java vulnerabilities if you're interested, but this repo only contains a portion of the C/C++ set.  The C/C++ set alone spans more than 100 unique CWEs each with numerous manifestations of a specific bug class.  If you're interested in learning about static analysis, Juliet is a great resource.

# Why is this repo here?

There's a really cool analysis framework called CodeQL, developed by Semmle (since acquired by GitHub) that I want to try on Juliet.  You can use CodeQL for free on open source repos on GitHub via lgtm.com, but Juliet isn't hosted on GitHub, so that's why this is here.  Oh, if you're wondering, lgtm means "looks good to me" and I have no idea why it's called that, but it sgtm (sounds good to me).

# What do you plan to do with this repo?

While I may continue to add test cases, my main goal is to create a `lgtm.yml` file to allow `lgtm` to build Juliet.  Since CodeQL needs to actually build C/C++ to collect data and populate a database, this step is unavoidable. Unfortunately, LGTM's default C/C++ build environment does not build Juliet, so I need to create a custom `lgtm.yml` file so LGTM can build it and create a database. 

# How do you normally compile Juliet?

It depends on what platforms you're compiling for.  In these initial tests I'll be building for Linux as individual files. Juliet supports building all test cases into a single massive binary or each test segment into smaller ("individuals") binaries. To do this on a fresh install of Ubuntu 20.04 you'd do this:

```
sudo apt-get install make gcc g++
python3 create_per_cwe_files.py
make individuals
```

It's that easy.  Note, that not all test cases are applicable to all platforms.  When running `python3 create_per_cwe_files.py`, you'll get messages like these:

```
[Wed Jun  9 19:33:10 2021] No Makefile created for CWE78_s06. All of the test cases are Windows-specific.
[Wed Jun  9 19:33:11 2021] No Makefile created for CWE78_s05. All of the test cases are Windows-specific.
[Wed Jun  9 19:33:13 2021] No Makefile created for CWE78_s09. All of the test cases are Windows-specific.
[Wed Jun  9 19:33:16 2021] No Makefile created for CWE78_s08. All of the test cases are Windows-specific.
[Wed Jun  9 19:33:17 2021] No Makefile created for CWE78_s07. All of the test cases are Windows-specific.
```

In other words, only s01-s04 are Linux-based, the rest are specific to Windows.  We can add Windows builds later as LGTM does support building for Windows, but I'm not worried about this right now.

# How do you compile Juliet for LGTM

By creating a custom `lgtm.yml` file and including it in this repo.  The two documents you'll want to check out are:
* [lgtm.yml configuration file](https://lgtm.com/help/lgtm/lgtm.yml-configuration-file)
* [cpp extraction](https://lgtm.com/help/lgtm/cpp-extraction)

