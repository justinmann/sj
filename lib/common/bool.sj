bool_toString(val : 'bool) {
	if val {
		"true"
	} else {
		"false"
	}
}

bool_compare(l : 'bool, r : 'bool) {
	if l == r {
		0
	} else if !l {
		-1
	} else {
		1
	}
}

bool_hash(val : 'bool)'u32 {
	val as u32
}

bool_isEqual(l : 'bool, r : 'bool)'bool {
	l == r
}

string_toBool(text : 'string)'bool {
	if text == "true" {
		true
	} else {
		false
	}
}