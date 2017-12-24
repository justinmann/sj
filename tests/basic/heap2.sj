data(
    x : 0
) { this }

class(
    data : data()
    get() { copy data }
) { this }

c : class()
d : c.get()