class(
    a() { 1 }
) { this }

package class {
    factory() { class() }
}

c : class()
d : class.factory()