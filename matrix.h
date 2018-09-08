struct matrix_ {
    comp el[4];
};

typedef struct matrix_ matr;

struct matrix16_ {
    comp el[16];
};

typedef struct matrix16_ matr16;

matr16 tmul(matr f, matr s) {
    matr16 res;
    res.el[0] = mul(f.el[0], s.el[0]);
    res.el[1] = mul(f.el[0], s.el[1]);
    res.el[2] = mul(f.el[1], s.el[0]);
    res.el[3] = mul(f.el[1], s.el[1]);
    res.el[4] = mul(f.el[0], s.el[2]);
    res.el[5] = mul(f.el[0], s.el[3]);
    res.el[6] = mul(f.el[1], s.el[2]);
    res.el[7] = mul(f.el[1], s.el[3]);
    res.el[8] = mul(f.el[2], s.el[0]);
    res.el[9] = mul(f.el[2], s.el[1]);
    res.el[10] = mul(f.el[3], s.el[0]);
    res.el[11] = mul(f.el[3], s.el[1]);
    res.el[12] = mul(f.el[2], s.el[2]);
    res.el[13] = mul(f.el[2], s.el[3]);
    res.el[14] = mul(f.el[3], s.el[2]);
    res.el[15] = mul(f.el[3], s.el[3]);
    return res;
}

void printmatr(matr16 m) {
    int i, j;
    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            printf("%.0f ", (m.el[4 * i + j].x));
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
}

void printm(matr m){
    int i;
    for (i = 0; i < 4; ++i) {
        printf("%.0f ", m.el[i].x);
        if (i == 1)
            printf("\n");
    }
    printf("\n\n");
}

matr mkmatradam () {
    matr a;
    comp x = {1 / sqrt(2), 0};
    a.el[0] = x;
    a.el[1] = x;
    a.el[2] = x;
    x.x = -x.x;
    a.el[3] = x;
    return a;
}


matr mkmatrx () {
    matr a;
    comp x = {0, 0};
    a.el[0] = x;
    a.el[3] = x;
    x.x = 1;
    a.el[1] = x;
    a.el[2] = x;
    return a;
}

matr mkmatry () {
    matr a;
    comp x = {0, 0};
    a.el[0] = x;
    a.el[3] = x;
    x.y = -1;
    a.el[1] = x;
    a.el[2] = x;
    return a;
}

matr mkmatrz () {
    matr a;
    comp x = {0, 0};
    a.el[1] = x;
    a.el[2] = x;
    x.x = 1;
    a.el[0] = x;
    x.x = -1;
    a.el[3] = x;
    return a;
}
