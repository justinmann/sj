typedef struct {
    int x;
    sjs_aa* b;
} sjs_a;

typedef struct {
    sjs_a* _parent;
} sjs_aa;

sjs_a* sjf_a(sjs_a* _this);
sjs_aa* sjf_aa(sjs_aa* _this);
int sjf_c(sjs_aa* _parent);

sjs_a* sjf_a(sjs_a* _this) {
    return _this;
}

sjs_aa* sjf_aa(sjs_aa* _this) {
    return _this;
}

int sjf_c(sjs_aa* _parent) {
    return x;
}

int main() {
    sjs_a* a;
    sjs_aa* d;
    sjs_aa sjd_temp1;
    sjs_a sjd_temp2;
    sjs_aa* sjv_temp1;
    sjs_a* sjv_temp2;
    sjv_temp1 = &sjd_temp1;
    sjv_temp2 = &sjd_temp2;
    sjv_temp2->x = 1;
    sjv_temp2->b = sjf_aa(sjv_temp1);
    a = sjf_a(sjv_temp2);
    a->bsjf_c((_parent));
    d = a->b;
    dsjf_c((_parent));
    return 0;
}
