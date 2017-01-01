object :# <resultType>(
	error :# (e#object)resultType {
		halt(e)
	}
)resultType

func1 :# (a : 0) {
	error("foo")
}

func1(1, error : error)