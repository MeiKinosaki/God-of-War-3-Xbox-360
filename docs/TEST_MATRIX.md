# Test matrix

No result should be marked PASS until the test is actually run and its evidence retained.

| ID | Test | Current status | Acceptance evidence |
|---|---|---|---|
| B-001 | Static scaffold assertions | Not run in this record | Command output from `python3 tests/check_source.py` |
| B-002 | Host C compilation | Not run in this record | Compiler output and successful process exit |
| B-003 | Xenon compiler availability | Not verified | Tool path and version output |
| B-004 | ELF format and machine target | Not verified | Object inspection output |
| B-005 | Xbox 360 startup | Not tested | Device/environment, launch result and log |
| B-006 | Controller input | Not implemented | Input test results |
| B-007 | Graphics output | Not implemented | Frame capture or visible test result |
| B-008 | Audio output | Not implemented | Playback test and diagnostic log |
| B-009 | XEX packaging | Not implemented | Validated XEX metadata and target test |
| B-010 | God of War III gameplay | Not implemented | Authorized game integration and repeatable test evidence |

Host tests only validate the portable bootstrap; they do not establish target compatibility.
