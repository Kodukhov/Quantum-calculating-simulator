struct qbit_ {
    comp s0, s1;
};

typedef struct qbit_ qbit;

qbit mkqbit (comp s0, comp s1) {
    qbit x;
    x.s0 = s0;
    x.s1 = s1;
    return x;
}

void print(qbit a) {
    print_c(a.s0);
    printf(" |0>\n");
    print_c(a.s1);
    printf(" |1>\n");
}
