qbit2 change(qbit2 prev, matr16 gate) {
    qbit2 res;
    int i, j;
    for (i = 0; i < 4; ++i) {
        comp t = {0, 0};
        for (j = 0; j < 4; ++j) {
            t = sum(t, mul(prev.s[j], gate.el[4 * i + j]));
        }
        res.s[i] = t;
    }
    return res;
}

qbit2 cnot1 (qbit2 prev) {
    matr16 g;
    int i;
    for (i = 0; i < 16; ++i) {
        g.el[i].x = 0;
        g.el[i].y = 0;
    }
    g.el[0].x = 1;
    g.el[5].x = 1;
    g.el[11].x = 1;
    g.el[14].x = 1;
    qbit2 res = change(prev, g);
    return res;
}

qbit2 cnot2 (qbit2 prev) {
    matr16 g;
    int i;
    for (i = 0; i < 16; ++i) {
        g.el[i].x = 0;
        g.el[i].y = 0;
    }
    g.el[0].x = 1;
    g.el[7].x = 1;
    g.el[10].x = 1;
    g.el[13].x = 1;
    qbit2 res = change(prev, g);
    return res;
}

qbit2 gate2 (qbit2 prev, int c1, int c2)
{
    qbit2 res;
    matr z, z1;
    matr16 m;
    comp cc = {1, 0};
    z.el[0] = z.el[3] = cc;
    z1.el[0] = z1.el[3] = cc;
    cc.x = 0;
    z.el[1] = z.el[2] = cc;
    z1.el[1] = z1.el[2] = cc;
    //printm(z1);
    switch (c1) {
    case 1:
        z = mkmatrx();
        break;
    case 2:
        z = mkmatry();
        break;
    case 3:
        z = mkmatrz();
        break;
    case 4:
        z = mkmatradam();
        break;
    case 5:
        return cnot1(prev);
    case 6:
        return cnot2(prev);
    default:
        break;
    }
    switch (c2) {
    case 1:
        z1 = mkmatrx();
        m = tmul(z, z1);
        break;
    case 2:
        z1 = mkmatry();
        m = tmul(z, z1);
        break;
    case 3:
        z1 = mkmatrz();
        m = tmul(z, z1);
        break;
    case 4:
        z1 = mkmatradam();
        m = tmul(z, z1);
    default:
        m = tmul(z, z1);
        break;
    }
    //printmatr(m);
    res = change(prev, m);
    return res;
}
