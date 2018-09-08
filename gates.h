qbit g_not(qbit a) {
    qbit c = {a.s1, a.s0};
    return c;
}

qbit g_y(qbit a) {
    comp i = {0, -1};
    qbit c;
    c.s0 = mul(i, a.s1);
    i.y = 1;
    c.s1 = mul(i, a.s0);
    return c;
}

qbit g_z(qbit a) {
    comp z = {0, 0};
    qbit c = {a.s0, sub(z, a.s1)};
    return c;
}


qbit g_h(qbit a) {
    qbit x;
    x.s0 = sum(a.s0, a.s1);
    x.s1 = sub(a.s0, a.s1);
    float y = 1 / sqrt(2);
    x.s0 = mulr(y, x.s0);
    x.s1 = mulr(y, x.s1);
    return x;
}

qbit gate (qbit a, int c) {
    qbit x;
    matr z;
    comp cc = {1, 0};
    z.el[0] = z.el[3] = cc;
    cc.x = 0;
    z.el[1] = z.el[2] = cc;
    switch (c) {
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
    default:
        break;

    }
    x.s0 = sum(mul(a.s0, z.el[0]), mul(a.s1, z.el[1]));
    x.s1 = sum(mul(a.s0, z.el[2]), mul(a.s1, z.el[3]));
    return x;
}
