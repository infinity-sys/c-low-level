# Exercises

| Given in | Exercise | Solution |
|---|---|---|
| E01 | Predict `sizeof` of 6 types on x86-64 and arm64, then check | E02 (`episodes/E02/e01-solution/`) |
| E02 | Find which stage fails for `broken1.c`, `broken2.c`, `broken3.c` | E03 (`episodes/E03/README.md`) |
| E03 | Predict the section (`T`, `D`, `B`, `R`, `U`) of every name in `place.c`, then check with `gcc -c place.c && nm place.o` | E04 (`episodes/E04/README.md`) |
| E04 | Predict `p+3` for a `char*`, an `int*` and a struct pointer (`p3.c`), then check | E05 (`episodes/E05/README.md`) |
| E05 | Reorder the 6-field struct in `six.c` (40 bytes) to the minimum `sizeof`, check with `offsetof` and gdb `ptype /o` | E06 (`episodes/E06/README.md`) |
| E06 | Rewrite `is_power_of_two` in `pow2.c` without any loop, check the 7 test values, explain why 0 is special | E07 |
