start : clock()

str := ""
for i : 0 to 50000000 {
	f64_sqrt(i as f64)
	f64_pow(i as f64, 2.56)
	j : i * 745
	s1 : i.asString()
	s2 : s1 + " kaka pipi"
	s3 : s2.toUpperCase()
	if i % 300 == 0 {
		str = ""
	} else {
		str = (str + i.asString(16))
	}
}

end : clock()
debug.writeLine("timetocalc(msec): " + ((end - start) as f64 * 1000.0 / clocks_per_sec as f64).asString())