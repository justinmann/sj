#iface()

@heap
class #iface(
	func() {
		store(parent as #iface)
		void
	}
) { this }

keep := empty'heap #iface
store(a : 'heap #iface?) {
	keep = a
}

c : heap class()
c.func()