u32_maxValue : 4294967295u

i32_maxValue : -1i - 2147483647i
i32_minValue : 2147483647i

i32_max(a : 'i32, b : 'i32)'i32 {
    if a < b { b } else { a }
}

i32_min(a : 'i32, b : 'i32)'i32 {
    if a < b { a } else { b }
}

i32_random()'i32 {
    x := 0
    --c--
    sjv_x = rand();
    --c--
    x
}

i32_asString(val : 'i32, base : 10) {
    count := 0
    data := nullptr
    --c--
    sjv_data = (int*)malloc(sizeof(int) + sizeof(char) * 256) + 1;
    int* refcount = (int*)sjv_data - 1;
    *refcount = 1;

    char *tmp = (char*)sjv_data + 128;
    char *tp = (char*)sjv_data + 128;
    int i;
    unsigned v;

    int sign = (base == 10 && val < 0);    
    if (sign)
        v = -val;
    else
        v = (unsigned)val;

    while (v || tp == tmp)
    {
        i = v % base;
        v /= base; // v/=base uses less CPU clocks than v=v/base does
        if (i < 10)
          *tp++ = i + '0';
        else
          *tp++ = i + 'a' - 10;
    }

    int len = tp - tmp;

    char* sp = (char*)sjv_data;
    if (sign) 
    {
        *sp++ = '-';
        len++;
    }

    while (tp > tmp)
        *sp++ = *--tp;

    sjv_count = len;
    --c--
    string(count := count, data := array!char(dataSize := 256, count := count, data := data))
}

i32_compare(l : 'i32, r : 'i32) {
    if l == r {
        0
    } else if l < r {
        -1
    } else {
        1
    }
}

i32_hash(val : 'i32)'u32 {
    val as u32
}

i32_isEqual(l : 'i32, r : 'i32)'bool {
    l == r
}

string_asI32(text : 'string)'i32 {
    x := 0
    --c--
    char* e;
    int v = (int)strtol((char*)text->data.data, &e, 10);
    
    if (*e != '\0') {
        sjv_x = 0;
    }
    else {
        sjv_x = v;
    }
    --c--
    x
}

