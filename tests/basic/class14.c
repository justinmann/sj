typedef struct {
    int m;
} sjs_class;

int sjf_class(sjs_class* _this);
int sjf_inner(sjs_class* _parent);

int sjf_class(sjs_class* _this) {
    int m;
    m = 1;
    return sjf_inner((_parent));
}

int sjf_inner(sjs_class* _parent) {
    return m;
}

int main() {
    sjs_class sjd_temp1;
    sjs_class* sjv_temp1;
    sjv_temp1 = &sjd_temp1;
    sjf_class(sjv_temp1);
    return 0;
}
