# Test matrix

A test is marked passed only when the workflow or target test actually ran and its evidence is recorded.

| ID | Test | Current status | Acceptance evidence |
|---|---|---|---|
| B-001 | Static scaffold assertions | PASS — GitHub Actions | Successful `make check` step for commit `fd0c48d9e7f6868d4c42e57c068148d0e298f94d` |
| B-002 | Host C compilation and bootstrap execution | PASS — GitHub Actions | Successful `make check` step for the same commit |
| B-003 | Portable core unit tests | PASS — GitHub Actions | Successful `make check` step for the same commit |
| B-004 | Xenon compiler availability | Not verified | Tool path, version and target output |
| B-005 | Xenon ELF format and machine target | Not built | Inspect the actual output file |
| B-006 | Xbox 360 startup | Not tested | Device/environment, launch result and log |
| B-007 | Controller input | Not implemented | Input test results |
| B-008 | Graphics output | Not implemented | Frame capture or visible test result |
| B-009 | Audio output | Not implemented | Playback test and diagnostic log |
| B-010 | XEX packaging | Not implemented | Validated XEX metadata and target test |
| B-011 | God of War III gameplay | Not implemented | Authorized game integration and repeatable test evidence |

Host CI validates the portable bootstrap and generic modules only; it does not establish Xenon ABI compatibility or game functionality.
