struct qbit2_ {
    comp s[4];
};

typedef struct qbit2_ qbit2;

qbit2 mkqbit2 (qbit f, qbit s) {
    qbit2 r;
    r.s[0] = mul(f.s0, s.s0);
    r.s[1] = mul(f.s0, s.s1);
    r.s[2] = mul(f.s1, s.s0);
    r.s[3] = mul(f.s1, s.s1);
    return r;
}

void print2 (qbit2 a) {
    print_c(a.s[0]);
    printf(" |00>\n");
    print_c(a.s[1]);
    printf(" |01>\n");
    print_c(a.s[2]);
    printf(" |10>\n");
    print_c(a.s[3]);
    printf(" |11>\n");
}
