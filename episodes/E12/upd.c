void upd(int *a, int *b, int *x) {
    *a += *x;
    *b += *x;
}

void upd_r(int *restrict a, int *restrict b, int *restrict x) {
    *a += *x;
    *b += *x;
}
