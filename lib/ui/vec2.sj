vec2(
    x : 0.0f
    y : 0.0f

    asString() {
        x.asString() + ", " + y.asString()
    }
) { this }

vec2_getRawSize() {
    --c--
    int x = sizeof(float) * 2;
    #return(i32, x);
    --c--
}

vec2_rawCopy(v : 'vec2, p := 'ptr) {
    --c--
    float* f = (float*)p;
    *f = v->x;
    f++;
    *f = v->y;
    f++;
    #return(ptr, (void*)f);
    --c--
}