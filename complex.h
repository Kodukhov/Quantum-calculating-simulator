struct complex_ {
    float x, y;
};

typedef struct complex_ comp;

void print_c(comp a) {
    printf("(%.1f+i%.1f)", a.x, a.y);
}

comp sum(comp a, comp b) {
    comp c = {a.x + b.x, a.y + b.y};
    return c;
}

comp sub(comp a, comp b) {
    comp c = {a.x - b.x, a.y - b.y};
    return c;
}

comp mulr(float x, comp a) {
    comp c = {x * a.x, x * a.y};
    return c;
}

comp mul(comp a, comp b) {
    comp c = {a.x * b.x - a.y * b.y, a.y * b.x + a.x * b.y};
    return c;
}
